/*
	封装一个函数：要求，它能够传入任意类型的数组。在函数内部，手动输入想要访问的数组的下标，然后返回该下标的地址
	函数外部，根据传入不同的数组返回的地址，打印相应数据类型的数据
	举例：{1,3,5,7,9},内部输入了3，则应该返回&7，外部将数据7打印出来
		"hello",内部输入4，则应该返回&o，外部将数据'o'打印出来
	注意，该函数写好之后不能改变
*/

#include<stdio.h>

void* func(void* arr,int size){
	int pos = 0;
	printf("请输入下标位置:");
	scanf("%d",&pos);
	while(getchar()!=10);
	return (char*)arr+pos*size;
}

/*
	在做通用化设计的时候，通常参数都会选取void*来接受任意类型的指针。
	void*指针在偏移的时候，一定要配合传入一个原本数据的内存大小来使用
*/

int main(){
	int arr[5] = {1,3,5,7,9};
	char str[6] = "world";
	double drr[5] = {1.6,2.1,3.5,4.3,5.7};
	char* ptr[5] = {"你好","中国","1908","上海","海同"};
	void* data = func(ptr,8);
	printf("%s\n",*(char**)data);
	//printf("%g\n",*(double*)data);
	return 0;
}
