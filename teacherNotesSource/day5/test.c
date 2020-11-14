#include<stdio.h>

int main(){
	int ch = 0;
	while(1){
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				printf("一\n");
				break;
			case 2:
				printf("二\n");
				break;
			default:
				printf("错误\n");
				break;
		}
	}
	return 0;
}
