#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(void){
	int fd;
	fd = open("./uuu",O_RDONLY);
	printf("fd = %d\n",fd);
	int size;
	char buf[20] = "";
	//while(1);
	size = read(fd,buf,20);
	printf("成功读出%d个字节:%s\n",size,buf);
	close(fd);
	return 0;
}












