
//----------进程链----------

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void){
	pid_t pid;
	int i = 0;
	for(;i<3;i++){
		pid = fork();
		if(pid > 0){
			break;    
		}
	}
	sleep(5);
	if(pid == 0)system("ps f");
	//只打印儿子的信息 系统调用函数 
	sleep(5);
	return 0;
}
