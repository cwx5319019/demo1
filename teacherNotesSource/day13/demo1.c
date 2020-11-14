#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert_data(int** arr,int* vol,int* len){
	int data = 0;
	if(*len >= *vol){
		printf("开始扩容\n");
		*vol *= 2;
		int* brr = malloc(4 * *vol);
		memset(brr,0,4 * *vol);
		//int* brr = calloc(*vol,4);
		//*arr = realloc(*arr,*vol);
		memcpy(brr,*arr,*len*4);
		free(*arr);
		*arr = brr;
		printf("brr = %p\n",brr);
	}
//	printf("请输入数据:");
//	scanf("%d",&data);
	data = *len+1;
//	while(getchar()!=10);
	(*arr)[*len] = data;
	(*len)++;
}

int main(){
	int vol = 5;
	int len = 0;
	int ch = 0;
	int* arr = malloc(sizeof(int)*vol);
	memset(arr,0,sizeof(int)*vol);
	printf("arr = %p\n",arr);
	while(1){
		printf("1:添加数据\n");
		printf("2:打印数据\n");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				insert_data(&arr,&vol,&len);
				break;
			case 2:
				printf("prr = %p\n",arr);
				break;
			default:
				break;
		}
	}
	return 0;
}
