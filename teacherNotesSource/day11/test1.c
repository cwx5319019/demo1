#include<stdio.h>

int main(){
	int arr[10] = {1,3,5,7,9,2,4,6,8,99};
/*
	要求，只偏移两次，每次都只能偏移1个模块，访问到数据：
		7,9,3,0
*/
	printf("%d\n",*((int*)((double*)arr+1)+1));
	printf("%d\n",*(int*)((double*)arr+1+1));
	printf("%d\n",*(int*)((short*)arr+1+1));
	printf("%d\n",*((int*)(&arr+1)-1));
	return 0;
}
