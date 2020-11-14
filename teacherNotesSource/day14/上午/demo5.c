#include<stdio.h>

enum Type{
	a=5,//默认从0开始
	b,
	c,
	d
};

int main(){
	enum Type type = b;
	printf("type = %d\n",type);
	return 0;
}
