#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void out_status(int status){
	if(WIFEXITED(status)){
		printf("%d\n",WEXITSTATUS(status));
	}else if(WIFSIGNALED(status)){
		printf("%d\n",WTERMSIG(status));
	}else if(WIFSTOPPED(status)){
		printf("%d\n",WSTOPSIG(status));
	}else {
		printf("unkonw sig\n");	
	}	

}

int main(void){
	int status;
	pid_t pid;
	if ((pid = fork()) < 0){
		perror ("fork error");
		exit(1);
	}else if(pid == 0){
		printf("pid%d ppid %d\n",getpid(),getppid());
		exit(3);
	}
	//父进程调用wait函数阻塞自己 
	wait (&status);
	out_status(status);
	printf("--------------\n");
	if ((pid = fork()) < 0){
		perror ("fork error");
		exit(1);
	}else if(pid == 0){
		printf("pid%d ppid %d\n",getpid(),getppid());
		int i = 3 , j = 0;
		int k = i /j;
		printf("%d\n",k);
	}
		wait (&status);
		out_status(status);
		printf("--------------\n");	
	if ((pid = fork()) < 0){
		perror ("fork error");
		exit(1);
	}else if(pid == 0){
		printf("pid%d ppid %d\n",getpid(),getppid());
		pause();
	}	
		wait (&status);
		out_status(status);
		printf("--------------\n");	
	
	
	return 0;
}
