#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
void getstring(char* str,int len){
	fgets(str,len,stdin);
	int i = 0;
	for(;str[i] != 0;i++){
		if(str[i] == 10){
			str[i] = 0;
		}
	}
}

int main(void){

	//int socket(int domain, int type, int protocol);
	//-----------创建套接字----------------
	int fd;
	fd = socket(AF_INET,SOCK_STREAM,0);
	printf("fd= %d\n",fd);
	
	//------------连接服务器---------------
	int on = 1; 
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
	//int connect(int socket, const struct sockaddr *address,socklen_t address_len);

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9000);
	
	//in_addr_t inet_addr(const char *cp);
	server.sin_addr.s_addr = inet_addr("192.168.2.60");
	int retval = connect(fd,(struct sockaddr *)&server,sizeof(struct sockaddr_in));
	if(retval == -1){
		perror("connect fail...");
		goto out;
	}
	
	//---------------与服务器通信-----------------
	char buf[100] = "";
	retval = read(fd,buf,100);
	printf("读到%d个字节：%s\n",retval,buf);
	memset(buf,0,100);
	while(1){
		printf("请输入向服务器发送的内容：");
		fflush(stdout);
		getstring(buf,100);
		retval = write(fd,buf,strlen(buf));
		if(strncmp(buf,"exit",4)==0)break;
		if(retval == -1){
			perror("write fail...");
			goto out;
		}
		printf("发送%d个字节到服务器\n",strlen(buf));
		memset(buf,0,100);
	
	}
	
	
out:
	close(fd);
	return 0;
}	
	
	
	
	
	
