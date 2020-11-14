#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
	//open函数
	int fd;
	//O_CREAT这个功能被使用时候必须给定文件属性 0222
	//如果打开的文件已经存在，创建就不生效了
	fd = open("./3.txt",O_RDWR|O_CREAT,0222);
	printf("fd=%d\n",fd);   

	return 0;
}

