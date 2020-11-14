#include<stdio.h>
#include<math.h>
int main(void)
{
	double a = (double) 10/3;
	printf("%lf\n",a);
	double a = 10/3;
	printf("%lf\n",a);    //注意两者的区别
	
	int x = 1010;
	printf("%d \n",x);//进制转化
		
	int x,y ;
	printf("please input two number:");
	scanf("%d%d",&x,&y);
	printf("x:%d y:%d\n",x,y);

	double t = 12;
	scanf("%lf",&t);
	printf("t:%lf\n",t);

	char str = 'A';  //定义字符型
	printf("str:%c\n",str+1);


	int a = 123;
	printf("%10d\n",a); //10宽度

	double p = 3.14;
	printf("%6.2lf\n",p); //6是宽度  lf默认精度6位
	
	//大小字母转化
	char x = 'a';
	printf("please input a char:");
	scanf("%c",&x);
	if ( x >= 'a' && x <= 'z'){
		x = x - 32;
		printf("%c\n",x);
	}else {
		x = x + 32;
		printf("%c\n",x);
	}
		
	//平方
	int x = 2, s = 1;
	printf("please input a number:");
	scanf("%d",&x);
	//s = x * x;
	s = pow(x,2);
	printf("%d\n",s);

	return 0 ;
}




















