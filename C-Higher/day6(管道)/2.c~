
/*
定义一个结构体变量
	struct student
	{
		int id;
		char name[20];
		float score;
	};

将结构体变量通过传参的方式传入子线程,在子线程中打印这个结构体的内容,子线程退出的时候给主线程一个返回值,主线程接收返回值并打印
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

typedef struct student{
	int id;
	char name[20];
	float score;
}std;

void* thread_fun(void* arg){
	((std*)arg)->id = 2;
	strcpy(((std*)arg)->name ,"张三");
	((std*)arg)->score = 80.0;
	printf("id :%d\n",((std*)arg)->id);
	printf("name :%s\n",((std*)arg)->name);
	printf("score :%.2f\n",((std*)arg)->score);
	
	return (void*)arg;
}

int main(void){	
	pthread_t thread;
	std student ;
	memset(&student,0,sizeof(std));
	pthread_create(&thread,NULL,thread_fun,(void*)&student);
	
	char* retval = NULL;
	pthread_join(thread,(void**)&retval);
	printf("retval :%d\n",*retval);
	
	
	return 0;
}



























