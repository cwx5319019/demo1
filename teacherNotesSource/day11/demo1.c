#include<stdio.h>

int main(){
	int a = 5;
	int* pa = &a;
	int arr[5] = {1,3,5,7,9};
	printf("%p\n",pa);
	printf("%p\n",pa+1);
	printf("%d\n",*(arr+4));
	printf("%d\n",arr[4]);
	return 0;
}
