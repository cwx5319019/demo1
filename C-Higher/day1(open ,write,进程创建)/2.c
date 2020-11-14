#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void)
{
	//open函数
	int fd;
	fd = open("./1.txt",O_RDONLY);
	//只读方式打开1.txt
	printf("fd=%d\n",fd);
	if(fd == -1){
		perror("open打开文件失败...");
		exit(1);
	}
	//close函数
	int res;
	res = close(fd);
	printf("res1 = %d\n",res);
	res = close(fd);
	//关闭一个已经关闭的文件，会错误,返回 -1
	printf("res2= %d\n",res);
	if(res ==-1){
		perror("close关闭文件失败...");
		exit(1);
	}
	
	return 0;	
}
