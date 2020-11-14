
/*

find /usr/include/* -name socket.h
//常用 找文件

cat mqtt-example.c | grep -r HAL_Free -n
//grep找字符串

*/


//----------------------服务器-------------------------------
//--------------------socket()套接字-----------------------------
//把一台电脑ip和端口号套接在一起，另一台也ip和端口号也套接在一起，把两台电脑进行连接。

/*
   #include <sys/types.h>         
   #include <sys/socket.h>
   int socket(int domain, int type, int protocol);
*/

#include <sys/types.h>         
#include <sys/socket.h>
#include <stdio.h>
int main(void){
	int fd; 
	fd = socket(AF_INET,SOCK_STREAM,0);
	//AF_INET        IPV4   
	//SOCK_STREAM    TCP
	printf("fd = %d\n",fd);
	close(fd);//关闭套接字
	return 0;
}














