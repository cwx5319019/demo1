#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"userOp.h"
#include"lotteryOp.h"
#include"menu.h"
#include"limitIO.h"


//初始化Lottery结构体,采用双向不循环链表
lott_t* initLott(){
	lott_t* lottHead=(lott_t*)calloc(50,sizeof(lott_t));
	lottHead->next=NULL;
	lottHead->prev=NULL;
	return lottHead;
}


//按期号查找彩票
lott_t* findLott(lott_t* lottHead,int no){
	lott_t* lott=lottHead->next;
	while(lott!=NULL){
		if(lott->no==no){
			return lott;
		}else{
			lott=lott->next;
		}
	}
	return NULL;
}


//查找当期彩票
lott_t* lastLott(lott_t* lottHead){
	lott_t* lott=lottHead;
	if(lott->next==NULL){
		return NULL;
	}else{
		while(lott->next!=NULL){
			lott=lott->next;
		}
		return lott;
	}
}


//打印当期未开奖的彩票信息
void printLastLott(lott_t* lottHead){
	system("clear");
	lott_t* lott=lastLott(lottHead);
	if(lott==NULL){
		printf("\n本公司尚未发行任何彩票！\n");
		backToLast();
	}else if(lott->status==1){
		printf("\n当期彩票已开奖，请等待下期发行！\n");
		backToLast();
	}else{
		printf("发布期号  彩票单价  开奖状态  开  奖  号  码    销售量     奖池金额\n");
		printf("%5d        %2d         %d     %2d %2d %2d %2d %2d     %4d        %d\n",lott->no,lott->price,lott->status,lott->a[0],lott->a[1],lott->a[2],lott->a[3],lott->a[4],lott->saleNum,lott->jackpot);
	}
}


//发布彩票
void insertLott(lott_t* lottHead){
	system("clear");
	lott_t* lott=lastLott(lottHead);
	if(lott==NULL || lott->status==1){
		lott_t* newlott=(lott_t*)malloc(sizeof(lott_t));
		memset(newlott,0,sizeof(lott_t));
		lott_t* p=lottHead;
		int no=0,price=0,jackpot=0;

		if(lottHead->next==NULL){
			no=1;
			jackpot=1000;   //第一次发行彩票的初始化
		}else{
			while(p->next!=NULL){
				p=p->next;
			}
			no=p->no+1;
			jackpot=p->jackpot;//第二次开始的彩票初始化
		}

		while(1){
			printf("\n请输入彩票单价（1~99的整数）后，回车发行：");
			limitDigit(&price);//限制输入数字
			if(price==0){
				printf("\n彩票单价需大于0！\n");
			}else{
				newlott->no=no;
				newlott->price=price;
				newlott->jackpot=jackpot;
				p->next=newlott;
				newlott->prev=p;
				newlott->next=NULL;
				printf("\n发行成功！\n");
				backLast();
				break;
			}
		}
	}else{
		printf("\n开启失败！当期彩票尚未开奖，不能开新一期彩票！\n");
		backToLast();
	}
}



//查看所有历史彩票信息
void lookAllLott(lott_t* lottHead){
	system("clear");
	lott_t* p=lottHead;
	printf("发布期号  彩票单价  开奖状态  开  奖  号  码    销售量     奖池金额\n");
	while(p->next!=NULL){
		p=p->next;
		printf("%5d        %2d         %d     %2d %2d %2d %2d %2d     %4d        %d\n",p->no,p->price,p->status,
			p->a[0],p->a[1],p->a[2],p->a[3],p->a[4],p->saleNum,p->jackpot);
	}
	backLast();
}


//保存彩票
void saveLott(lott_t* lottHead){
	FILE* fp=fopen("./doc/lottDB.txt","w");
	lott_t* p=lottHead;
	while(p->next!=NULL){
		p=p->next;
		fwrite(p,sizeof(lott_t),1,fp);
	}
	fclose(fp);
}


//加载彩票
void loadLott(lott_t* lottHead){
	FILE* fp=fopen("./doc/lottDB.txt","r");
	if(fp==NULL){
		return;
	}else{
		lott_t* p=lottHead;
		while(feof(fp)==0){
			lott_t* newlott=(lott_t*)malloc(sizeof(lott_t));
			memset(newlott,0,sizeof(lott_t));
			fread(newlott,sizeof(lott_t),1,fp);
	//由于fwrite会多输入一行空格，故读取时需要判断一下，把多余的空格一行释放
			if(newlott->no>0){
				p->next=newlott;
				newlott->prev=p;
				newlott->next=NULL;
				p=p->next;
			}else{
				free(newlott);
			}
		}
	}
	fclose(fp);
}


//释放彩票
void freeLott(lott_t* lottHead){
	lott_t* p=lottHead;
	while(p->next!=NULL){
		p=p->next;
		free(p->prev);
	}
	free(p);
}
