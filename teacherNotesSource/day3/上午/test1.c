/*
	首先在终端上输出__/__/__/__,然后使用while(1)是程序不会结束
	程序休眠2秒之后，将第一组__变成10，再次休眠2秒之后将第二组__变成20，以此类推，最终__/__/__/__变成10/20/30/40
*/
#include<stdio.h>
#include<unistd.h>

int main(){
	printf("__/__/__/__");
	printf("\033[11D");
	fflush(stdout);
	sleep(2);
	printf("10\033[1C");
	fflush(stdout);
	sleep(2);
	printf("20\033[1C");
	fflush(stdout);
	sleep(2);
	printf("30\033[1C");
	fflush(stdout);
	sleep(2);
	printf("40");
	fflush(stdout);
	while(1);
	return 0;
}
