
//用mkfifo创建管道文件，两个程序，一个程序向其中写入数据，另外 一个程序从管道文件中读取数据，
//（注意管道文件如果存在就会报错，所以开始我们要先通过access函数判断管道文件是否存在）

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include <sys/stat.h>

// int access(const char *path, int amode);

int main(void){
	char* filename = "./uuu";
	int res = access(filename,F_OK);
	if(res == 0){
		printf("文件已经存在！\n");
		exit(-1);
	}
	system("mkfifo uuu");
	int fd ;
	fd = open("./uuu",O_WRONLY);
	while(1){
		printf("请输入内容：");
		char buf[100] = "";
		fgets(buf,100,stdin);
		write(fd,buf,100);
		memset(buf,0,sizeof(buf));
	}
	close(fd);
	return 0;
}



















