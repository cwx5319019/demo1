#include<stdio.h>

int func(int n){
	int i = 0;
	int res = 0;
	for(i=0;i<=n;i++){
		res = res + i;
	}
	return res;//任何函数，一旦遇到return，函数将会直接结束，并且将return后面的数据赋值给 函数的表达式
}

int main(){
	int num = 0;
	scanf("%d",&num);
	while(getchar()!=10);
	int res = func(num);
	int ret = printf("res = %d\n",res);
	printf("ret = %d\n",ret);
	return 0;
}
