/*
	封装一个函数，函数功能，判断导入的参数是否为质数。
	然后在主函数中，调用该函数实现功能，计算1~100之中，所有质数的和
*/
#include<stdio.h>

int func(int num){
	int i = 0;
	int count = 0;
	for(i=1;i<=num;i++){
		if(num%i==0){
			count++;
		}
	}
	return (count==2)?num:0;
}

int main(){
	int i = 0;
	int res = 0;
	//int ret = 0;
	for(i=1;i<=100;i++){
		res = res + func(i);
	}
	printf("res = %d\n",res);
	return 0;
}
