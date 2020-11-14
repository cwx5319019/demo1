#include<stdio.h>

void print_int(void* data){
	printf("%d\n",*(int*)data);
}

void print_char(void* data){
	printf("%c\n",*(char*)data);
}

void print_double(void* data){
	printf("%g\n",*(double*)data);
}

void print_str(void* data){
	printf("%s\n",(char*)data);
}

void func(void* data,void (*print)(void*)){
	print(data);
}

/*
	封装一个函数：技能计算两个数的平方和，又能计算两个数的立方和
*/

int main(){
	int a = 5;
	char b = 'x';
	double c = 3.14;
	char* str = "你好上海";
	func(str,print_str);
	func(&a,print_int);
	return 0;
}
