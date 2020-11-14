
//写一个程序在屏幕上不停打印‘@’，当按下ctrl+c信号时，使用raise函数发送SIGINT信号给本进程，使本进程结束。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/signal.h>
void signal_fun(int signo){
	printf("我捕捉到了ctrl+c...\n");
	printf("我将杀死自己...\n");
	raise(SIGKILL);
}
int main(void){
	signal(SIGINT,signal_fun);
	while(1){
		putchar('@');
		fflush(stdout);
		sleep(2);
	}
	return 0;
}













