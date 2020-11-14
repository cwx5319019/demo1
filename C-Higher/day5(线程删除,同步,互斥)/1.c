
//---通过alarm函数在屏幕上定时的打印当前时间-----

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signal_fun(int signo){
	system("date");
	alarm(10); //10秒打印1次时间
}

int main(void){
	signal(SIGALRM,signal_fun);
	alarm(10);
	while(1);
	return 0;
}
