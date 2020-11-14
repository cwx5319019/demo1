#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"menu.h"
#include"userOp.h"
#include"lotteryOp.h"
#include"myLotteryOp.h"
#include"login.h"


int main(){
	user_t* userHead=initUser();//初始化用户
	lott_t* lottHead=initLott();//初始化彩票
	mylott_t* myLottHead=initMyLott();//初始化个人彩票

	loadUser(userHead);//加载用户
	loadLott(lottHead);//加载彩票
	loadMyLott(myLottHead);//加载个人彩票

	while(1){
		printIndex();//首页菜单
		int ch=-1;
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				insertUser(userHead);//注册
				break;
			case 2:
				login(userHead,lottHead,myLottHead);//登录
				break;
			case 0:
				printf("\n*************感觉你对我们的支持，欢迎你再来******************\n\n");
				quitMain(userHead,lottHead,myLottHead);//退出程序
				return 0;
			default:
				printf("\n请输入正确的编号！\n");
				fresh();
		}
	}
	return 0;
}
