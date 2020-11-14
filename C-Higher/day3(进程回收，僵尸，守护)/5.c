//实现自己的一个myshell,同时把执行的命令结果重定向输出到文件.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main(void){
/*
	char *fgets(char *s, int size, FILE *stream);
	从文件里得到 size 字节 放入 s 
	int system(const char *command);
	括号里面放的是指针
*/
	char buf[10] = "";
	int retval = 0;
	int savefd = dup(1);  //保存指向屏幕的文件描述符
	int fd = open("5.txt",O_RDWR| O_CREAT,0666);
	while(1){
		dup2(savefd,1);  //在把输出的信息重新定向在屏幕
		dup2(fd,2);
		printf("请输入shell指令：");
		fflush(stdout);
		fgets(buf,10,stdin);
		if(strncmp(buf,"end",3)==0){
		//strncmp 防止'\n'被读入，只读3个
			break;
		}
		dup2(fd,1);//把输出的信息重定向进文件
		dup2(fd,2);//把错误信息也重定向到文件
		retval = system(buf);
		//得到输入的shell指令，会在代码里面执行system
		printf("retval = %d\n",retval);
		//成功返回0，失败返回错误编码
	}
	close(fd);
	return 0;
}


























