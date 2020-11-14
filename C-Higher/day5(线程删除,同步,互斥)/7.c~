
//---------------线程函数(解决线程同步)-----------------
#if 0
sem_t sem; //定义同步函数变量

//初始化同步函数变量   
//第二个参数0，只能在生成我的这个进程用，别的进程不能用
//第三个参数1，则开始执行第一次，第三个参数0，则开始不执行，等待
sem_init(&sem,0,0);
 
//等待函数内部在进行sem-1操作，如果sem-1 < 0则等待，sem-1 >= 0则继续进行
sem_wait(&sem)

//执行的时候进行sem+1
sem_post(&sem)

//销毁
sem_destroy(&sem);

#endif

#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>
sem_t sem;
sem_t sem1;
char buff[30] = "";
void* thread_fun(void* arg){
	while(1){
		sem_wait(&sem);
		printf("你录入了%d个字节\n",(int)strlen(buff)-1);
		sem_post(&sem1);
	}
}
int main(void){
	pthread_t thread;
	sem_init(&sem,0,0);
	sem_init(&sem1,0,1);
	char Esc = 27;
	pthread_create(&thread,NULL,thread_fun,NULL);
	while(1){
		sem_wait(&sem1);
		printf("请输入字符：");
		fgets(buff,30,stdin);
		if(strncmp(buff,&Esc,1)==0){
			return 0;
		}
		sem_post(&sem);
	}
	sem_destroy(&sem);
	return 0;
}


















