/*
	1-1/3+1/5-1/7+1/9-....-1/99+1/101
*/

/*
	将1-1/3+1/5-1/7...这么一组减法操作看成一组，然后所有组加起来

	申请一个循环变量，他的值为1，他会随着循环的进行，在1和-1之间反复变换
*/

#include<stdio.h>

int main(){
	int num = 0;
	scanf("%d",&num);
	while(getchar()!=10);
	int i = 0;
	int j = 1;
	double res = 0;
	for(i=1;i<=num;i+=2){
		res = res + 1.0/i*j;
		j=-j;
	}
	printf("res = %g\n",res);
	return 0;
}
