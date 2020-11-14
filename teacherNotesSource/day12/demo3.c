#include<stdio.h>

int f2(int data){
	return data*data;
}

int f3(int data){
	return data*data*data
}

int func(int a,int b,int (*f)(int)){
	//return a*a+b*b;
	//return a*a*a+b*b*b;
	return f(a) + f(b);
}

int main(){
	
	return 0;
}
