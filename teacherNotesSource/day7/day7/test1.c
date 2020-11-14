/*
	编写一个函数，它能够传入随意数量的整型数，函数功能为计算所有传入参数的和
*/

#include<stdio.h>
#include<stdarg.h>

int func(int num,...){
	va_list p;
	va_start(p,num);
	int i = 0;
	int res = 0;
	for(i=0;i<num;i++){
		res = res + va_arg(p,int);
	}
	va_end(p);
	return res ;
}

int main(){
	int res = func(6,1,2,3,4,5,6);
	printf("res = %d\n",res);
	return 0;
}
