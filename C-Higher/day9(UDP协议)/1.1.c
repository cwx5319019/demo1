//一个TCP的客户端与TCP的服务器,服务器采用多进程并发结构,
//客户端可以一直给服务器发送数据,直到输入exit退出
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
	//int socket(int domain, int type, int protocol);
	//-----------创建套接字----------------
	int fd;
	fd = socket(AF_INET,SOCK_STREAM,0);
	printf("fd= %d\n",fd);
	
	//--------------绑定------------------
	int on = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
	//#include<netinet/in.h> 
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9000);
	server.sin_addr.s_addr = inet_addr("192.168.2.60");
	int retval = 0;
	retval = bind(fd,(struct sockaddr *)&server,sizeof(struct sockaddr_in));
	printf("bind = %d\n",retval);
	if(retval == -1){
		perror("bind error");
		goto out;
	}
	//------------------监听------------------------
	retval = listen(fd,10);
	printf("listen = %d\n",retval);
	if(retval == -1){
		perror("listen error");
		goto out;
	}
	
	//----------------接收客户端的链接------------------
	//int accept(int socket, struct sockaddr *restrict address,socklen_t *restrict address_len);
	//被restrict修饰，只有这个指针能指向目的作用域
	struct sockaddr_in client;
	socklen_t len = 0;
	int clientfd = 0;
	signal(SIGCHLD,signal_fun);
	while(1){
		printf("accept...\n");
		clientfd = accept(fd,(struct sockaddr *)&client,&len);
		printf("客户端fd = %d,IP = %s,PORT = %d\n",clientfd,inet_ntoa(client.sin_addr),ntohs(client.sin_port));
		if(clientfd == -1){
			perror("accept fail...");
			goto out;
		}
	
		//----------------与客户端通信---------------------
		char* str = "欢迎光临...";
		retval = write(clientfd,str,strlen(str));
		if(retval == -1){
			perror("write fail...");
			goto out;
		}
		pid_t pid = fork();
		char buf[100] = "";
		if(pid == 0){
			while(1){
				retval = read(clientfd,buf,100);
				if(retval == 0){
					break;
				}
				printf("从客户端%d读取到%d字节:%s\n",clientfd,strlen(buf),buf);
				if(retval == -1){
					perror("read fail...");
					goto out;
				} 
				memset(buf,0,100);
			}
		}
	}
	
	
out:
	close(fd);
	return 0;
}
















