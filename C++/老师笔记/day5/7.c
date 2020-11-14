#include<stdio.h>
void _swap(int a ,int b){
	int c = a;
	a = b;
	b = c;

	
}

int main(int argc,char** argv)
{
	int a= 0,b = 10;
	_swap(a,b);
	printf("a = %d b = %d\n",a,b);
	return 0;
}
