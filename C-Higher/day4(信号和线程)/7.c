
//-------------------------------信号kill -l  -------------------------------
//---------------------------SIGALRM(14)  闹铃信号-----------------------------

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>

void catch_alarm(int signo){
	system("date");//打印日期和时间
	alarm(1);//再次启动闹钟
}
int main(){
	signal(SIGALRM,catch_alarm);
	alarm(1);//1秒触发闹钟
	while(1){
		putchar('.');
		fflush(stdout);
		sleep(10);//有闹钟在  它只能睡1秒就被闹铃叫醒 
		
	}
}



