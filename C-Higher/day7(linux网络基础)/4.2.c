#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<pthread.h>
char chat_end = 0;
void* chat_read(void* arg){
	int fd = open("./41",O_RDWR);
	printf("fd = %d\n",fd);
	char buf[100] ="";
	int retval;
	while(1){
		retval = read(fd,buf,100);
		printf("读取到%d字节：%s\n",retval,buf);
		if(strncmp(buf,"end",3)==0){
			break;
		}
		memset(buf,0,100);
	}
	chat_end = 1;
	return NULL;
}

int main(void){
	pthread_t thread;
	pthread_create(&thread,NULL,chat_read,NULL);
	int fd = open("./42",O_RDWR);
	printf("fd = %d\n",fd);
	char buf[100] = "";
	int retval;
	printf("请输入聊天信息：");
	fflush(stdout);
	while(1){
		fgets(buf,100,stdin);
		retval = write(fd,buf,strlen(buf)-1);
		printf("我成功写入了%d字节到管道\n",retval);
		if(strncmp(buf,"end",3) == 0){
			break;
		}
		memset(buf,0,100);
		printf("我：");
		fflush(stdout);
		if(chat_end == 1)break;
	}
	pthread_join(thread,NULL);
	close(fd);
	
	return 0;
}
















