#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<assert.h>
#include<string.h>
#include"limitIO.h"

/* 通过termios结构体的c_lflag成员控制终端编辑，关闭终端标准输入和回显功能，再获取键盘输入字符，将该字符返回，交由其他函数进行下一步判断和引用 */
char getch(){
	char c=0;
	//定义两个termios结构体变量，用于保存，设置和还原终端的参数设置
	struct termios orgOpts;
	struct termios newOpts;
	//获取终端参数（保存），并返回结果，0则成功，否则失败
	int res=0;
	res=tcgetattr(STDIN_FILENO,&orgOpts);
	//利用断言assert来判断获取标准输入符是否出现异常，获取成功则继续执行下面的代码，否则调用abort终止进程
	assert(res==0);
	//利用中间变量new_opts来修改原org_opts的成员c_flag终端编辑的参数，&=~是位置0的操作，即关闭（设置）
	newOpts=orgOpts;
	//关闭标准输入和回显
	newOpts.c_lflag &=~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO,TCSANOW,&newOpts);
	//获取输入字符
	c=getchar();
	//（还原设置）
	res=tcsetattr(STDIN_FILENO,TCSANOW,&orgOpts);
	assert(res==0);
	//返回输入字符
	return c;
}


/* 通过getch()获得的字符来进行判断，是否输出显示及其他操作 */

void limitNamePwd(char* str,int no){
	char c=0;
	int i=0;
	while(1){
		//获取终端输入字符
		c=getch();
		/*  输入回车，则换行，结束字符串后退出循环
			输入字母和数字，则判断是否显示真实数据，1显示真实数据，其他则显示*，再保存字符
			如果输入退格字符，则退格，将最后一个字符重写成空格再退格，如果当前字符串长度大于0,  字符串的长度需要减去1  */
		if(c==10){
			printf("\n");
			str[i]=0;
			break;
		}else if((c>47 && c<58) || (c>64 && c<91) || (c>96 && c<123)){
			if(no==1){
				printf("%c",c);
			}else{
				printf("*");
			}
			str[i++]=c;
		}else if(c==127){
			if(i>0){
				printf("\b \b");
				i--;
			}
		}
	}
}


void limitDigit(int* n){
	char c=0;
	int i=0;
	while(1){
		//获取终端输入字符
		c=getch();
		/*  输入回车，则换行，结束字符串后退出循环
			输入字符，判断是数字后再保存字符，范围0～99
			如果输入退格字符，则退格，将最后一个字符重写成空格再退格，如果当前字符总长度大于0,  需要减去1  */
		if(c==10){
			printf("\n");
			break;
		}else if(c>47 && c<58 && i<2){
			printf("%c",c);
			*n=*n*10+(int)c-48;
			if((*n)>0){
				i++;
			}
		}else if(c==127){
			if(i>0){
				printf("\b \b");
				*n=*n/10;
				i--;
			}
		}
	}
}


void limitCash(int* n){
	char c=0;
	int i=0;
	while(1){
		//获取终端输入字符
		c=getch();
		/*  输入回车，则换行，结束字符串后退出循环
			输入字符，判断是数字后再保存字符
			如果输入退格字符，则退格，将最后一个字符重写成空格再退格，如果当前字符总长度大于0,  需要减去1  */
		if(c==10){
			printf("\n");
			break;
		}else if(c>47 && c<58){
			printf("%c",c);
			*n=*n*10+(int)c-48;
			if((*n)>0){
				i++;
			}
		}else if(c==127){
			if(i>0){
				printf("\b \b");
				*n=*n/10;
				i--;
			}
		}
	}
}


void limitNum(int* n){
	char c=0;
	int i=0;
	while(1){
		//获取终端输入字符
		c=getch();
		/*  输入回车，则换行，结束字符串后退出循环
			输入字符，判断是数字后再保存字符，范围1～5
			如果输入退格字符，则退格，将最后一个字符重写成空格再退格，如果当前字符总长度大于0,  需要减去1  */
		if(c==10){
			printf("\n");
			break;
		}else if(c>48 && c<54 && i<1){
			printf("%c",c);
			*n=*n*10+(int)c-48;
			i++;
		}else if(c==127){
			if(i>0){
				printf("\b \b");
				*n=*n/10;
				i--;
			}
		}
	}
}
