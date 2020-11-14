#include<stdio.h>

double func(double num,int n){//12.3456 2
	int i = 0;
	for(i=0;i<n;i++){
		num*=10;
	}
	//num = 1234.46
	int temp = num + 0.5;
	num = temp;
	for(i=0;i<n;i++){
		num/=10;
	}
	return num;
}

int main(){
	double num = 0;
	int n = 0;
	scanf("%lf %d",&num,&n);
	while(getchar()!=10);
	num = func(num,n);
	printf("num = %g\n",num);
	return 0;
}
