#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include "protobuf/protobufUtils.pb.h"

using namespace std;

string str;
char msg[1024];
char buf[1024];

int sockfd;
int len;
int result;

void test0()
{
	memset(msg, 0, sizeof(char) * 1024);
	memset(buf, 0, sizeof(char) * 1024);

	printf("Test for signup:\n");
	// genarate test msg
	protobufUtils::PGRequest request;
	request.set_code("0");
	request.set_username("zaishiyici");
	request.set_password("nimabi");
	request.set_nickname("liaoyt3");

	request.CheckInitialized();
	printf("%s\n", "request OK");
	// request.SerializeToString(&str);
	request.SerializeToArray(msg, 1024);

	// send the msg to the server
	write(sockfd, msg, strlen(msg));
	len = read(sockfd, buf, 1024);

	// write(sockfd, str.c_str(), str.length());
	// len = read(sockfd, buf, 1024);

	protobufUtils::PGRequest backInfo;
	backInfo.ParseFromArray(buf, len);
	backInfo.CheckInitialized();
	printf("%s\n", "backInfo OK");

	if (backInfo.has_errorinfo()) {
		printf("%s\n", backInfo.errorinfo().c_str());
	}
}

void test1()
{
	memset(msg, 0, sizeof(char) * 1024);
	memset(buf, 0, sizeof(char) * 1024);

	printf("Test for login:\n");
	// genarate test msg
	protobufUtils::PGRequest request;
	request.set_code("1");
	request.set_username("liaoyt1");
	request.set_password("liaoyt2");

	request.CheckInitialized();
	printf("%s\n", "request OK");
	request.SerializeToArray(msg, 1024);

	// send the msg to the server
	write(sockfd, msg, strlen(msg));
	len = read(sockfd, buf, 1024);

	protobufUtils::PGRequest backInfo;
	backInfo.ParseFromArray(buf, len);
	backInfo.CheckInitialized();
	printf("%s\n", "backInfo OK");

	if (backInfo.has_errorinfo()) {
		printf("%s\n", backInfo.score().c_str());
		printf("%s\n", backInfo.errorinfo().c_str());
	}
}

void test2()
{
	memset(msg, 0, sizeof(char) * 1024);
	memset(buf, 0, sizeof(char) * 1024);

	printf("Test for postScore:\n");
	// genarate test msg
	protobufUtils::PGRequest request;
	request.set_code("2");
	request.set_username("liaoyt1");
	request.set_score("23333");

	request.CheckInitialized();
	printf("%s\n", "request OK");
	request.SerializeToArray(msg, 1024);

	// send the msg to the server
	write(sockfd, msg, strlen(msg));
	len = read(sockfd, buf, 1024);

	protobufUtils::PGRequest backInfo;
	backInfo.ParseFromArray(buf, len);
	backInfo.CheckInitialized();
	printf("%s\n", "backInfo OK");

	if (backInfo.has_errorinfo()) {
		printf("%s\n", backInfo.errorinfo().c_str());
	}
}

void test3()
{
	memset(msg, 0, sizeof(char) * 1024);
	memset(buf, 0, sizeof(char) * 1024);

	printf("Test for postPicture:\n");
	// genarate test msg
	protobufUtils::PGRequest request;
	request.set_code("3");
	request.set_username("lisi");
	request.set_picturedate("2000000");

	request.CheckInitialized();
	printf("%s\n", "request OK");
	request.SerializeToArray(msg, 1024);

	// send the msg to the server
	write(sockfd, msg, strlen(msg));


	// send a pic
	struct sockaddr_in address;
	/* Create a socket for the client. */
	int picsocket = socket(AF_INET, SOCK_STREAM, 0);

	/* Name the socket, as agreed with the server. */
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(9734 + 3);
	len = sizeof(address);

	/* Now connect our socket to the server's socket. */
	result = connect(picsocket, (struct sockaddr *)&address, len);
	if (result == -1) {
		perror("oops: picsocket");
		exit(1);
	}

	fstream ifs("bitmap/pic0.jpg", ios::in | ios::binary);
	char picbuf[102400];
	string picture = "";
	while (!ifs.eof()) {
		ifs.read(picbuf, 102400);
		int count = ifs.gcount();
		picture += string(picbuf, count);
	}

	protobufUtils::PGImage image;
	image.set_opt("post");
	image.set_username("lisi");
	image.set_date("2000000");
	image.set_image(picture.data(), picture.length());
	picture.clear();
	image.SerializeToString(&picture);
	write(picsocket, picture.data(), picture.length());
	printf("%d\n", (int)picture.length());
	// len = read(picsocket, buf, 1024);
	// buf[len] = '\0';
	// printf("%s\n", buf);
	close(picsocket);

	len = read(sockfd, buf, 1024);

	protobufUtils::PGRequest backInfo;
	backInfo.ParseFromArray(buf, len);
	backInfo.CheckInitialized();
	printf("%s\n", "backInfo OK");

	if (backInfo.has_errorinfo()) {
		printf("%s\n", backInfo.errorinfo().c_str());
	}
}


