#include<stdio.h>

/*
	在终端上输出一个 5行5列的由"* "组成的正方形
*/
/*
     *		0	1		
    * *		1	2
   * * *	2	3
  * * * *	3	4
 * * * * *	4	5
*/
int main(){
	int i = 0,j = 0;
	for(j=0;j<5;j++){
		for(i=0;i<5-j;i++){
			printf(" ");
		}
		for(i=0;i<j+1;i++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
