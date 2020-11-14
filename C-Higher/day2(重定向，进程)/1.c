
//-------作业第一题------------使用lseek  SEEK_END  返回字节数
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char** argv){
	int fd = open(argv[1],O_RDONLY);
	if(argc < 2){
		perror("stdin error");
		exit(1);
	}
	if(fd == -1){
		perror("open error");
		exit(1);
	}
	int retval = 0;
	char buf[2] = {0};
	while(1){
		retval = read(fd,buf,1);
		write(1,buf,strlen(buf)); 
		//write 第一个参数只能是 1，不能写stdout，stdout是宏，文件描述符是值
		if(retval == -1){
			perror("read error ");
			exit(1);
		}else if(retval != 1){
			exit(1);
		}	
	}
	close(fd);
	exit(0);
}

