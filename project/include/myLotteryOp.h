#ifndef myLotteryOp_h
#define myLotteryOp_h

#include"userOp.h"
#include"lottery.h"
#include"myLotteryOp.h"



mylott_t* initMyLott();//初始化个人彩票链表

mylott_t* lastMyLott(mylott_t*);//获取最后的个人彩票信息

void insertMyLott(user_t*,lott_t*,mylott_t*,char*,int);//添加个人彩票信息

void buyLott(user_t*,lott_t*,mylott_t*,char*);//购买彩票

void deleteMyLott(mylott_t*,char*);//删除个人彩票信息

void quickSort(int*,int,int);//对开奖号码和个人号码进行快速排序

void updateMyLott(user_t*,lott_t*,mylott_t*,int,int*);//更新个人彩票信息

void lookMyLott(mylott_t*,char*);//查看个人的历史购买信息

void lookMyPrize(mylott_t*,char*);//查看个人的中奖信息

void createPrize(user_t*,lott_t*,mylott_t*);//开奖

void saveMyLott(mylott_t*);//保存个人彩票

void loadMyLott(mylott_t*);//加载个人彩票

void freeMyLott(mylott_t*);//释放个人彩票

void quitMain(user_t*,lott_t*,mylott_t*);//退出程序

#endif
