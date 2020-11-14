#include"head.h"

void func1(){
	printf("1号函数 data = %p\n",&data);
	func2();
}

void func2(){
	printf("2号函数\n");
	int a = 10/0;
}
