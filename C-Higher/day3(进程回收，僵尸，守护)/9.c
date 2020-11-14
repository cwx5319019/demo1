
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

//------------产生孤儿-------------
int main(){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		int i = 20;
		//子进程循环20次，20秒后退出，这时候父进程已经退出
		//所以它自己就成为了孤儿，它自己会被托付给一个新的父亲
		//ps lf 可以查看 
		printf("我是子进程，我的pid = %d,我的父亲pid是：%d\n",getpid(),getppid());
		while(i--){
			printf("%d ",i);
			fflush(stdout);
			sleep(1);
		}
		printf("我是子进程，我的pid = %d,我的父亲pid是：%d\n",getpid(),getppid());
	}
	//父进程睡10秒退出
	if(pid > 0){
		sleep(10);
		printf("我是父进程，我的pid是：%d,我将离开这个世界。。。\n",getpid());
	}


	return  0;
}




















