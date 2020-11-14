#include<stdio.h>

void func(int* a,int* b){
	//*a = *b;
	a = b;
}

int main(){
	int a = 5;
	int b = 10;
	func(&a,&b);
	printf("a = %d\n",a);
	return 0;
}
