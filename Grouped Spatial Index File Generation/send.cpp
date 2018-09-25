#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#define NUM_MAX 1024
#define SERVER_PORT 9090
#define SERVER_IP1 "127.0.0.1"
#define SERVER_IP2 "192.168.1.10"
#define SERVER_IP3 "192.168.1.3"
#define SERVER_IP4 "192.168.1.5"
using namespace std;
string reqStr;


void send(string ip, string request) {
	struct sockaddr_in s_in;
	int s_fd;

	//memset((void *)&s_in,0,sizeof(s_in));

	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(SERVER_PORT);
	inet_pton(AF_INET, ip.c_str(), (void *)&s_in.sin_addr);

	s_fd = socket(AF_INET,SOCK_STREAM,0);

	connect(s_fd,(struct sockaddr *)&s_in,sizeof(s_in));



	write(s_fd, request.c_str(), request.size());

	close(s_fd);
}

int main()
{
    cout<<"Please input the target coordinates: ";
    reqStr = "45.01078800 -85.42365300";
    send(SERVER_IP1, reqStr);
	send(SERVER_IP2, reqStr);
	send(SERVER_IP3, reqStr);
	send(SERVER_IP4, reqStr);
}
