#include<stdio.h>

/*
	从键盘上输入任意整型数据，将他翻转后输出

	从键盘输入一个数，判断他是否为回文数
	12321,123321,32123,321123都是回文数，123456不是回文数
*/

int main(){
	int num = 0;
	scanf("%d",&num);
	while(getchar()!=10);
	//12345
	int i = 0;
	int res = 0;
	//0*10+5
	//5*10+4
	//54*10+3
	//543*10+2
	//5432*10+1
	for(i=num;i>0;i/=10){
		res = res*10 + i%10;
	}
	printf("res = %d\n",res);
	return 0;
}
