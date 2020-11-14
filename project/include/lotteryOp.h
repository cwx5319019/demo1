#ifndef lotteryOp_h
#define lotteryOp_h

#include"lottery.h"


lott_t* initLott();//初始化Lottery结构体

lott_t* findLott(lott_t*,int);//按期号查找彩票

void printLastLott(lott_t*);//打印最新的彩票信息

void insertLott(lott_t*);//发布彩票

lott_t* lastLott(lott_t*);//获取最新的彩票信息

void lookAllLott(lott_t*);//查看所有彩票信息

void saveLott(lott_t*);//保存彩票

void loadLott(lott_t*);//加载彩票

void freeLott(lott_t*);//释放彩票

#endif
