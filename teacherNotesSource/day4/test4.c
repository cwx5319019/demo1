/*
	使用3种方法，交换两个变量的值
		① 中间变量法
		② 算数运算法
		③ 位运算法(按位异或)
*/
#include<stdio.h>

int main(){
	int a = 5,b = 10;
	int* pa = &a;
/*
	int temp = a;
	a = b;
	b = temp;
*/
/*
	a = a + a;
	a = a - a;
	a = a - a;
*/
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
/*
	这里有2个地方需要注意的：
		①使用第三方变量法，效率最低，但是最稳定
		使用算数运算符或者按位异或的方法做变量交换的话，一定注意参与交换的两个数据不能是同一个数据
		②效率最高的位运算符，因为即使是算数运算符的操作，他最终还是会转换成位运算符去实现(算数运算符的底层就是依靠位运算符实现的)
*/
	printf("a = %d,b = %d\n",a,b);
	return 0;
}
