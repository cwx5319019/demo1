
//----开一个进程自己运行的快(因为它拷贝了主进程的全部数据)，但会拖慢系统------
//----

//-------------------------pthread_create()函数第四个参数不是NULL的情况---------------------------

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* thread_fun(void* arg){
	int i = 10;
	while(i--){
		sleep(1);
		putchar(*((char*)arg));
		fflush(stdout);
		(*((char*)arg))++;
	}
	return (void*)arg;  //这时候遇到问题，怎么得到它的返回值 见10.c
}
int main(){
	char a = 'a';
	pthread_t threadid;
/*
  int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                 void *(*start_routine) (void *), void* arg);
*/
	//创建子线程
	pthread_create(&threadid,NULL,thread_fun,(void*) &a);
	while(1){
		sleep(1);
		putchar('.');
		fflush(stdout);
	}
	return 0;
}
















