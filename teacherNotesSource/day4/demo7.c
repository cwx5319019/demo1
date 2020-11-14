#include<stdio.h>

int main(){
	int a = 1,b = 1;
	printf("%d\n",a++);//1
	printf("%d\n",++b);//2
	printf("%d\n",a);//2
	printf("%d\n",b);//2
	return 0;
}
