#include<stdio.h>

typedef struct type1{
	int a;//4
	double b;//8
	char c;//4
	int d;//4
	int e;//4
	float f;//4
	double g;//8
}type_1;

typedef struct type2{
	double a;
	short b;
	int c;
	short d;
}type_2;

typedef struct type3{
	int a[25];//12*8+8 = 96+8=104
	double b;//8
	int c[25];//12*8+8 = 104
}type_3;

int main(){
	printf("%lu\n",sizeof(type_3));
	return 0;
}
