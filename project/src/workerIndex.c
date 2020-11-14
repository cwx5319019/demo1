#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include"limitIO.h"
#include"workerIndex.h"
#include"menu.h"
#include"lotteryOp.h"
#include"myLotteryOp.h"
#include"runLottery.h"

//公证员界面
void workerIndex(user_t* userHead,lott_t* lottHead,mylott_t* myLottHead){
	while(1){
		printWorker();//公证员界面菜单
		int ch=-1;
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				createPrize(userHead,lottHead,myLottHead);//开奖
				break;
			case 2:
				lookAllLott(lottHead);//查看彩票历史发行
				break;
			case 0:
				return;//退出登录
			default:
				printf("\n请输入正确的编号！\n");
				fresh();
				break;
		}
	}
}
