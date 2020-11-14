#include<stdio.h>

int main(){
	int a = 5;
	printf("a的地址为:%p\n",&a);
	int* pa = &a;//pa指向变量a的地址，a是int类型，所以pa是int*类型
	int** ppa = &pa;//ppa指向了变量pa的地址，pa是int*类型，所以ppa是int**类型
	int*** pppa = &ppa;//pppa指向了变量ppa的地址，ppa是int**类型，所以pppa是int***类型
	

	printf("a = %d\n",***pppa);
	return 0;
}
