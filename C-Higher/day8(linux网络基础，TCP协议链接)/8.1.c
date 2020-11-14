
//-------------------线程处理并发状态------------------

#include <sys/types.h>         
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void* do_server(void* arg){
	int retval;
	int clientfd = *((int*)arg);
	printf("%s,client = %d\n",__FUNCTION__,clientfd);
	char buf[100] = "";
	while(1){
		retval = read(clientfd,buf,100);
		printf("从%d号客户端读取到%d字节：%s\n",clientfd,retval-1,buf);
		memset(buf,0,100);
		if(retval == 0){
			printf("%d号客户端已断开...\n",clientfd);
			break;
		}
		//printf("请输入你要发给客户的信息：");
		//fflush(stdout);
		//fgets(buf,100,stdin);
		//if(strncmp(buf,"end",3)==0)break;
		//retval = write(clientfd,str,strlen(str));
		//printf("发送%d个字节到客户端...\n",retval);
	}
	close(clientfd);
	return NULL;
}

int main(void){
	//------------第一步：创建套接字-------------
	int fd; 
	fd = socket(AF_INET,SOCK_STREAM,0);
	printf("fd = %d\n",fd);
	int on = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
	//------------第二步：绑定------------------
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(9000); 
	server.sin_addr.s_addr = inet_addr("192.168.0.111");
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
	
	printf("listen的返回值 %d\n",ret);
	
	if(ret == -1){
		perror("listen failed..");
		goto out;
	}
	
	//---------第四步：accept()接收(接收客户端的链接)------------
	int clientfd;
	//用于保存客户端的IP地址和端口号
	struct sockaddr_in client;
	socklen_t len = 0;
	
	pthread_t thread[100];
	int client_no = 0;
	pthread_attr_t attr[100];
	
	while(1){
		printf("accept:");
		fflush(stdout);
		clientfd = accept(fd,(struct sockaddr*)&client,&len);
		printf("客户端fd = %d,IP = %s,PORT = %d 已经连接！\n",clientfd,inet_ntoa(client.sin_addr),ntohs(client.sin_port));
		if(clientfd == -1){
			perror("accept fail...");
			goto out;
		}
	
		//-------------------第五步：与客户端通信------------------
		char* str ="欢迎光临...";
		retval = write(clientfd,str,strlen(str));
		printf("发送%d字节到客户端...\n",retval);
		
		pthread_attr_init(&attr[client_no]);
		pthread_attr_setdetachstate(&attr[client_no],PTHREAD_CREATE_DETACHED);
		pthread_create(&thread[client_no],&attr[client_no],do_server,(void*)&clientfd);
		client_no++;
		
	}
	
out://标号
	printf("goto here...\n");
	close(fd);
	return 0;
}














