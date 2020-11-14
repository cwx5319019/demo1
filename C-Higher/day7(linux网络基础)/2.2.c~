#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include <sys/stat.h>

int main(void){
	int fd ;
	fd = open("./uuu",O_RDONLY);
	char buf[100] = "";
	while(1){
		read(fd,buf,100);
		printf("读到的内容：%s",buf);
		memset(buf,0,sizeof(buf));
	}
	close(fd);
	return 0;
}
