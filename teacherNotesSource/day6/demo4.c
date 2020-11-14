#include<stdio.h>

void func(int* pa,int* pb){
	*pa = 10;
	*pb = 50;
	return ;
}

int main(){
	int a = 5;
	int b = 20;
	
	/*int* pa = &a;
	*pa = 10;
	a = 10	*/

	func(&a,&b);
	printf("a = %d,b = %d\n",a,b);
	return 0;
}
