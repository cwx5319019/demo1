#include<stdio.h>

int main(){
	char str[20] = {'h','e','l','l','o'};//字符数组
	char str2[20] = "world";//字符数组
	char str3[20] = "hello world";//字符串
	str2[0] = 'W';
	//str3[0] = 'H';
	char* str4 = str2;
	//str4[0] = 'h';

	//printf("str2 = %s\n",str2);
	int i = 0;
	for(i=0;str2[i]!=0;i++){
		printf("%c",str2[i]);
	}//遍历字符数组的时候只能使用这种方式
	printf("\n");
	return 0;
}
