#include<stdio.h>

int main(){
	int a = 0;
	char b = 0;
	char c = 0;
	//scanf("%d",&a);
	//printf("a = %d\n",a);

	scanf("%c",&b);
	while(getchar()!='\n');
	printf("b = %c\n",b);

	scanf("%c",&c);
	printf("c = %c\n",c);
	return 0;
}
