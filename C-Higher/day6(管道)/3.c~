
//建立两个线程1、2，两个线程分别访问共享资源，并进行加 1操作，
//当共享资源<=3时，线程1挂起不操作，这时线程2工作，共享资源>3后，两者都工作

//-------------注释掉的是死锁----------------

#if 1
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
int temp = 0;
sem_t sem1 ;
pthread_mutex_t mutex;
void* thread_fun1(void* arg){
	while(1){
		sem_wait(&sem1);
		pthread_mutex_lock(&mutex);
		temp++;
		printf("thread_1: %d\n",temp);
		pthread_mutex_unlock(&mutex);	
		sleep(1);
	}
	return NULL;
}
void* thread_fun2(void* arg){
	while(1){
		pthread_mutex_lock(&mutex);
		temp++;
		printf("thread_2: %d\n",temp);
		pthread_mutex_unlock(&mutex);
		if(temp > 3){
			sem_post(&sem1);			
		}
		sleep(1);
	}
	return NULL;
}
int main(void){
	pthread_t thread1, thread2;
	sem_init(&sem1,0,0);
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&thread1,NULL,thread_fun1,NULL);
	pthread_create(&thread2,NULL,thread_fun2,NULL);
	while(1);
	sem_destroy(&sem1);
	pthread_mutex_destroy(&mutex);
	
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
int temp = 0;
sem_t sem1 ;
pthread_mutex_t mutex;
void* thread_fun1(void* arg){
	while(1){
		//两个函数换一下位置就成了死锁
		//如果在小于 3 的时候抢到了锁，这个时候就是死锁  
		//因为抢到了锁，等待函数在卡着它
		pthread_mutex_lock(&mutex);
		sem_wait(&sem1);
		
		temp++;
		printf("thread_1: %d\n",temp);
		pthread_mutex_unlock(&mutex);	
		sleep(1);
	}
	return NULL;
}
void* thread_fun2(void* arg){
	while(1){
		pthread_mutex_lock(&mutex);
		temp++;
		printf("thread_2: %d\n",temp);
		pthread_mutex_unlock(&mutex);
		if(temp > 3){
			sem_post(&sem1);			
		}
		sleep(1);
	}
	return NULL;
}
int main(void){
	pthread_t thread1, thread2;
	sem_init(&sem1,0,0);
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&thread1,NULL,thread_fun1,NULL);
	pthread_create(&thread2,NULL,thread_fun2,NULL);
	while(1);
	sem_destroy(&sem1);
	pthread_mutex_destroy(&mutex);
	
	return 0;
}

#endif






