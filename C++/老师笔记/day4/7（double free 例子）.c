#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Test{
	char* p;
}T;

int main(void){
	T t1;
	t1.p = (char*)malloc(100);
	memset(t1.p,0,100);
	printf("t1地址：%p\n",t1.p);
	strcpy(t1.p,"hello rose\n");
	printf("t1 = %s\n",t1.p);
	
	T t2;
	t2 = t1;
	printf("t2地址：%p\n",t2.p);
	printf("t2 = %s\n",t2.p);
	if(t1.p != NULL){
		free(t1.p);
	}
	if(t2.p != NULL){
		free(t2.p);
	}
	
	
	return 0;
}

