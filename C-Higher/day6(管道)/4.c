
//--------------分离和不分离属性-----------------
/*
pthread_create( ,attr, , ); 第二个参数是重点
如果第二个参数是： 
			分离属性   用在并发状态 系统会回收它
			不分离属性 用在非发状态 主线程阻塞自己等待子线程运行完毕回收它

*/

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
	//创建属性
	pthread_attr_t attr;
	//初始化属性
	pthread_attr_init(&attr);
	//设置属性
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	//创建子线程，第二个参数引用属性
	pthread_create(&thread,&attr,thread_fun,NULL);
	int i = 10;
	while(i--){
		putchar('*');fflush(stdout);sleep(1);
	}
	//用于验证使用分离属性后主线程不会去等待子线程
	//也就是说使用分离属性后，pthread_join()不起作用，系统会回收子线程
	//pthread_join()作用是主线程等待子线程结束并回收
	pthread_join(thread,NULL);
	printf("pthread_join结束了...\n");
	//销毁属性
	pthread_attr_destroy(&attr);
	
	return 0;
}