void test4()
{
	memset(msg, 0, sizeof(char) * 1024);
	memset(buf, 0, sizeof(char) * 1024);

	printf("Test for getRank:\n");
	// genarate test msg
	protobufUtils::PGRequest request;
	request.set_code("4");
	request.set_score("23333");

	request.CheckInitialized();
	printf("%s\n", "request OK");
	request.SerializeToArray(msg, 1024);

	// send the msg to the server
	write(sockfd, msg, strlen(msg));
	len = read(sockfd, buf, 1024);

	protobufUtils::PGRequest backInfo;
	backInfo.ParseFromArray(buf, len);
	backInfo.CheckInitialized();
	printf("%s\n", "backInfo OK");

	if (backInfo.has_errorinfo()) {
		printf("%s\n", backInfo.errorinfo().c_str());
		printf("%s\n", backInfo.rankinfo().myrank().c_str());
		printf("%s\n", backInfo.rankinfo().topscore(0).c_str());
	}
}

void test5()
{
	memset(msg, 0, sizeof(char) * 1024);
	memset(buf, 0, sizeof(char) * 1024);

	printf("Test for getPicList:\n");
	// genarate test msg
	protobufUtils::PGRequest request;
	request.set_code("5");

	request.CheckInitialized();
	printf("%s\n", "request OK");
	request.SerializeToArray(msg, 1024);

	// send the msg to the server
	write(sockfd, msg, strlen(msg));
	len = read(sockfd, buf, 1024);

	protobufUtils::PGRequest backInfo;
	backInfo.ParseFromArray(buf, len);
	backInfo.CheckInitialized();
	printf("%s\n", "backInfo OK");

	if (backInfo.has_errorinfo()) {
		printf("%s\n", backInfo.errorinfo().c_str());
		for (int i = 0; i < backInfo.pictures_size(); ++i)
		{
			printf("%s\n", backInfo.pictures(i).c_str());
		}
	}
}

void test6()
{
	memset(msg, 0, sizeof(char) * 1024);
	memset(buf, 0, sizeof(char) * 1024);

	printf("Test for getExactPic:\n");

	// send a pic
	struct sockaddr_in address;
	/* Create a socket for the client. */
	int picsocket = socket(AF_INET, SOCK_STREAM, 0);

	/* Name the socket, as agreed with the server. */
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(9734 + 3);
	len = sizeof(address);

	/* Now connect our socket to the server's socket. */
	result = connect(picsocket, (struct sockaddr *)&address, len);
	if (result == -1) {
		perror("oops: picsocket");
		exit(1);
	}

	string picture;
	protobufUtils::PGImage image;
	image.set_opt("get");
	image.set_username("lisi");
	image.set_date("2000000");
	image.set_image("none");
	image.SerializeToString(&picture);
	write(picsocket, picture.data(), picture.length());

	char picbuf[102400];
	int len;
	picture.clear();
	while (true) {
		len = read(picsocket, picbuf, 102400);
		if (len > 0)
			picture += string(picbuf, len);
		else
			break;
	}
	close(picsocket);

	image.Clear();
	image.ParseFromString(picture);
	image.CheckInitialized();

	fstream ofs("test.bmp", ios::out | ios::binary);
	ofs.write(image.image().data(), image.image().length());
	ofs.close();
}


int main()
{

	struct sockaddr_in address;


	/* Create a socket for the client. */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/* Name the socket, as agreed with the server. */
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(9734);
	len = sizeof(address);

	/* Now connect our socket to the server's socket. */
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if (result == -1) {
		perror("oops: client");
		exit(1);
	}

	test0();	// passed
	test1();	// passed
	test2();	// passed
	test3();	// passed
	test4();	// passed
	test5();	// passed
	test6();	// passed


	close(sockfd);
	return 0;
}