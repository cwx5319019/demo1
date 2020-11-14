#ifndef userOp_h
#define userOp_h

#include"user.h"
#include"myLottery.h"


user_t* initUser();//初始化User结构体

user_t* findUser(user_t*,char*);//按用户名查找用户

void insertUser(user_t*);//用户注册

void lookUser(user_t*,char*);//查看某一用户信息

void queryUser(user_t*);//查询用户

int deleteUser(user_t*,mylott_t*,char*);//用户注销

void updateCash(user_t*,char*);//用户充值

void updatePwd(user_t*,char*);//用户修改密码

void bubbleSort(user_t*);//按余额冒泡降序排序

void printAllUser(user_t*);//查看所有用户信息

void sort(user_t*);//排序并显示

void saveUser(user_t*);//保存用户

void loadUser(user_t*);//加载用户

void freeUser(user_t*);//释放用户

#endif
