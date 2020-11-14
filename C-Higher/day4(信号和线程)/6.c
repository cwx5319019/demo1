
//-----------父进程 和 子进程 相互搏杀---------------

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>

int main(void){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("我的父亲：%d\n",getppid());
		//kill(getppid(),9);
		//printf("我的父亲已被我杀。。。。\n我的新父亲：%d\n",getppid());
		
	}else{
		printf("我的儿子：%d\n",pid);
		kill(pid,9);
		printf("我的儿子已被我杀。。。。\n");
	}
	sleep(5);
	return 0 ;
}



