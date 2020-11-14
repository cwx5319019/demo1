#include<stdio.h>

void print_int(void* data){
	printf("%d ",*(int*)data);
}

void print_char(void* data){
	printf("%c ",*(char*)data);
}

void print_double(void* data){
	printf("%g ",*(double*)data);
}

void print_str(void* data){
	printf("%s ",*(char**)data);
}

void print_data(void* arr,int len,int size,void (*print)(void*)){
	int i = 0;
	for(i=0;i<len;i++){
		print(arr+i*size);
	}
	printf("\n");
}

int main(){
	int arr[5] = {1,3,5,7,9};
	char str[6] = "world";
	double drr[5] = {1.6,2.1,3.5,4.3,5.7};
	char* ptr[5] = {"你好","中国","1908","上海","海同"};
/*
	封装一个函数，要求能够遍历输出以上4种类型的数组
*/
	func(arr,5,4,print_int);
	func(str,5,1,print_char);
	func(drr,5,8,print_double);
	func(ptr,5,8,print_str);
}

