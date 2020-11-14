
//父进程通过信号来回收子进程的资源

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signal_fun(int signo){
	wait(NULL);
	printf("我已经被回收...\n");
}

int main(void){
	signal(SIGCHLD,signal_fun);
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("我是儿子，我已经生成...\n");
		sleep(10);
		printf("我已经死亡...\n");
	}

	if(pid > 0)while(1);
	
	return 0;
}
/*
int main(void){
	signal(SIGCHLD,signal_fun);
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("son:%d\n",getpid());
		int i = 10;
		while(i--){
			sleep(1);
			putchar('+');
			fflush(stdout);
		}
	}else if(pid > 0){
		printf("father:%d\n",getpid());
		while(1){
			sleep(1);
			putchar('*');
			fflush(stdout);
		}
	}
	return 0;
}
*/




