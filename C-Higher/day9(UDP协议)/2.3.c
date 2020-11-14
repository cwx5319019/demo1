#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int main(void){
	//----------创建套接字------------      
	//int socket(int domain, int type, int protocol);
	int fd ;
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1){
		perror("create socket fail...");
		exit(-1);
	}
	printf("fd : %d\n",fd);
	//-----------连接----------------
	int on = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
	//int setsockopt(int sockfd, int level, int optname,const void *optval, socklen_t optlen);                   
	//int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
	struct sockaddr_in client;
	client.sin_family = AF_INET;
	client.sin_port = ntohs(9000);
	client.sin_addr.s_addr = inet_addr("192.168.0.111");
    int retval = connect(fd,(struct sockaddr*)&client,sizeof(struct sockaddr_in));            
	if(retval == -1){
		perror("connect fail...");
		goto out;
	}
	printf("connect：%d \n",retval);
	//-----------通信------------------
	char buf[100] = "";
	retval = read(fd,buf,100);
	if(retval == -1){
		perror("read fail...");
		goto out;
	}
	printf("%s\n",buf);
	memset(buf,0,100);
	while(1){
		printf("请输入向服务器发送的内容：");
		fflush(stdout);
		fgets(buf,100,stdin);
		retval = write(fd,buf,strlen(buf));
		if(strncmp(buf,"exit",4)==0)break;
		if(retval == -1){
			perror("write fail...");
			goto out;
		}
	}
	
out:
	close(fd);
	return 0;
}
