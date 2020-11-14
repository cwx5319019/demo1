
//----------------进程之间通信（无名管道1）-----------------------

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void){
	//定义两个文件描述符号
	int fd[2];
	//创建无名管道
	pipe(fd);
	//printf("fd[0] = %d\n",fd[0]); //读
	//printf("fd[1] = %d\n",fd[1]); //写
	pid_t pid;
	pid = fork();
	if(pid == 0){
		int retval = 0;
		char buf[10] = "";
		printf("我是子进程，我在等待父亲写数据...\n");
		retval = read(fd[0],buf,10);//fd[0] 读
		printf("我是子进程，我从父亲那里读到了%d字节:%s\n",retval,buf);
		close(fd[0]);
		exit(1);
	}
	if(pid > 0){
		char* str = "1234567890\n";
		int i = 10;
		while(i--){
			sleep(1);putchar('*');fflush(stdout);
		}
		write(fd[1],str,11);//fd[1] 写
		printf("我是父进程，我写了11个数据给儿子...");
		close(fd[1]);
		exit(1);
	}

	return 0;
}
































