
//--------------分离属性也可以删除-----------------

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void* thread_fun(void* arg){
	while(1){
		putchar('.');fflush(stdout);sleep(1);
	}
	return NULL;
}
int main(void){
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_create(&thread,&attr,thread_fun,NULL);
	int i = 10;
	while(i--){
		putchar('*');fflush(stdout);sleep(1);
	}
	
	//删除成功返回 0 ，失败错误编码
	int res = pthread_cancel(thread);
	if(res == 0){
		printf("res = %d,删除成功...\n",res);
	}
	
	pthread_attr_destroy(&attr);
	return 0;
}















