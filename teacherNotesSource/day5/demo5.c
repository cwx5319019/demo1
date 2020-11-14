/*
	使用循环，求出char数据类型的取值范围
*/
#include<stdio.h>

int main(){
	char a = 0;
	//char b = a+1;
	while(a<(char)(a+1)){
		a++;
		//b++;
	}
	printf("最大值为%d,最小值为%d\n",a,(char)(a+1));
	return 0;
}
