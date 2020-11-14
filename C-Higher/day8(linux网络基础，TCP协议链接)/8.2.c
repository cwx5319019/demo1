
//-------------------客户端通信------------------
#include <sys/types.h>         
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	//------------第一步：创建套接字-------------
	int fd; 
	fd = socket(AF_INET,SOCK_STREAM,0);
	printf("fd = %d\n",fd);
	int on = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
	//------------第二步：连接服务器------------------
	int retval = 0;
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(8989);
	server.sin_addr.s_addr = inet_addr("192.168.2.66");
	
	retval = connect(fd,(struct sockaddr*)&server,sizeof(struct sockaddr_in));
	printf("retval = %d\n",retval);
	if(retval ==-1){
		perror("connect failed...");
		goto out;
	}
	//------------第三步：与服务器通信------------------
	char buf[100] = "";
	retval = read(fd,buf,100);
	printf("从服务器读到%d字节:%s\n",retval,buf);
	memset(buf,0,100);
	while(1){
		
		printf("请输入你要发送的数据：");
		fflush(stdout);
		memset(buf,0,100);
		fgets(buf,100,stdin);
		retval = write(fd,buf,strlen(buf));
		printf("发送了%d字节到服务器...\n",retval-1);
		memset(buf,0,100);
		//retval = read(fd,buf,100);
		//printf("从服务器读取到%d字节：%s\n",retval-1,buf);
		if(strncmp(buf,"end",3)==0)break;
		
		
	}
	
out://标号
	printf("goto here...\n");
	close(fd);
	return 0;
}














