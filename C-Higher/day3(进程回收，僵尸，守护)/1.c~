
//运用fork 函数 创建 出一个进程扇（程序一，一个父进程，3个子进程）运用fork函数创建出一个进程链（程序二，父，子，孙三个进程）。要求通过ps elf 查看进程命令 截图显示完成情况。

//ps elf   查看全面信息  f 基本信息（PID）  l稍微多一点（PPID）  e更全面
 

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void creat(pid_t pid){
	pid = fork();
	if(pid < 0){
		perror("pid_1 error");
		exit(1);
	}else if (pid > 0){
		printf("我是父进程:%d \n",pid);
		//sleep(10);
		//exit(1);
	}else{
		//printf("我是子进程:%d \n",pid);
		exit(1);
	}
}

int main(void){
	pid_t pid;
	creat(pid);
	creat(pid);
	creat(pid);
	sleep(10);
	
	return 0;
}









