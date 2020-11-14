#include<stdio.h>

int main(){
/*
	int a = 2,b = 3;
	a*=	a++ + 	b++ + 	a++;
	//4*=	2		3		3 a = 32
	b+=	a++ + 	b +	 b++;
	//5+=	32 +	4 + 4
	printf("a = %d,b = %d\n",a,b);
*/
	int a = 2,b = 3,c = 4,d = 5, e = 6;
	a+=5*=c-=d%=e/=2;
	return 0;
}
