/*
	从键盘输入2个数，使用循环求出这两个数的最大公约数和最小公倍数
*/
#include<stdio.h>

int main(){
	int a = 0,b = 0;
	scanf("%d %d",&a,&b);
	while(getchar()!=10);
	int smaller = (a<b)?a:b;
	int i = 0;
/*
	for(i=smaller;1;i--){
		if(a%i==0 && b%i==0){break;}
	}
*/
	for(i=smaller;a%i!=0 || b%i!=0;i--);
	printf("%d 和 %d 的最大公约数为 :%d\n",a,b,i);

	int bigger = (a>b)?a:b;
/*
	for(i=bigger;1;i++){
		if(i%a==0 && i%b==0){break;}
	}
*/
	for(i=bigger;i%a!=0 || i%b!=0;i++);
	printf("%d 和 %d 的最小公倍数为 :%d\n",a,b,i);
	return 0;
}
