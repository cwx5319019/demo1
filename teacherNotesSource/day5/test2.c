/*
	使用switch case编写一个简易的+,-,*,/,%计算器
	普通要求：输入 a 运算符 b,在终端上显示 a 运算符 b = 运算结果
	进阶要求：使用while(1)将整个计算器逻辑嵌套，整个计算逻辑无限循环，直到按q退出,只q就能退出
*/

#include<stdio.h>

int main(){
	double a = 0,b = 0;
	double res = 0;
	char c = 0;
	while(1){
		printf("请输入计算表达式:");
		scanf("%lf",&a);
		scanf("%c",&c);
		if(c=='q'){
			return 0;
		}else if(c=='+'||c=='-'||c=='/'||c=='*'||c=='%'){
			scanf("%lf",&b);
		}
		while(getchar()!=10);
		switch(c){
			case '+':
				res = a + b;
				break;
			case '-':
				res = a - b;
				break;
			case '*':
				res = a * b;
				break;
			case '/':
				if(b==0){res=0;break;}
				res = a / b;
				break;
			case '%':
				if(b==0){res=0;break;}	
				res = (int)a % (int)b;	
				break;
			default:
				break;
		}
		if(c=='+'||c=='-'||c=='/'||c=='*'||c=='%'){
			printf("%g %c %g = %g\n",a,c,b,res);
		}
	}
	return 0;
}
