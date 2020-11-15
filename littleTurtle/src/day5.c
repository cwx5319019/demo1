/*
	字符串数组：要有结束符'\0'
	字符串常量：会默认添加'\0'


*/
#include <stdio.h>
int main()
{
	char str[] = {'c','l','y','q','q','\0'};
	char *ptr = "clyqq";

	printf("%s\n",str);
	printf("hello\n");

	return 0;
}
