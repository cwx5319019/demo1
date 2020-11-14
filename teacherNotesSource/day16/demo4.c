#include<stdio.h>

int main(){
	FILE* fp = fopen("./test2.txt","w");
	fputs("hello world",fp);
	fclose(fp);
	return 0;
}
