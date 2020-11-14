
//--------------------------------信号kill -l  --------------------------
//--------------------------SIGCHLD(17) 回收僵尸进程 ---------------------

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>
void catch_child(int signo){
	pid_t pid;
	pid = wait(NULL);
	printf("我是子进程，我的pid：%d\n",getpid());
}

int main(void){
	pid_t pid;
	pid = fork();
	signal(SIGCHLD,catch_child);
	//使用背景，因为父进程需要执行别的代码，在父程序里使用wait()会阻塞自己回收僵尸进程，这样会影响父进程，所以使用信号 SIGCHLD ，子进程执行完毕，该信号会被启动调用 catch_child 函数，去执行 catch_child函数里的 wait() 函数，把僵尸进程全部收回
	if(pid == 0){
		int i = 10;
		while(i--){
			putchar('*');
			sleep(1);
			fflush(stdout);
		}
		exit(1);
	}
	if(pid > 0){
		while(1){
			putchar('.');
			sleep(1);
			fflush(stdout);
		}
	}
	
	return 0;
}

































