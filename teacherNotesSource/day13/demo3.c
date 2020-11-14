#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int* pa = malloc(4);
	memset(pa,0,4);
	pa = realloc(pa,40);
	free(pa);
	return 0;
}
