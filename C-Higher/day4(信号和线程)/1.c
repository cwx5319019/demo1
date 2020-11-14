
//----------------在孤儿进程内产生100个僵尸进程-----------------------

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(void){
	pid_t pid;
	int status = 0;
	pid = fork();
	if(pid < 0){
		perror("fork fail...");
		exit(-1);
	}else if(pid > 0){
		//wait(NULL);
		exit(1);
	}else{
		pid_t res;
		int i = 0;
		for(;i<100;i++){
			res = fork();
			if(res == 0)exit(1);
			//wait(NULL);   //回收后不会产生，注意放在循环内部
		}
	}
	
	system("ps -elf");
	return 0;
}
