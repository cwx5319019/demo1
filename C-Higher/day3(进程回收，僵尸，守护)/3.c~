

//----------进程扇----------


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void){
	pid_t pid;
	int i = 0;
	for(;i<3;i++){
		pid = fork();
		if(pid == 0){
			//printf("pid = %d\n",pid);
			break;      //儿子退出     还没死
			//exit(1);  //儿子直接退出  死掉
		}
	}
	sleep(5);
	if(pid > 0)system("ps elf");  
	// f 就可以看基本信息（PID）   加上l可以看到 PPID  加上e就可看到更详细的信息
	sleep(5);
	return 0;
}
