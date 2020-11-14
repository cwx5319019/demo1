//建立TCP服务器和客户端,客户端向服务器输入shell命令,服务器执行并返回结果

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
void* thread_fun(void* arg){
	int savefd = dup(1);
	while(1){
		char buf[100] = "";
		int retval = read((int)arg,buf,100);
		if(retval == 0)break;
		printf("接收%d号客户端%d字节：%s\n",(int)arg,strlen(buf)-1,buf);
		dup2((int)arg,1);
		dup2((int)arg,2);
		system(buf);
		dup2(savefd,1);
		if(strncmp(buf,"exit",4)==0){
			printf("%d号客户端已经退出！\n",(int)arg);
			close((int)arg);
			break;
		}
	}
	return NULL;
}
int main(void){
	//----------创建套接字------------      
	int fd ;
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1){
		perror("create socket fail...");
		exit(-1);
	}
	printf("fd : %d\n",fd);
	//-----------绑定----------------
	int on = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9000);
	server.sin_addr.s_addr = inet_addr("192.168.2.60");
    int retval = bind(fd,(struct sockaddr*)&server,sizeof(struct sockaddr_in));            
	if(retval == -1){
		perror("bind fail...");
		goto out;
	}
	printf("bind：%d \n",retval);
	//-----------监听-------------------
	retval = listen(fd,10);
	if(retval == -1){
		perror("listen fail...");
		goto out;
	}
	printf("listen : %d\n",retval);
	//-----------接收-------------------
	struct sockaddr_in addr;
	socklen_t len = 0;
	pthread_t thread[100];
	pthread_attr_t attr[100];
	int clen = 0;
	while(1){
		printf("accept...\n");
		int clientfd = accept(fd,(struct sockaddr*)&addr,&len);
		if(clientfd == -1){
			perror("accept fail...");
			goto out;
		}
		printf("客户端:%d IP:%s,PORT = %d 已经连接！\n",clientfd,inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
		//------------通信----------
		char *str = "欢迎光临..."; 
		retval = write(clientfd,str,strlen(str));
		if(retval == -1){
			perror("write fail...");
			goto out;
		}
		

		pthread_attr_init(&attr[clen]);
	   	pthread_attr_setdetachstate(&attr[clen],PTHREAD_CREATE_DETACHED);	
		pthread_create(&thread[clen],&attr[clen],thread_fun,(void*)clientfd);
		clen++;
	}

	

out:
	close(fd);
	return 0;
}





























