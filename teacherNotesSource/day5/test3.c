/*
	输出1~1000之内所有的质数
	质数：只有2个约数的数才是质数，就是1和本身
*/

#include<stdio.h>

int main(){
	int i = 0,j = 0;
	//int count = 0;
	//int flag = 0;
	for(i=2;i<1001;i++){
		//flag = 0;
		for(j=2;j<i;j++){
			if(i%j==0){
				break;
			}
		}
		if(j==i){
			printf("%d\n",i);
		}
	}
	return 0;
}
