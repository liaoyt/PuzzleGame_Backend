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
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAXBUF 1024
#define MAXEPOLLSIZE 10000

#define MSGKEY 1024
struct msgstru
{
	long msgtype;
	char msgtext[2048];
};
int key;

using namespace std;

extern void connectMysql();
extern void signup(const string username, const string password, const string nickname);
extern void login(const string username, const string password);
extern void postScore(const string username, const string score);
extern void postPicture(const string username, const string pictureDate);
extern void getRank(const string score);
extern void getPicList();
extern void getExactPic(const string pictureName);
extern void closeConnect();
extern char* msg;

/* setnonblocking - 设置句柄为非阻塞方式 */
int setnonblocking(int sockfd) {
	if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK) == -1) {
		return -1;
	}
	return 0;
}

void MissingField() {
	protobufUtils::PGRequest error;
	error.set_errorinfo("Missing required field!");
	error.set_code("400");
	error.SerializeToArray(msg, MAXBUF);
}

void handle_massage(protobufUtils::PGRequest &request)
{
	memset(msg, 0, sizeof(char)*MAXBUF);

	printf("%s\n", request.code().c_str());

	if (strcmp(request.code().c_str(), "0") == 0) {		// 注册
		if (request.has_username() && request.has_password() && request.has_nickname())
			signup(request.username(), request.password(), request.nickname());
		else
			MissingField();
	} else if (strcmp(request.code().c_str(), "1") == 0) {		// 登陆
		if (request.has_username() && request.has_password())
			login(request.username(), request.password());
		else
			MissingField();
	} else if (strcmp(request.code().c_str(), "2") == 0) {		// 上传得分
		if (request.has_score() && request.has_username())
			postScore(request.username(), request.score());
		else
			MissingField();
	}  else if (strcmp(request.code().c_str(), "3") == 0) {		// 上传照片
		if (request.has_username() && request.has_picturedate())
			postPicture(request.username(), request.picturedate());
		else
			MissingField();
	} else if (strcmp(request.code().c_str(), "4") == 0) { 		// 排名
		if (request.has_score())
			getRank(request.score());
		else
			MissingField();
	} else if (strcmp(request.code().c_str(), "5") == 0) {		// 自定义照片列表
		getPicList();
	} else if (strcmp(request.code().c_str(), "6") == 0) {		// 选取特定照片
		if (request.pictures_size() != 0)
			getExactPic(request.pictures(0));
		else
			MissingField();
	} else {							// 请求码错误
		protobufUtils::PGRequest error;
		error.set_code("444");
		error.set_errorinfo("No such type of requestion!");
		error.SerializeToArray(msg, MAXBUF);
	}
}

/* handle_socket - 处理每个 socket 上的消息收发*/
int handle_socket(int new_fd) {
	char buf[MAXBUF];
	int len;

	memset(buf, 0, sizeof(char)*MAXBUF);

	// 开始处理每个新连接上的数据收发
	len = read(new_fd, buf, MAXBUF);
	if (len > 0) {
		printf("%d接收消息成功:'%s',共%d个字节的数据\n",
		       new_fd, buf, len);
		protobufUtils::PGRequest request;
		request.ParseFromArray(buf, len);
		request.CheckInitialized();

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

void handle_image(int new_fd) {
	// setnonblocking(new_fd);
	char picbuf[102400];
	string picture = "";
	int len = 0;
	bool firstread = true;
	while (true) {
		len = read(new_fd, picbuf, 102400);
		printf("%d\n", len);
		if (len > 0) {
			picture += string(picbuf, len);
			if (firstread) {
				protobufUtils::PGImage test;
				test.ParseFromString(picture);
				if(test.opt() == "get"){
					break;
				} else {
					firstread = false;
					continue;
				}
			}
		} else {
			break;
		}
	}

	printf("%d接收消息成功:,共%d个字节的数据\n",
	       new_fd, (int)picture.length());

	protobufUtils::PGImage image;
	image.ParseFromString(picture);
	image.CheckInitialized();

	if (image.opt() == "post") {
		string filename(image.username() + image.date() + ".bmp");
		fstream ifs(filename.c_str(), ios::binary | ios::out);
		ifs.write(image.image().data(), image.image().length());
		ifs.close();
	} else if (image.opt() == "get") {
		string picNam(image.username() + image.date() + ".bmp");
		fstream ifs(picNam.c_str(), ios::binary | ios::in);
		char picbuf[102400];
		picture.clear();
		while (!ifs.eof()) {
			ifs.read(picbuf, 102400);
			int count = ifs.gcount();
			picture += string(picbuf, count);
		}

		protobufUtils::PGImage image;
		image.set_opt("post");
		image.set_username(picNam);
		image.set_date(picNam);
		image.set_image(picture.data(), picture.length());
		string sendmsg;
		image.SerializeToString(&sendmsg);
		write(new_fd, sendmsg.data(), sendmsg.length());
	}

	close(new_fd);
	return;
}

int imageProc() {

	int listener, new_fd;
	socklen_t len;
	struct sockaddr_in my_addr, their_addr;
	unsigned int myport, lisnum;
	struct rlimit rt;
	myport = 9734 + 3;
	lisnum = 1;
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
		printf("开启图片服务成功!\n");
	}

	while (true) {
		new_fd = accept(listener, (struct sockaddr *) &their_addr, &len);
		if (new_fd > 0) {
			if (fork() > 0) {
				close(new_fd);
			} else {
				handle_image(new_fd);
				return 0;
			}
		}
	}

	close(listener);
	return 0;
}

int messageProc() {

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
		printf("开启消息服务成功!\n");
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

int main() {

	pid_t pid;
	// 分叉进程
	pid = fork();

	// 判断是否执行成功
	if (-1 == pid)
	{
		printf("进程创建失败\n");
	} else if (pid == 0)
	{
		// 子进程中执行此代码
		imageProc();
	} else {
		// 父进程执行代码
		messageProc();
	}

	return 0;
}