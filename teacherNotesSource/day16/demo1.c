#include<stdio.h>

int main(){
	char str[20] = "123hello";
	char ptr[20] = {0};
	int data = 0;
	//sscanf(str,"%d",&data);
	sprintf(ptr,"%s",str);
	printf("ptr = %s\n",ptr);
	return 0;
}
