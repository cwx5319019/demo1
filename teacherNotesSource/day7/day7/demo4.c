#include<stdio.h>

void insert(int* count){
	(*count)++;
}

void Remove(int* count){
	(*count)--;
}

void _insert(){
	static int count = 0;
	count++;
	printf("insert:%d\n",count);
}

void _Remove(){
	static int count = 0;
	count--;
	printf("remove:%d\n",count);
}

int main(){
	int count = 0;
/*	insert(&count);
	insert(&count);
	insert(&count);
	insert(&count);
	insert(&count);
	Remove(&count);
	Remove(&count);*/
	_insert();
	_insert();
	_insert();
	_Remove();
	_Remove();
	printf("容器中还有%d个数据\n",count);
	return 0;
}
