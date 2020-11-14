/*
	1:使用递归解决猴子吃桃的问题
	2:使用递归解决 1/1-1/3+1/5-1/7+...-1/99+1/101
	3:使用递归解决斐波那契数列第n项值的问题
*/
#include<stdio.h>

int f1(int n){
	if(n==1){return 1;}
	return (f1(n-1)+1)*2;
}

double f2(int n){
	if(n==1){return 1.0;}
	return f2(n-2) + 1.0/n * ((n/2%2==0)?1:(-1));
}

int f3(int n){
	if(n==1||n==2){return 1;}
	return f3(n-2) + f3(n-1);
}

int main(){
	printf("%d\n",f4(1));

	printf("%d\n",f4(1));
	return 0;
}
