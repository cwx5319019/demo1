#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

void *thread_fun(void *arg)
{
	int clientfd = *(int*)arg;
	while(1){
		char buf[20] = "";
		fgets(buf,sizeof(buf),stdin);
		write(clientfd,buf,sizeof(buf));
		memset(buf,0,20);
		read(clientfd,buf,sizeof(buf));
		fputs(buf,stdout);
		memset(buf,0,20);
	}

	return NULL;
}


int main(int argv ,char** argc)
{
	//socket
	int sockfd =  socket(AF_INET,SOCK_STREAM, 0);
	if(sockfd == -1){
		printf("创建失败\n");
		return -1;
	}
	
	//bind
	int on = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
	struct sockaddr_in server;
	memset(&server,0,sizeof(struct sockaddr_in));
	server.sin_family = AF_INET;
	server.sin_port = htons(9999);//转化网络字节序（大端字节）
	server.sin_addr.s_addr = inet_addr("0.0.0.0");//

	int res = bind(sockfd, (struct sockaddr*) &server,sizeof(struct sockaddr_in));
	printf("sockfd:%d, %d,%s\n",sockfd,ntohs(server.sin_port),inet_ntoa(server.sin_addr));
	if(res == -1){
		perror("绑定失败\n");
		return -2;
	}

	//listen
	res = listen(sockfd, 10);
	if(res == -1){
		perror("侦听失败\n");
		return -3;
	}
	//accept
	//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	
	struct sockaddr_in client;
	socklen_t clientlen = 0 ;
	int clientfd = accept(sockfd,(struct sockaddr *)&client,&clientlen);
	if(clientfd == -1){
		perror("接收失败失败\n");
		return -4;
	}
	printf("%d 号客户已经连接，ID号:%s \n",clientfd,inet_ntoa(client.sin_addr));
	//read write
	
	char buf[20] = "欢迎光临\n";
	write(clientfd,buf,sizeof(buf));
	memset(buf,0,20);
	

	
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	//pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	pthread_create(&thread,&attr,thread_fun,(void*)&clientfd);

	
	pthread_join(thread, NULL);
	
	return 0;
}


















































