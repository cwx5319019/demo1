#include<stdio.h>

int main(){
	printf("hello world\b\b\033[1B");
	fflush(stdout);
	while(1);
	return 0;
}
