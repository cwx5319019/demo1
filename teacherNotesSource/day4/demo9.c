#include<stdio.h>

int main(){
	//chmod u+r demo.c
	int u = 0;
	//打开可读权限
	u = u|4;
	printf("u = %d\n",u);

	//打开可写权限
	u = u|2;
	printf("u = %d\n",u);

	//打开可执行权限
	u = u|1;
	printf("u = %d\n",u);

	u = u|4;
	printf("u = %d\n",u);

	u = u&~4;
	printf("u = %d\n",u);

	u = u&~2;
	printf("u = %d\n",u);

	u = u&~1;
	printf("u = %d\n",u);

	u = u&~4;
	printf("u = %d\n",u);
	return 0;
}
