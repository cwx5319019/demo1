/*
	比特位 byte 
	字节  bit   
	1bit = 8 byte

    signed int 的取值范围 pow()取几次方函数
    unsigned int 的取值范围 
	
	long long int 范围
	-9223372036854775808 ～ 922 3372 0368 5477 5807
                            922京 3372zhao  0368亿 5447万 
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int max_signed = pow(2,31)-1;
	int min_signed = -pow(2,31);
	printf(" %d <= int_signed <=  %d\n",min_signed,max_signed);

	unsigned int max_un = pow(2,32)-1;
    unsigned int min_un = 0;
	printf(" %d <= int_un <=  %u\n",min_un,max_un);//注意这里使用%u 不能用%d

	return 0;
}
