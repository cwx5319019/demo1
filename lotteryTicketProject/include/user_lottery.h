#ifndef USER_LOTTERY_H_
#define USER_LOTTERY_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h> 
#include<termios.h>
#include<assert.h>
#include"issue_link.h"
typedef struct Data_lot{ //个人彩票链表
	int date;  //期数
	int id;     //彩票id
	int num[20]; //号码
	char name[20];//用户
	int amount; //注数
	double custom;//花费
	int grade;  //等级
	double balance; // 金额
}data_lot_t;

typedef struct Lottery{
	data_lot_t data;
	struct Lottery* next;
}lot_t;

lot_t* init_lot_head();

//注销彩票链表
void delete_lot(lot_t* head_lot,char* ptr);

//查询个人购票记录 //查询中奖情况
void head_purchase(); //定义的不一样的地方
void head_draw();
void recode_draw(lot_t* p);
void recode_purchase(lot_t* p);

void find_lot(lot_t* head_lot,char* ptr,void (* recode)(lot_t*),void (* head)());

//查询所有用户购票记录
void lot_print(lot_t* head_lot);

//释放彩票链表堆空间
void free_lot(lot_t* head_lot);

//保存个人彩票数据
void save_lot_data(lot_t* head_lot);

//加载个人彩票数据
void load_lot_data(lot_t* head_lot);











































































#endif
