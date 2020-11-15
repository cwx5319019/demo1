/* 
	define 的使用
	sizeof 运算符号
	signed unsigned 有无符号

*/


#include <stdio.h>
#define URL "http://www.fishc.com"
#define NAME "曹宇"
#define YEAR "20201114"

int main(void)
{
	printf("URL = %s,NAMR = %s,YEAR = %s\n",URL,NAME,YEAR);
	

	char str[10] = {1,2,3,4,5,6,7,8,9,10};
	char *ptr = "hello";
	printf("%d\n",*(str+1));
    
	//sizeof()
	printf("size of void is %d\n ", sizeof(void));
	printf("size of char is %d\n ", sizeof(char));
	printf("size of int is %d\n ", sizeof(int));
	printf("size of float is %d\n ", sizeof(float));
	printf("size of double is %d\n ", sizeof(double));
	printf("size of _Bool is %d\n ", sizeof(_Bool));
	printf("size of long double is %d\n ", sizeof(long double));
	
	//short int  int可以省略
	short i;
	unsigned short j;
	i = -1;
	j = -1;
	printf("%d\n",i);
	printf("%u\n",j);  //%u 打印无符号数据

	return 0;
}
