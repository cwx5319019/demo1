#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	//想要在对空间上申请一段内存空间，这段内存空间能够存储整型数据
//	int* pa = malloc(4*10);
//	memset(pa,0,40);
	int* pa = calloc(10,4);
/*
	int i = 0;
	for(i=0;i<10;i++){
		pa[i] = i*10;
	}

	for(i=0;i<10;i++){
		printf("pa[%d] = %d\n",i,pa[i]);
	}
*/
	printf("%d\n",pa[0]);
	free(pa);
	return 0;
}
