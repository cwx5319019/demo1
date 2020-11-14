#include<stdio.h>
/*
	从键盘输入3个随机数，然后按照从小到大的方式依次输出
*/
int main(){
	int a = 0,b = 0,c = 0;
	printf("请输入要比较的3个数的大小:");
	scanf("%d %d %d",&a,&b,&c);
	while(getchar()!=10);
	int smaller = (a<b)?a:b;
	int min = (smaller<c)?smaller:c;

	int bigger = (a>b)?a:b;
	int max = (bigger>c)?bigger:c;

	int mid = a + b + c - max - min;
	printf("%d %d %d\n",min,mid,max);
	return 0;
}
