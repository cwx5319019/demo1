#include<stdio.h>

void func(const int* pa){//const int* pa = &a
	//int* a = pa;
	//*a = 10;	//由于c语言的不完善性，这样操作编译可以通过，就导致了const失去了其意义
}

int main(){
	int arr[2][3] = {0};
	int (*parr)[3] = arr;
	//parr[0][1] = 5;
	//*(*(parr+1)+2) = 6;
	int a = 5;
	int b = 10;
	//常量指针
	const int* pa = &a;
	func(&a);
	//int* ppa = pa;	//c语言会提示警告，c++直接报错
	//*pa = 10; //语法错误
	//指针常量
	int* const pb = &b;
	*pb = 15;
	//pb = &a;	//语法错误
	return 0;
}
