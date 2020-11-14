/*
	分支结构：根据给定的分支，直接跳转进入满足条件的分支内部，不会像if else if那样，从头开始判断哪一个条件是正确的
	语法：switch case 语句
		switch(分支条件){
			case 分支1:
				语句1;
				break;
			case 分支2:
				语句2;
				break;
			...
			case 分支n:
				语句n;
				break;
			default:
				语句0;
				break;
		}
	分析：“分支条件”必须有一个对应的值，所以分支条件必须可读。当然通常情况下，分支条件只会是一个变量
		该语法中，系统会根据“分支条件”的值，直接跳转到与该值相等“分支”中，并执行对应语句
		如果有多个“分支”的值，与“分之条件”相等，语法错误，编译不通过
		如果没有“分支”符合条件，则走default中语句0

	注意：
		① 在switch case 语句中，case只负责转入，不负责跳出，跳出由break负责
	break:专门用来跳出分支结构和循环结构的关键字
		② 在case中，不能直接声明变量


//------------------
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

*/
