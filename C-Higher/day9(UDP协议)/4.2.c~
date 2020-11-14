
//----------------UDP协议---------------------

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
	
	//--------------服务器通信------------------
	int on = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9000);
	server.sin_addr.s_addr = inet_addr("192.168.2.60");

	//ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                      //const struct sockaddr *dest_addr, socklen_t addrlen);
	char buf[100] = "";
	while(1){
		printf("请输入要发送的数据：");
		fgets(buf,100,stdin);
		//类似write函数
		int retval = sendto(fd,buf,strlen(buf),0,(struct sockaddr*)&server,sizeof(struct sockaddr_in));
		if(strncmp(buf,"exit",4)==0){
			break;
		}
		printf("你发送了%d个字节\n",retval-1);
		memset(buf,0,100);
	}

	close(fd);
	return 0;
}
















