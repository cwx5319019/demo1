//----------------------服务器------------------------------
//-------------------第三步：listen()监听-------------------------
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
/*
       #include <sys/types.h>          
       #include <sys/socket.h>
       int listen(int sockfd, int backlog);
       		
       //int backlog 设置监听队列长度
*/	

	//返回值，监听成功返回 0 否则返回-1
	int ret;
	ret = listen(fd,10);
	printf("listen的返回值 = %d\n",ret);
	if(ret == -1){
		perror("listen failed..");
		goto out;
	}
	
out://标号
	printf("goto here...\n");
	close(fd);
	return 0;
}














