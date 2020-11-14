#include<stdio.h>

int main(){
	char ch = 0;
	printf("请输入分支:");
	scanf("%c",&ch);
	while(getchar()!=10);
	switch(ch){
		case '1':{
			int a = 5;
			printf("分支1\n");
			break;
		}
		case '2':
			printf("分支2\n");
			break;
		case '3':
			printf("分支3\n");
			break;
		default:
			printf("输入错误\n");
			break;
	}
	return 0;
}
