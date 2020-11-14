#ifndef lottery_h
#define lottery_h


//结构体Lottery采用双向不循环链表
typedef struct Lottery{
	int no;//彩票期号
	int price;//彩票单价
	int status;//开奖状态，1开奖，0未开奖
	int a[5];//5个1~99的中奖号码（如： 3,23）
	int saleNum;//该彩票的销售注数
	int jackpot;//奖池金额
	struct Lottery* prev;
	struct Lottery* next;
}lott_t;

#endif
