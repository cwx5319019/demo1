
//---------------线程删除-----------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
void* pthread_fun(void* arg){
	//忽视来自主线程的删除
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);  
	int i = 10;
	while(i--){
		putchar('*');
		fflush(stdout);
		sleep(1);
	}
	puts("我要删除主线程");
	pthread_cancel((int)arg);
	return NULL;
}
int main(void){
	pthread_t pthread;
	int res = pthread_self();
	printf("主线程id：0x%x\n",res);
	pthread_create(&pthread,NULL,pthread_fun,(void*)res);
	int i = 5;
	while(i--){
		putchar('+');
		fflush(stdout);
		sleep(1);
	}
	puts("我要删除子线程");
	//删除成功返回 0 失败错误编码
	int retval = pthread_cancel(pthread);
	printf("retval = %d\n",retval);
	while(1){
		putchar('.');
		fflush(stdout);
		sleep(1);	
	}
	
	
	return 0;
}



