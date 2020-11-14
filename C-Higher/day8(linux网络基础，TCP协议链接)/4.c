//----------------------服务器-------------------------------
//---------第四步：accept()接收(接收客户端的链接)-----------
#include <sys/types.h>         
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
int main(void){
	//------------第一步：创建套接字-------------
	int fd; 
	fd = socket(AF_INET,SOCK_STREAM,0);
	printf("fd = %d\n",fd);
	//------------第二步：绑定------------------
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(8990); 
	server.sin_addr.s_addr = inet_addr("192.168.2.66");
	int retval;
	retval = bind(fd,(struct sockaddr*)&server,(socklen_t)sizeof(struct sockaddr_in));
	printf("bind返回值 = %d\n",retval);
	if(retval == -1){
		perror("bind failed...");
		//使用goto语句减少代码冗余 
		goto out;
	}
	//------------第三步：listen()监听------------------
	int ret;
	ret = listen(fd,10);
	printf("listen的返回值 = %d\n",ret);
	if(ret == -1){
		perror("listen failed..");
		goto out;
	}
	
	//---------第四步：accept()接收(接收客户端的链接)------------

/*
       #include <sys/types.h>          
       #include <sys/socket.h>

       int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
*/



	int clientfd;
	//用于保存客户端的IP地址和端口号
	struct sockaddr_in client;
	socklen_t len = 0;
	printf("accept:");
	clientfd = accept(fd,(struct sockaddr*)&client,&len);
	printf("客户端fd = %d,IP = %s,PORT = %d\n",clientfd,  
											  inet_ntoa(client.sin_addr),
											  ntohs(client.sin_port));
	if(clientfd == -1){
		perror("accept fail...");
		goto out;
	}
	
	
out://标号
	printf("goto here...\n");
	close(fd);
	return 0;
}














