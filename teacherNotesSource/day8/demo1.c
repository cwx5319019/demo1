#include<stdio.h>

int func(int num){
	if(num==1){return 1;}
	return func(num-1)+num;
}
/*
	func(1) = 1
	func(2) = func(2-1) + 2 = func(1) + 2 = 3
	func(3) = func(3-1) + 3 = func(2) + 3 = 6
	func(4) = func(4-1) + 4 = func(3) + 4 = 10
	func(5) = func(5-1) + 5 = func(4) + 5 = 15
*/
/*
	1+1/2+1/3+1/4+....+1/n
*/

double f2(int n){
	if(n==1){return 1.0;}
	return f2(n-1) + 1.0/n;
}

int main(){
	printf("%g\n",f2(4));
	return 0;
}
