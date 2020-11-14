
//-------------------------------信号kill -l  -------------------------------
//---------SIGKILL(9)杀死进程 SIGCONT(18)继续进程 SIGSTOP(19)停止进程 -----------
//--------------------------用本程序去控制4.c的运作 --------------------------

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>

int main(int argc,char** argv){
	if(argc < 3){
		printf("usage:./a.out pid sinnum");
		exit(1);
	}
	kill(atoi(argv[1]),atoi(argv[2]));
	return 0 ;
}




