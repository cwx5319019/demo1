#include<stdio.h>

int* func(int* b){
	int a = 5;//0x21
	int* pa = &a;
	//pa = b;
	return pa;//return &a;
}
/*
	无论是返回pa也好，还是返回&a也好，都是返回一个局部变量地址，都属于非法操作。所以，无论如何神操作，都不允许返回一个栈空间局部变量的地址
*/
int main(){
	int b = 5;
	int* pa = func(&b);
	printf("%d\n",*pa);
	return 0;
}
