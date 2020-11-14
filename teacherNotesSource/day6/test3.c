/*
	封装函数，实现功能，该函数会自动统计自身被调用的次数。
	然后在主函数中，调用该函数若干次之后，打印出该函数被调用的次数
*/

#include<stdio.h>

void func(int* pcount){
	(*pcount)++;
}

int main(){
	int count = 0;
	func(&count);
	printf("函数总共调用了%d次\n",count);
	return 0;
}
/*
	这样的一个函数记数功能，在之后的学习当中会经常被使用：
		假设 系统中存在一个容器，当调用insert函数的时候，会通过某种逻辑，向该容器中，添加一个数据。当调用remove函数的时候，同样会通过某种逻辑，从该容器中移除一个数据。
		所以，当调用insert的时候，记数变量count++，remove的时候记数变量count--
*/
