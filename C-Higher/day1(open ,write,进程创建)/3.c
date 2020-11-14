#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void)
{
	//open函数
	int fd;
	fd = open("./1.txt",O_RDONLY);
	//只读方式打开1.txt
	printf("fd=%d\n",fd);
	if(fd == -1){
		perror("open打开文件失败...");
		exit(1);
	}
	//read函数
	//1.要得数据小于文件中的数据0123456789\n 写的文件后面有个\n
	//2.要得数据大于文件中的数据，返回所有数据
	//3.buff长度小于第三个参数count，会出错误,数组越界
	int size;
	char buf[5] ="";
	size = read(fd,buf,10);
	//从fd里读取10个字节放到buf里
	printf("read读取到了%d字节：%s\n",size,buf);
	
	close(fd);
	
	return 0;	
}
