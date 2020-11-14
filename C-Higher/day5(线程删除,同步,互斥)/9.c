
//先安装sudo apt-get install manpages-posix-dev
//restrict 类似const是个关键字  它修饰指针，只能通过该关键字修饰的指针访问内存。
//使用函数时候，属性指针不知道的就写 NULL

//---------------线程函数(互斥锁)-----------------

#if 0
pthread_mutex_t mutex;  //定义互斥锁
pthread_mutex_init(&mutex,NULL); //初始化互斥锁

//使用这个初始化宏，就不需要上面的初始化函数
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER   //( [ɪ'nɪʃəlaɪzə)

//上锁  类似同步 sem_wait()函数
pthread_mutex_lock(&mutex);  

//解锁 
pthread_mutex_unlock(&mutex);
#endif

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
int tick = 1000;


void* thread_tick(void* arg){
	int ticknum = 0;
	
	while(1){
		pthread_mutex_lock(&mutex);
		if(tick > 0 ){
			tick--;
			ticknum++;
			printf("0x%x抢到了%d张票，还剩%d张票...\n",(int)pthread_self(),ticknum,tick);
			pthread_mutex_unlock(&mutex);
			sleep(1);
		}else{
			printf("0x%x票抢完了...\n",(unsigned int)pthread_self());
			pthread_mutex_unlock(&mutex);
			break;
		}
	}
}

int main(void){
	pthread_t pthread[300];
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex,NULL);
	int i = 0;
	for(;i<300;i++){
		pthread_create(&pthread[i],NULL,thread_tick,NULL);
	}
	while(1);
	pthread_mutex_destroy(&mutex);

	return 0;
}







































