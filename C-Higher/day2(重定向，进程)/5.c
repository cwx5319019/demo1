#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(void){
	//dup2函数
	//int dup2(int oldfd，int newfd);
	int fd = 0;
	fd = open("5.txt",O_RDWR|O_CREAT,0666);
	int newfd ;
	printf("fd = %d\n",fd);
	newfd = dup2(fd,1);
	printf("newfd = %d\n",newfd);
	  
	write(newfd,"hello1\n",6);
	printf("hello2\n");
	puts("hello3");
	
	close(fd);	
	return 0;
}
