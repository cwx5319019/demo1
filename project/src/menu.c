#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"menu.h"

void printIndex(){
	system("clear");
	printf("\n****************欢迎进入中国福利彩票中心*********************\n\n");
	printf("                1：   注   册   用   户\n");
	printf("                2：   登   录   帐   号\n");
	printf("                0：   退   出   程   序\n");
	printf("请选择：");
}


void printRegister(){
	system("clear");
	printf("\n*************************用户注册******************************\n\n");
	printf("\n请输入要注册的用户名：");
}


void printLogin(){
	system("clear");
	printf("\n*************************登录页面******************************\n\n");
	printf("请输入登录账号：");
}


void printUser(){
	system("clear");
	printf("********************欢迎进入用户界面*************************\n\n");
	printf("                1：   查 看 个 人 信 息\n");
	printf("                2：   修 改 个 人 密 码\n");
	printf("                3：   注 销 个 人 信 息\n");
	printf("                4：   充          值\n");
	printf("                5：   查 询 中 奖 记 录\n");
	printf("                6：   买          票\n");
	printf("                7：   查 询 购 票 记 录\n");
	printf("                8：   扫  雷  游  戏\n");
	printf("                0：   退  出  登  录\n");
	printf("请选择：");
}


void printAdmin(){
	system("clear");
	printf("*******************欢迎进入管理员界面************************\n\n");
	printf("                1：   发  行  彩  票\n");
	printf("                2：   按 用 户 帐 号 查 询\n");
	printf("                3：   按 用 户 余 额 排 序\n");
	printf("                0：   退  出  登  录\n");
	printf("请选择：");
}


void printWorker(){
	system("clear");
	printf("*******************欢迎进入公正员界面************************\n\n");
	printf("                1：   开          奖\n");
	printf("                2：   查 看 历 史 发 行\n");
	printf("                0：   退  出  登  录\n");
	printf("请选择：");
}


void backLast(){
	while(1){
		char c=0;
		printf("\n返回上一级（是Y/y;否N/n）:");
		scanf("%c",&c);
		while(getchar()!=10);
		if(c=='Y' || c=='y'){
			break;
		}else if(c!='N' && c!='n'){
			printf("\n请输入正确的编号！\n");
		}
	}
}


void backToLast(){
	printf("\n正在返回上一级...");
	fflush(stdout);
	sleep(2);
}


void fresh(){
	printf("\n正在刷新界面...");
	fflush(stdout);
	usleep(1500000);
}
