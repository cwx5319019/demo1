/*
	malloc memset free 使用


*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int *ptr = NULL;
	int num , i ;
	printf("请输入等待录入的个数:");
	scanf("%d",&num);
	ptr = (int*)malloc(num*sizeof(int));;
	if(ptr == NULL) {
		exit(1);
	}
	for(i = 0;i<num; i++){
		printf("请输入：");
		scanf("%d",ptr+i); // 注意这里我用的是指针片移，也可这样写&ptr[i] &(*(ptr+i))
	}
	printf("你输入的数是：");
	for(i = 0; i< num; i++){
		printf("%d",ptr[i]);
	}
	putchar('\n');
	free(ptr);

	return 0;
}
