
//----------------UDP---------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include<signal.h>
#include<sys/wait.h>
void signal_fun(int sigo){
	wait(NULL);
	printf("已经回收\n");
}
int main(void){
	//-----------创建套接字----------------
	int fd;
	fd = socket(AF_INET,SOCK_DGRAM,0);//stream dgram
	printf("fd= %d\n",fd);
	
	//--------------绑定------------------
	int on = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9000);
	server.sin_addr.s_addr = inet_addr("192.168.2.60");
	int retval = 0;
	retval = bind(fd,(struct sockaddr *)&server,sizeof(struct sockaddr_in));
	printf("bind = %d\n",retval);
	if(retval == -1){
		perror("bind error");
		close(fd);
		return 0;
	}
	//----------------与客户端通信---------------------
//ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                     //struct sockaddr *src_addr, socklen_t *addrlen);
		char buf[100] = "";
		struct sockaddr_in clientaddr;
		socklen_t len = 0;
		while(1){
			puts("recieve:");
			//类似read函数
			retval = recvfrom(fd,buf,100,1,(struct sockaddr*)&clientaddr,&len);
			if(strncmp(buf,"exit",4)==0){
				printf("%d号客户端已退出！\n",ntohs(clientaddr.sin_port));
				break;
			}
			printf("从客户端(%s,%d)读取到%d字节\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port),retval-1);
			puts(buf);
			memset(buf,0,100);
		}
	
	

	close(fd);
	return 0;
}
















