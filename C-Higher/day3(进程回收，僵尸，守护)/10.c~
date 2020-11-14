
//-------僵尸进程------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	pid_t pid;
	pid = fork();
	//子进程进入
	if(pid == 0){
		int i = 10;
		printf("我是子进程，我的pid = %d,我的父亲pid是：%d\n",getpid(),getppid());
		while(i--){
			printf("*");
			fflush(stdout);
			sleep(1);
		}
		//循环完毕子进程结束，成为僵尸进程，状态 Z ，<defunct>
		//查看ps -elf  (可以查看到cmd <defunct>)
		//等父进程结束它才会一起被系统回收（被回收后僵尸进程就没了，不回收就会遗留在系统内，成为僵尸进程有很大危害）
		printf("我是子进程，我将离开。。。\n");
	}
	//父进程进入
	if(pid > 0){
		while(1){
		printf("+");
		fflush(stdout);
		sleep(1);
		}
	}
	return  0;
}







































