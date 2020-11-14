/*
	输出1到10000之内所有的完数
	什么是完数: 除去本身之外的所有约数之和等于本身
	例如：6就是完数，6的约数1,2,3,6,除去本身之后就是1,2,3,1+2+3==6
*/
#include<stdio.h>

int main(){
	int i = 0,j = 0;
	int res = 0;
	for(i=1;i<=10000;i++){
		res = 0;
		for(j=1;j<i;j++){
			if(i%j==0){
				res = res + j;	
			}
		}
		if(res == i){
			printf("%d\n",i);
		}
	}
	return 0;
}
