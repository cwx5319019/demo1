/*
	可变参函数：顾名思义，参数的数量可以随时改变的函数。
	printf和scanf就是两个典型的可变参函数。
	可变参函数通常情况下，第一个参数必须是固定参数，然后人为的约定，第一个参数直接或者间接的决定到底有多少个可变参。这是可变参函数的声明规则

	如何声明一个可变参函数：
		函数返回值类型 + 函数名(固定参数，...)
*/

#include<stdio.h>
#include<stdarg.h>
/*
	va_list 是一个指针变量类型，他相当于char*，因为他的模块大小是1个字节，但是是否为char*不清楚
*/

void func(int num,...){
	va_list p;
	va_start(p,num);//这个函数会将p指向可变参数的第一个参数,也就是固定参数num的下一个参数
	printf("%d\n",va_arg(p,int));//这个函数会将p当前指向参数，以基础类型为int类型取值,也就是说会准确的读取int数据所占据的4个字节内存并取值。然后再将p指向下一个可变参的地址，最后将从地址上取出来的值，返回给va_arg表达式
	printf("%d\n",va_arg(p,int));
	printf("%d\n",va_arg(p,int));
	printf("%d\n",va_arg(p,int));
	va_end(p);
}

int main(){
	func(500,400,300,200,100);
	return 0;
}
