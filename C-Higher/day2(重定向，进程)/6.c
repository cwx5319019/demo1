#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(void){
	//dup2函数
	//int dup2(int oldfd，int newfd);
	int fd = 0;
	int savefd = dup(1);  // savefd文件描述符    //记得把问加描述符号“1”保存中间变量 ，因为后面它的指向更改了，就不能再使用“1”文件描述符了
	
	fd = open("6.txt",O_RDWR|O_CREAT,0666);
	int newfd ;
	printf("fd = %d\n",fd);
	newfd = dup2(fd,1);   //newfd文件描述符    //这时候“1”的指向已经改变 ，指向了fd ，也就是变为指向文件
	printf("newfd = %d\n",newfd); 
	write(newfd,"hello1\n",6);
	
	int newfd_1 = 0;
	newfd_1 = dup2(savefd,1);  //把新的“1”在指向之前的中间变量，这时候“1”又能正常输出
	
	printf("hello2\n");
	puts("hello3");
	
	close(fd);	
	return 0;
}
