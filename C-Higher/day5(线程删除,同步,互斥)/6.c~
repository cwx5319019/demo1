
//---------------全局变量共用(解决线程同步)-----------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
char FLAG = 1;
void* thread_fun(void* arg){
	while(1){
		if(FLAG == 2){
			putchar('2');
			fflush(stdout);
			FLAG = 1;
			sleep(1);
		}
	}
	return  (void*)0;
}
int main(void){
	pthread_t pthread;
	pthread_create(&pthread,NULL,thread_fun,NULL);
	while(1){
		if(FLAG == 1)
				putchar('1');
				fflush(stdout);
				FLAG = 2;
				sleep(1);
	}	
	return 0 ;
}















