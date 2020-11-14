#include<stdio.h>

int main(){
	int arr[5] = {1,3,5,7,9};
	int brr[5] = {0};

	/*printf("arr = %p\n",arr);
	printf("arr+1 = %p\n",arr+1);
	printf("&arr = %p\n",&arr);
	printf("&arr+1 = %p\n",&arr+1);
	printf("%lu\n",sizeof(arr));*/
	int* pa = 0;
	int a = 5;
	pa = arr;
	pa = brr;
	pa = &a;
	return 0;
}
