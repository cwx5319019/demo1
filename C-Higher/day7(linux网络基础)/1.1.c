
//写两个程序，1.c 和2.c。通过命名管道的方式，实现 1.c 和 2.c 之间 相互聊天。
//（注意开辟线程让读和写互不影响,这里需要双向通讯注意创建2个命名管道）

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sem1,sem2;

void* pthread_fun(void* arg){
	int fd = open("./two",O_RDONLY);
	char buf[100] = "";
	while(1){
		sem_wait(&sem1);
		int res = read(fd,buf,100);
		if(res == -1){
			perror("read error");
			exit(-1);
		}
		printf("对方的内容：%s",buf);
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
	int fd = open("./one",O_WRONLY);
	if(fd == -1){
		perror("open error");
		exit(-1);
	}
    //ssize_t write(int fildes, const void *buf, size_t nbyte);
	char buf[100] = "";
	while(1){
		printf("你的内容：");
		fgets(buf,100,stdin);
		int res = write(fd,buf,100);
		if(res == 0){
			perror("write error");
			exit(-1);
		}
		sem_post(&sem1);
		sem_wait(&sem2);
	}

	char* retval= NULL;
	
	pthread_join(thread,(void**)retval);
	return 0;
}
















