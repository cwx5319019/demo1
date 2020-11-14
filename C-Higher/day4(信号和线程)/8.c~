
//---------线程和进程的区别--------------
//---------开一个进程自己运行的快(因为它拷贝了主进程的全部数据 例如：堆栈)，但多了会拖慢系统------
//---------子线程和主线程共用资源-----------

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* thread_fun(void* arg){
	 
	printf("函数名：%s\n",__FUNCTION__);
	printf("行号：%d \n",__LINE__);
	printf("文件名：%s \n",__FILE__);
	//打印子线程id
	printf("子线程id：0x%x \n",(int)pthread_self());
	while(1){
		sleep(1);
		putchar('*');
		fflush(stdout);
	}
}
int main(){
/*
    pthread_t pthread_self(void);
	打印主线程id
	注意：它的返回值是pthread_t 类型， 所以强转成(int)型，并且 0x%x 16进制格式输出
*/
	printf("主线程id：0x%x\n",(int)pthread_self());
/*
 	int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                 void *(*start_routine) (void *), void *arg);
	创建子线程
*/
	pthread_t threadid;
	pthread_create(&threadid,NULL,thread_fun,NULL);
	//打印子线程id
	printf("子线程id：0x%x\n",(int)threadid);
	while(1){
		sleep(1);
		putchar('.');
		fflush(stdout);
	}
	return 0;
}
















