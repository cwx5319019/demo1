#include<stdio.h>

int main(){
	FILE* fp = fopen("./test1.txt","w");
	fprintf(fp,"hello world %d\n",123);
	fclose(fp);
	return 0;
}
