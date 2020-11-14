#include<stdio.h>

int main(){
	int num = 0;//123
	int flag = 1;
	while(flag){
		flag = 0;
		scanf("%d",&num);
		while(getchar()!=10);
		for(;num!=0;num/=10){
			if(num%10==3 || num%10==-3){
				flag = 1;
			}
		}
	}
	return 0;
}
