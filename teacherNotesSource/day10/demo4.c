#include<stdio.h>
#include<user.h>

int main(){
	printf("请输入字符串:");
	char str[20] = {0};
	getstring(str,20);
	printf("str = %s\n",str);
	return 0;
}
