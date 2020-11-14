#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"adminIndex.h"
#include"limitIO.h"
#include"menu.h"
#include"userOp.h"
#include"lotteryOp.h"

//管理员界面
void adminIndex(user_t* userHead,lott_t* lottHead){
	while(1){
		printAdmin();//管理员界面菜单
		int ch=-1;
		scanf("%d",&ch);
		while(getchar()!=10);

		switch(ch){
			case 1:
				insertLott(lottHead);//发行彩票
				break;

			case 2:
				queryUser(userHead);//查询用户
				break;

			case 3:
				sort(userHead);//按余额冒泡降序排序
				break;

			case 0:
				return;//退出登录

			default:
				printf("\n输入的编号无效！\n");
				fresh();//短暂睡眠自动刷新当前界面
				break;
		}
	}
}
