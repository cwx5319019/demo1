#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
#if 1
	//open 和 fopen 区别
	//open  行缓存  一行读到\n  直接写入文件 
	//fopen 全缓存  一行读到\n  不理会 等缓存满了在写入文件
	int fd;
	//O_CREAT这个功能被使用时候必须给定文件属性 0222
	fd = open("./4.txt",O_RDWR);
	printf("fd=%d\n",fd); 
	int retval;
	int i = 10;
	while(i--){
		retval = write(fd ,"hello world\n",5);
		printf("写入了%d个字节\n",retval);
		sleep(1);
	}
#endif 
#if 0	
	FILE* fp = NULL;
	fp = fopen("./5.txt","w");
	printf("fp=%p\n",fp); 
	int retval;
	char* buf = "hello\n";
	int i = 10;
	while(i--){
		retval = fwrite(buf,strlen(buf),1，fp); 
		//返回值是第三个参数
		printf("写入了%d个字节\n",strlen(buf));
		sleep(1);
	}
#endif	
	return 0;
}

