//----------------------服务器-------------------------------
//----------------------bind()绑定--------------------------------
//大小端字节序  大端 低地址放 （0x01020304）16进制高位数据例如 01
//			  小端 相反
//网络字节序即大小端字节序

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
	//------------第二步：绑定-------------
/*
       #include <sys/types.h>        
       #include <sys/socket.h>
       int bind(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen);

*/
	//定义struct sockaddr_in 类型结构体
	struct sockaddr_in server;
	//定义结构体成员sin_family
	server.sin_family = AF_INET;
	//定义结构体成员sin_port
	//把端口号转化为网络字节 host short
	server.sin_port = htons(8990);
	//设置IP地址 
	server.sin_addr.s_addr = inet_addr("192.168.2.66");
	//返回值非常重要 绑定成功返回 0 否则返回-1
	int retval;
	retval = bind(fd,(struct sockaddr*)&server,(socklen_t)sizeof(struct sockaddr_in));
	printf("bind返回值 = %d\n",retval);
	if(retval == -1){
		perror("bind failed...");
		close(fd);//注意：申请不成功退出前关闭fd
		exit(1);
	}
	
	close(fd);
	return 0;
}














