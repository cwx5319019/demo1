#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char buf[1024] = "";
	FILE* fp;
	if((fp = fopen("lines.txt","r")) == NULL)
	{
		printf("haha");
		exit(0);
	}
	while(1)
	{
		fgets(buf,1024,fp);
		if(feof(fp) == 1)
		{
			break;
		}
		printf("%s",buf);
	}

	return 0;
}
