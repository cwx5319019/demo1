#ifndef USER_LINK_H_
#define USER_LINK_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h> 
#include<termios.h>
#include<assert.h>
#include<time.h>
#include"user_lottery.h"
typedef struct Data{ //用户名链表
	char name[20];
	char pwd[20];
	double balance;
}data_t;

typedef struct User{
	data_t data;
	//struct User* prev;
	struct User* next; 
}user_t;

//获得字符  
char getch();

//获取字符串
void getstring(char* str,int len);

//请屏
void clear();

//密码隐藏 获得合法字符
void get_pwd(char* str);

//密码隐藏 获得合法字符
void get_pwd(char* str);

//初始化链表，创建头节点 
user_t* init_user_head();

//用户注册
void insert_user_node(user_t* head_user);

//登录
int login(user_t* head,char* ptr);

//管理员查询
void admin_find_user(user_t* head_user);

//查询个人信息  返回p
user_t* find_user(user_t* head_user,char* ptr);

//打印个人信息
void print_user(user_t* head_user,char* ptr);

//修改密码
int updata_user_code(user_t* head_user,char* ptr);



//充值
void recharge_user(user_t* head_user,char* ptr);

//打印全部注册人员的信息
void print(user_t* head);

//按照用户余额排序
void bubble_user(user_t* head_user);

//保存用户名和密码
void save_user(user_t* head);

//载入用户名和密码
void load_user(user_t* head);

//释放user的堆空间
void free_user(user_t* head_user);

//验证码
int identify_code(void);


#endif








































































