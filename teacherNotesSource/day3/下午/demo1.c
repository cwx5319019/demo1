#include<stdio.h>

int main(){
	char a = 400;//127+256=383,400-383 = 17,-128+16
	unsigned char b = 500;//1111 1111 -> 2^8-1 = 256-1 = 255
	//500-255 = 245,0+244
	printf("%d\n",a);
	printf("%d\n",b);
	return 0;
}
