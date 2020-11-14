
//----------------------信号kill -l  -------------------------
//-----------SIGCONT(18) SIGSTOP(19)  进程继续和停止 -----------
//----注意：SIGSTOP(19) SIGKILL(9) -----不能被捕获和忽视也没用-----

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>

int main(void){

	signal(SIGSTOP,SIG_IGN);
	signal(SIGKILL,SIG_IGN);
	//忽视停止信号 SIGSTOP SIGKILL  
	//写了也不管事  它们俩不能被忽视
	printf("我的pid:%d\n",getpid());
	while(1){
		putchar('.');
		sleep(1);
		fflush(stdout);
	}
	
	return 0;
}

































