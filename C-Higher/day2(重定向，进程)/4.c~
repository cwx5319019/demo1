#include<stdio.h>
#include<unistd.h>

int main(void){
/*
	//dup函数
	//int dup(int oldfd);
	int newfd ;
	newfd = dup(1);
	//close(1); //1是屏幕 不要关闭
	printf("newfd = %d\n",newfd);
	//newfd 是新创建的文件描述符 dup复制旧的文件描述符，功能和旧的文件描述符一样 （stdout）
	write(newfd,"hello\n",6);
	close(newfd);
*/
	//dup2函数
	//int dup2(int oldfd，int newfd);
	int newfd ;
	newfd = dup2(1,100);
	//close(1); //1是屏幕 不要关闭
	printf("newfd = %d\n",newfd);   //100
	//newfd 是新创建的文件描述符 dup复制旧的文件描述符，功能和旧的文件描述符一样 （stdout）
	write(newfd,"hello\n",6);
	close(newfd);	
	
	return 0;
}

