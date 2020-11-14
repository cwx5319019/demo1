#include<stdio.h>

typedef int (*stdio_t)(const char*,...);

int main(){
	int data = 0;
	//int (*arr[2])(const char*,...) = {printf,scanf};
	stdio_t arr[2] = {printf,scanf};
	arr[0]("请输入数据:");
	arr[1]("%d",&data);
	while(getchar()!=10);
	arr[0]("data = %d\n",data);
	return 0;
}
