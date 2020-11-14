#include <stdio.h>
int main(void)
{

	FILE* fp = fopen("./test.txt","w");
	fprintf(fp,"hello %d\n",123);
	fclose(fp);
	return 0;
}
