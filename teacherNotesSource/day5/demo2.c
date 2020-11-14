#include<stdio.h>

int main(){
	int i = 1;
	int res = 0;
	/*while(i<10){
		printf(" * \n");
		i++;
	}*/
	while(i<101){
		res = res + i;
		i++;
	}
	printf("res = %d\n",res);
	return 0;
}
