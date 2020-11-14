#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include"limitIO.h"
#include"login.h"
#include"menu.h"
#include"userOp.h"
#include"lotteryOp.h"
#include"myLotteryOp.h"
#include"userIndex.h"
#include"adminIndex.h"
#include"workerIndex.h"


//获取随机验证码（一位大写字母，一位小写字母和两位数字）
void getCode(char* code){
	srand(time(0));
	code[0]=rand()%26+65;
	code[1]=rand()%26+97;
	code[2]=rand()%10+48;
	code[3]=rand()%10+48;
}


//用户登录
void login(user_t* userHead,lott_t* lottHead,mylott_t* myLottHead){
	char name[20]={0},pwd[20]={0};
	int nCount=0;//帐号输错的次数
	int pCount=0;//密码输错的次数
	while(nCount<3){
		printLogin();//登录界面菜单
		limitNamePwd(name,1);//限制输入字母和数字，1表示可见
		if(strlen(name)==0){
			printf("\n登录用户名不能为空！\n");
			nCount++;
			fresh();//短暂睡眠自动刷新当前界面
			if(nCount==3){
				printf("\n用户名已错3次\n");
				backToLast();//短暂睡眠自动返回上一级
			}
			continue;

		}else if(strcmp(name,"admin")==0){
			while(pCount<3){
				printf("\n请输入管理员密码：");
				limitNamePwd(pwd,2);//限制输入字母和数字，2表示不可见
				if(strcmp(pwd,"12345")==0){
					adminIndex(userHead,lottHead);//进入管理员界面
					return;
				}else{
					printf("\n管理员密码错误！\n");
					pCount++;
				}
			}

		}else if(strcmp(name,"worker")==0){
			while(pCount<3){
				printf("\n请输入公证员密码：");
				limitNamePwd(pwd,2);
				if(strcmp(pwd,"12345")==0){
					workerIndex(userHead,lottHead,myLottHead);//进入公证员界面
					return;
				}else{
					printf("\n公证员密码错误！\n");
					pCount++;
				}
			}

		}else if(findUser(userHead,name)==NULL){
			printf("\n用户名不存在！\n");
			nCount++;
			fresh();
			if(nCount==3){
				printf("\n用户名已错3次\n");
				backToLast();
			}

		}else{
			while(pCount<3){
				printf("\n请输入登录密码：");
				limitNamePwd(pwd,2);
				if(strcmp(findUser(userHead,name)->pwd,pwd)==0){
					char myCode[5]={0},code[5]={0};
					getCode(code);//获取验证码
					printf("\n请输入验证码：%s\n",code);
					scanf("%s",myCode);
					while(getchar()!=10);
					if(strcmp(myCode,code)==0){
						userIndex(userHead,lottHead,myLottHead,name);//进入用户界面
						return;
					}else{
						printf("\n验证码错误！需重新输入登录密码\n");
						pCount++;
					}
				}else{
					printf("\n密码错误！\n");
					pCount++;
				}
			}
		}

		if(pCount==3){
			printf("\n密码已错3次\n");
			backToLast();
			break;
		}
	}
}
