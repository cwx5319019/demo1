#include<stdio.h>
/*
	斐波那契数列：前两项是1，从第3项开始，每一项都是前两项之和
*/
/*
			1	1	2	3	5	8	13
第一次循环	n1	n2	n3
第二次循环		n1	n2	n3
第三次循环			n1	n2	n3
*/
int main(){
	int i = 0;
	int n = 0;
	int n1 = 1,n2 = 1;
	int n3 = 1;
	scanf("%d",&n);
	while(getchar()!=10);
	for(i=3;i<=n;i++){
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	printf("第%d项的值为%d\n",n,n3);
	return 0;
}
