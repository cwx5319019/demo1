/*
	假设现在有一个整型数 int a = 12345,要求，将他变成54321后，输出到终端上。使用算术运算符和赋值运算符即可实现。
*/
#include<stdio.h>

int main(){
	int a = 12345;
	int five = a%10 * 10000;//5
	int four = a/10%10 * 1000;//4
	int three = a/100%10 * 100;//3
	int two = a/1000%10 * 10;//2
	int one = a/10000;//1
	a = one+two+three+four+five;
	printf("a = %d\n",a);
	return 0;
}
