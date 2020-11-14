#include<stdio.h>

int main(){
	int a = 8,b = 15;
	printf("%d\n",a = a | (1<<2));
	printf("%d\n",b = b & ~(1<<2));
/*
	0000 1111

	0000 1011
*/
	return 0;
}
