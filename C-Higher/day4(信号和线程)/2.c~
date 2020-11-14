
//------------------------------信号kill -l  ---------------------------
//---------------------------SIGINT(2)终断信号 --------------------------
//-------------------------------ctrl+c---------------------------------
//-------------------kill —9 强制杀死-----ctrl+c 正常终止------------------

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

/*
       #include <signal.h>
       //void (*signal(int sig, void (*func)(int)))(int);
       
       typedef void (* sighander_t)(int)
       sighandler_t signal(int signum,sighandler_t handler)

*/

void catch_sight(int signo){
	static int i = 1;
	printf("signo :%d\n",signo);
	printf("我捕捉到了ctrl+c信号...\n");
	if(i ==2){
		signal(2,SIG_DFL);
		//第二个参数传递SIG_DFL 恢复本信号默认形态
	}
	i++;
}

int main(void){
	signal(SIGINT,catch_sight);
	//signal(SIGINT,SIG_IGN);
	//第一个参数是信号，第二个参数传递函数指针，然后在定义一个函数 
	//第二个参数传递 SIG_IGN 忽视本信号
	while(1){
		putchar('.');
		sleep(1);
		fflush(stdout);
	}
	return 0;
}

































