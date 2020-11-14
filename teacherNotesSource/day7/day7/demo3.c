#include<stdio.h>


void func(){
	static int a = 0;
	a++;
	printf("%d\n",a);
}

int main(){
	for(int i=0;i<10;i++){
		func();
	}
	return 0;
}
