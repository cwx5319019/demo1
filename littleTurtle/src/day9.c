#include <stdio.h>
#include <string.h>

union data
{
	int i ;
	double x; float f;

};
int main(void)
{
	union data s;
	printf("%d\n",sizeof(s));
	
	return 0;
}
