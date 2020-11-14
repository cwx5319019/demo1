#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sem1,sem2;
void* pthread_fun(void* arg){
	int fd = open("./two",O_WRONLY);
	char buf[100] = "";
	while(1){
		sem_wait(&sem1);
		printf("你的内容：");
		fflush(stdout);
		fgets(buf,100,stdin);
		int res = write(fd,buf,100);
		if(res == 0){
			perror("write error");
			exit(-1);
		}
		sem_post(&sem2);
	}
	return NULL;
}
int main(void){
	sem_init(&sem1,0,0);
	sem_init(&sem2,0,0);
	pthread_t thread;
	int ret = pthread_create(&thread,NULL,pthread_fun,NULL);
	if(ret != 0){
		perror("create pthread error");
		exit(-1);
	}
	int fd = open("./one",O_RDONLY);
	if(fd == -1){
		perror("open error");
		exit(-1);
	}
    //ssize_t write(int fildes, const void *buf, size_t nbyte);
	char buf[100] = "";
	while(1){
		int res = read(fd,buf,100);
		if(res == -1){
			perror("read error");
			exit(-1);
		}
		printf("对方的内容：%s",buf);
		sem_post(&sem1);
		sem_wait(&sem2);
	}

	char* retval= NULL;
	pthread_join(thread,(void**)retval);
	
	return 0;
}
















