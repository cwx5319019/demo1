#include<stdio.h>

int main(){
	int arr[6] = {1,3,5,7,9,11};
	printf("%d\n",&arr[3] - &arr[0]);
	return 0;
}
