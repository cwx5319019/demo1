/*
	define undef 使用undef下面的不再使用PI

*/
#include <stdio.h>
#include <math.h>
#define R 6371
#define PI 3.14
//宏定义‘\’可以换行看起来代码更好看
#define MAX(x,y) \
			(((x) > (y)) ? (x) : (y))

int main(void)
{
	
	int r;
	float s;
	printf("请输入半径：");
	scanf("%d",&r);

// #undef PI

	s = PI * r * r ;
	printf("圆的面积是：%.2f\n",s);

	//带变量宏的使用
	int x = 5;
	int y = 10;
	printf("最大数是：%d\n",MAX(x,y));

	return 0;
}
