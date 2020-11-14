#include<stdio.h>

int main(){
	int a = 5;
	char b = 'x';
	int* pa = &a;
	char* pb = &b;
	void* vpa = pa;
	void* vpb = pb;

	printf("%d\n",*pa);
	printf("%c\n",*pb);

	printf("%d\n",*(int*)vpa);
	printf("%c\n",*(char*)vpb);

	void* vppa = &pa;

	void** vvpa = &vpa;
	void* vvvpa = &vvpa;
/*
	使用vvvpa访问到a的值
*/
	printf("a = %d\n",*(int*)(**(void***)vvvpa));
	return 0;
}
