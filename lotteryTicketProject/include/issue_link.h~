#ifndef ISSUE_LINK_H_
#define ISSUE_LINK_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h> 
#include<termios.h>
#include<assert.h>
#include<time.h>
#include"user_link.h" //引用getch
#include"user_lottery.h"
typedef struct Data_iss{ //每期彩票链表
	int date;
	double price;  
	char state[20]; // 开奖状态
	int num[20]; //号码
	int total;
	double pool;  //奖池余额
	double pool_1; //奖池金额
}data_iss_t;

typedef struct issue_link{
	data_iss_t data;
	struct issue_link* next;
}iss_t;

//初始化每期彩票链表堆空间
iss_t* init_head();

// 管理员发行彩票
void issue_link(iss_t* head_iss);

//保存每期彩票链表
void save_iss(iss_t* head_iss);

//加载每期彩票链表
void load_iss(iss_t* head_iss);

//释放每期彩票链表堆空间
void free_iss(iss_t* head_iss);

//打印每期彩票链表
void print_iss_link(iss_t* head_iss);

//公证员界面控制
//void worker_view_contronal(iss_t* head_iss,lot_t* head_lot);
#endif





















