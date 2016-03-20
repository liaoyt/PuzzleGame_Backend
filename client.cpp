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

int main()
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;

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

	char msg[1024];
	char buf[1024];

	printf("Test for MIL:\n");
	// genarate test msg
	protobufUtils::PGRequest request;
	request.set_requesttype("post");
	request.set_requestcode("0");
	printf("%s\n", "check request:");
	request.CheckInitialized();
	printf("%s\n", "request OK");
	request.SerializeToArray(msg, 1024);

	// send the msg to the server
	write(sockfd, msg, strlen(msg));
	len = read(sockfd, buf, 1024);
	protobufUtils::PGRequest backInfo;
	backInfo.ParseFromArray(buf, len);
	printf("%s\n", "check backInfo:");
	backInfo.CheckInitialized();
	printf("%s\n", "backInfo OK");

	if(backInfo.has_picture()){
		printf("%s\n", backInfo.picture().c_str());
	}

	
	close(sockfd);
	return 0;
}