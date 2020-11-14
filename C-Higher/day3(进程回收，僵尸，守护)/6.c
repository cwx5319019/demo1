
//--------wait(NULL)函数------

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void){
	pid_t pid,wpid;
	pid = fork();
	printf("pid = %d\n",pid);
/*	
	pid_t wait(int *stat_loc);
			
	wait函数：wait()无参数情况 
			 等待子进程结束，并回收资源
			 如果有子进程，且子进程不结束，则一直等待，如果结束，则返回子进程PID
			 如果没有子进程，则返回-1
*/
	if(pid > 0){
		 
		wpid = wait(NULL); 
		printf("wpid = %d\n",wpid);
	}
	return 0;
}
