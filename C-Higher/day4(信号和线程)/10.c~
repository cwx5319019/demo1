#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* thread_fun(void* arg){
	int i = 20;
	while(i--){
		sleep(1);
		putchar(*((char*)arg));
		fflush(stdout);
		(*((char*)arg))++;
	}
	return (void*)arg;  
	//这时候遇到问题，怎么得到它的返回值,解决这个问题 对比进程wait()函数
	//引入 pthread_join()函数

	
}
int main(){
	char a = 'a';
	pthread_t threadid;
	pthread_create(&threadid,NULL,thread_fun,(void*) &a);
	int i = 10;
	while(i--){
		sleep(1);
		putchar('.');
		fflush(stdout);
	}
/*
	pthread_join() 函数
    int pthread_join(pthread_t thread, void** retval);
    功能：阻塞父线程 回收子线程
*/
	char* retval = NULL;
	//定义一个char* 因为返回的是 char* 类型
	pthread_join(threadid,(void**)&retval);
	//因为pthread_join 函数第二个参数 使用的二级指针，所以也得取地址
	printf("子线程返回值：%c\n",*retval);
	//打印直接打印retval 注意要加个*  因为它本身是个地址，用*中和掉&
	return 0;
}
















