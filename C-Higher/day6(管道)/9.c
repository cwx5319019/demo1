
//--------------有名管道（2）---------------
/*
1：普通文件 -
2：连接文件 l
3:目录文件  d
4:管道文件p
5:字符设备文件c
6:块设备文件b
*/
/*
--------mkfifo uuu 创建有名管道-------- 
有名管道：用于非亲圆关系的进程通信 
1)如果读端打不开（不掉用open），则写端open函数阻塞
2)如果写端不写，则读端阻塞（直到写端写入数据）
3)如果读端不读，则写端不阻塞
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(void){
	int fd;
	fd = open("./uuu",O_WRONLY);
	printf("fd = %d\n",fd);
	int size;
	char* str = "1234567890\n";
	sleep(10);
	printf("写之前...\n");
	size = write(fd ,str,11);
	printf("成功写入%d个字节\n",size);
	close(fd);
	return 0;
}






























