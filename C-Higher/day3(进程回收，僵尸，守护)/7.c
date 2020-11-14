
//---------wait（int* status）函数----------

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(void){
	pid_t pid,wpid;
	pid = fork();
	printf("pid = %d\n",pid);
	switch(pid){
		case -1:
			perror("error");
			exit(-1);
		case 0 :
			{
				int i = 10;
				printf("i am child,my pid :%d\n",getpid());
				while(i--){
					printf("*");sleep(1);fflush(stdout);
				}
			}
			exit(100);//return 100;//只能返回整型
		default :
			{
				int status = 0;
				printf("i am father,my pid:%d\n",getpid());
/*	
	         pid_t wait(int *stat_loc);
			
			 wait函数：  wait(&status)有参数情况 
			 			等待子进程结束，并回收资源//注意：子进程很多的情况下，只等待最先退出的，然后父进程就退出
			 			如果没有子进程，则返回-1，否则返回子进程pid
			 			使用宏可以查看子进程返回值，WEXITSTATUS(status)输出的时候用宏读取到值
*/
				wpid = wait(&status);
				printf("wpid = %d,status = %d\n",wpid,WEXITSTATUS(status));
			}

	}
	return 0;
}




