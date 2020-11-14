#include<stdio.h>
#include<assert.h>
#include<string.h>

int main(){
	int res = 0;
	assert(res==0);
	char str[20] = "hello world";
	char ptr[20] = {0};
	int arr[5] = {1,3,5,7,9};
	int brr[5] = {0};
	memcpy(brr,arr,20);
	printf("brr[0] = %d,brr[4] = %d\n",brr[0],brr[4]);
	return 0;
}
