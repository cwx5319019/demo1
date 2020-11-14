#ifndef myLottery_h
#define myLottery_h

typedef struct MyLottery{
	int id;//彩票ID
	int no;//彩票期号
	int b[5][5];//一注5个号码,不超过5注
	char name[20];//用户名
	int num;//已下注的彩票注数，不大于5
	int status[5];//中奖状态，0未中奖,1一等奖（中5球）,2二等奖（中4球）,3三等奖（中3球）,4四等奖（中2球）,5五等奖（中1球）
	int myjack[5];//各注的中奖金额
	struct MyLottery* prev;
	struct MyLottery* next;
}mylott_t;

#endif
