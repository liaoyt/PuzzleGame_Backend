#include "protobuf/protobufUtils.pb.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fstream>

#define MAXBUF 1024
#define MAXEPOLLSIZE 10000

using namespace std;

extern void connectMysql();
extern void signup();
extern void login();
extern void postScore();
extern void postPicture();
extern void getRank();
extern void getPicList();
extern void getExactPic();
extern void closeConnect();
extern char* msg;

/* setnonblocking - 设置句柄为非阻塞方式 */
int setnonblocking(int sockfd) {
	if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK) == -1) {
		return -1;
	}
	return 0;
}

void handle_massage(protobufUtils::PGRequest &request)
{
	memset(msg, 0, sizeof(char)*MAXBUF);

	switch(request.code())
	{
		case 0:		// 注册
			signup();
			break;
		case 1:		// 登陆
			login();
			break;
		case 2:		// 上传得分
			postScore();
			break;
		case 3:		// 上传照片
			postPicture();
			break;
		case 4:		// 排名
			getRank();
			break;
		case 5:		// 自定义照片列表
			getPicList();
			break;
		case 6:		// 选取特定照片
			getExactPic();
			break;
		default:
			request.set_errorinfo("No such type of requestion!");
			request.SerializeToArray(msg, MAXBUF);
			break;
	}
}

/* handle_socket - 处理每个 socket 上的消息收发*/
int handle_socket(int new_fd) {
	char buf[MAXBUF];
	int len;
	bzero(buf, MAXBUF);

	/* 开始处理每个新连接上的数据收发 */
	len = read(new_fd, buf, sizeof(buf));
	if (len > 0) {
		printf("%d接收消息成功:'%s',共%d个字节的数据\n",
		       new_fd, buf, len);
		protobufUtils::PGRequest request;
		request.ParseFromArray(buf, strlen(buf));
		printf("%d\n", request.code());

		handle_massage(request);
		printf("%s\n", msg);
		// printf("%d\n", strlen(msg));
		write(new_fd, msg, strlen(msg));
	}
	else {
		if (len < 0)
			printf ("消息接收失败!错误代码是%d,错误信息是'%s'\n", errno, strerror(errno));
		close(new_fd);
		return -1;
	}
	/* 处理每个新连接上的数据收发结束 */
	return len;
}

int main() {
	int listener, new_fd, kdpfd, nfds, n, ret, curfds;
	socklen_t len;
	struct sockaddr_in my_addr, their_addr;
	unsigned int myport, lisnum;
	struct epoll_event ev;
	struct epoll_event events[MAXEPOLLSIZE];
	struct rlimit rt;
	myport = 9734;
	lisnum = 2;
	rt.rlim_max = rt.rlim_cur = MAXEPOLLSIZE;

	/* 设置每个进程允许打开的最大文件数 */
	if (setrlimit(RLIMIT_NOFILE, &rt) == -1) {
		perror("setrlimit");
		exit(1);
	}
	else {
		printf("设置系统资源参数成功!\n");
	}

	/* 开启 socket 监听 */
	if ((listener = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}
	else {
		printf("socket 创建成功!\n");
	}
	setnonblocking(listener);
	bzero(&my_addr, sizeof(my_addr));
	my_addr.sin_family = PF_INET;
	my_addr.sin_port = htons(myport);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(listener, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)) == -1) {
		perror("bind");
		exit(1);
	}
	else {
		printf("IP 地址和端口绑定成功\n");
	}
	if (listen(listener, lisnum) == -1) {
		perror("listen");
		exit(1);
	}
	else {
		printf("开启服务成功!\n");
	}

	/* 创建 epoll 句柄,把监听 socket 加入到 epoll 集合里 */
	kdpfd = epoll_create(MAXEPOLLSIZE);
	len = sizeof(struct sockaddr_in);
	ev.events = EPOLLIN | EPOLLET;
	ev.data.fd = listener;
	if (epoll_ctl(kdpfd, EPOLL_CTL_ADD, listener, &ev) < 0) {
		fprintf(stderr, "epoll set insertion error: fd=%d\n", listener);
		return -1;
	}
	else {
		printf("监听 socket 加入 epoll 成功!\n");
	}
	curfds = 1;

	// 连接数据库
	connectMysql();

	while (1) {
		nfds = epoll_wait(kdpfd, events, curfds, -1); /* 等待有事件发生 */
		if (nfds == -1) {
			perror("epoll_wait");
			break;
		}
		for (n = 0; n < nfds; ++n) {
			/* 处理所有事件 */
			if (events[n].data.fd == listener) {
				new_fd = accept(listener, (struct sockaddr *) &their_addr, &len);
				if (new_fd < 0) {
					perror("accept"); continue;
				}
				else {
					printf("有连接来自于: %s:%d, 分配的 socket 为:%d\n",
					       inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port), new_fd);
				}
				setnonblocking(new_fd);
				ev.events = EPOLLIN | EPOLLET;
				ev.data.fd = new_fd;
				if (epoll_ctl(kdpfd, EPOLL_CTL_ADD, new_fd, &ev) < 0) {
					fprintf(stderr, "把 socket '%d' 加入 epoll 失败!%s\n", new_fd, strerror(errno));
					return -1;
				}
				curfds++;
			}
			else {
				ret = handle_socket(events[n].data.fd);
				if (ret < 1 && errno != 11) {
					epoll_ctl(kdpfd, EPOLL_CTL_DEL, events[n].data.fd, &ev);
					curfds--;
				}
			}
		}
	}
	printf("%s\n", "exit");
	closeConnect();
	close(listener);
	return 0;
}