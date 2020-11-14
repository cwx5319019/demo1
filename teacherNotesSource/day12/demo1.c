#include<stdio.h>

typedef int (*stdio)(const char*,...);

int main(){
	//int printf(const char *format, ...);
	int data = 0;
	//int (*s)(const char*,...) = scanf;
	//int (*p)(const char*,...) = printf;
	stdio s = scanf;
	stdio p = printf;
	s("%d",&data);
	while(getchar()!=10);
	p("data = %d\n",data);


	return 0;
}
