/*
	编译并且执行 gcc day2.c -o day2 && ./day2 
	%d %c %11.2f %g 的使用 %u 打印无符号数据
 
*/


#include <stdio.h>

int main()
{

	int a;
	char b;
	float c;
	double d;

	a = 520;
	b = 'F';
	c = 3.14;
	d = 3.141592653;
	
	printf("%d\n",a);
	printf("%c\n",b);
	printf("%.2f\n",c);   //%g 
	printf("%11.9f\n",d);//11这个数据的宽度

	return 0;
}
