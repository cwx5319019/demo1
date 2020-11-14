#include<stdio.h>

double add(double a,double b){
	return a + b;
}

double sub(double a,double b){
	return a - b;
}

double mul(double a,double b){
	return a * b;
}

double div(double a,double b){
	return a / b;
}

typedef double (*cal_t)(double,double);

int main(){
	double a = 0,b = 0;
	char ch = 0;
	cal_t cal[4] = {add,sub,mul,div};
	while(1){
		printf("请输入表达式:");
		scanf("%lf %c %lf",&a,&ch,&b);
		while(getchar()!=10);
		int pos = (ch=='+') + (ch=='-')*2 + (ch=='*')*3 + (ch=='/')*4-1;
		printf("%g %c %g = %g\n",a,ch,b,cal[pos](a,b));
	}
	return 0;
}
