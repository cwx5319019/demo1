
//创建一个子线程，在主线程中打开一个文件，然后在子线程中定时1秒向文件1.txt中写入Hello

#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/stat.h>
#include<fcntl.h>

void signal_fun(int signo){
	printf("0x%x\n",(int)pthread_self());
	system("echo \"hello\" >> 1.txt");
	alarm(1);
}

void* thread_fun(void* arg){
	printf("0x%x\n",(int)pthread_self());
	signal(SIGALRM,signal_fun);
	alarm(1);
}

int main(void){
	pthread_t thread;
	pthread_create(&thread,NULL,thread_fun,NULL);
	int fd ;
	fd = open("./1.txt",O_CREAT | O_RDWR | O_APPEND,0666);
	
	//可以考录重定向 dup(fd,1)
	while(1);
	
	return 0;
}






