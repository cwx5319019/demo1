#include<stdio.h>

/*
	键盘输入一个十进制数，将他转换成二进制输出
*/

int main(){
	int num = 0;
	scanf("%d",&num);
	while(getchar()!=10);
	//10
	int i = 0;
	//10%2=	0
	//5%2=	1
	//2%2=	0
	//1%2=	1
	int j = 0;
	int res = 0;
	int temp = 1;
	//0+1*0
	//1+10*1
	//10+100*0
	//10+1000*1
	for(i=num;i>0;i/=2){
		res = res + temp * (i%2);
		temp = temp*10;
	}
	printf("res = %d\n",res);
	return 0;
}
