#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(void)
{
	//open函数
	int fd;
	fd = open("./2.txt",O_RDWR);//注意：我如果对文件进行又读又写必须这样写，如果分开写 O_RDONLY | O_WRONLY 它只认 O_WRONLY 这个会把O_RDONLY 覆盖掉
	printf("fd=%d\n",fd);
	
	//write函数  //注意：写完之后指针已经偏移到最后了
	int retval;
	char *buf ="hello world\n";
	retval = write(fd,buf,strlen(buf));
	if(retval == -1){
		perror("写入失败");
		exit(1);
	}else{
		printf("成功写入了%d字节\n",retval);
	}
	//lseek函数
	//把文件指针置于开始，偏移0个字节
	lseek(fd,0,SEEK_SET);

	//read函数
	int size;
	char buf2[20] = "";
	size = read(fd,buf2,strlen(buf2));
	if(size == -1){
		perror("读取失败");
		exit(1);
	}else{
		printf("读取到%d字节：%s\n",size,buf2);
	}
	
	
	//close函数
	int res;
	res = close(fd);
	if(res ==-1){
		perror("close关闭文件失败...");
		exit(1);
	}	
	
	return 0;	
}
