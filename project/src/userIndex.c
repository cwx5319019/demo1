#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"userIndex.h"
#include"menu.h"
#include"userOp.h"
#include"lotteryOp.h"
#include"myLotteryOp.h"
#include"mineSweeper.h"

//用户界面
void userIndex(user_t* userHead,lott_t* lottHead,mylott_t* myLottHead,char* name){
	while(1){
		printUser();
		int ch=-1,res=0;
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				lookUser(userHead,name);//查看个人信息
				break;
			case 2:
				updatePwd(userHead,name);//修改个人密码
				break;
			case 3:
				res=deleteUser(userHead,myLottHead,name);//注销个人帐号
				if(res==1){
					return;
				}
				break;
			case 4:
				updateCash(userHead,name);//充值
				break;
			case 5:
				lookMyPrize(myLottHead,name);//查看个人中奖情况
				break;
			case 6:
				buyLott(userHead,lottHead,myLottHead,name);//买票
				break;
			case 7:
				lookMyLott(myLottHead,name);//查看个人购票历史
				break;
			case 8:
				mineSweeper();//扫雷游戏
				break;
			case 0:
				return;//退出程序
			default:
				printf("\n请输入正确的编号！\n");
				fresh();
				break;
		}
	}
}
