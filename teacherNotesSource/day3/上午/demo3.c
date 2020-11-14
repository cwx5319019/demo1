#include<stdio.h>

int main(){
	int a = 5;//这里的等号是一个赋值运算符，他的含义为：读取数据5，然后将他写入到a所代表的内存空间上
	a = 20;
	//如何在printf中输出一个变量的值
	//printf("a的值为:%d\n",a);
	
	scanf("%d",&a);
	printf("a = %d\n",a);
	return 0;
}
