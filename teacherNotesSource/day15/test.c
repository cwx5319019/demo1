#include<stdio.h>
#include<stdlib.h>
#include<user.h>

int main(){
	char data[20] = {0};
	getstring(data,20);
	int num = atoi(data);
	printf("num = %d\n",num);
/*
	atoi这个函数，会去寻找字符串中的非数字字符，寻找到之后，将该非数字字符之前的所有数字字符转换成一个整型数
*/
	return 0;
}
