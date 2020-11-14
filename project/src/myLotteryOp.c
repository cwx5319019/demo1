#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"limitIO.h"
#include"userOp.h"
#include"myLotteryOp.h"
#include"lotteryOp.h"
#include"runLottery.h"
#include"menu.h"


//初始化MyLottery结构体,采用双向循环链表
mylott_t* initMyLott(){
	mylott_t* myLottHead=(mylott_t*)calloc(100,sizeof(mylott_t));
	myLottHead->next=myLottHead;
	myLottHead->prev=myLottHead;
	return myLottHead;
}


//查找最新的个人彩票信息
mylott_t* lastMyLott(mylott_t* myLottHead){
	mylott_t* p=myLottHead;
	if(p->next==myLottHead){
		return NULL;
	}else{
		while(p->next!=myLottHead){
			p=p->next;
		}
		return p;
	}
}


//手动输入下注号码
void inputNumber(mylott_t* newMyLott,int i,int* number){
	for(int j=0;j<5;j++){
		while(1){
			memset(number,0,sizeof(int)*5);
			printf("\n请输入第%d个号码（1～99）：",j+1);
			limitDigit(number+j);
			if(number[j]==0){
				printf("\n没有0号码！\n");
				fflush(stdout);
			}else{
				newMyLott->b[i][j]=number[j];
				break;
			}
		}
	}
	printf("\n购买第%d注成功！\n",i+1);
	fresh();
}


//系统分配下注号码
void aotuNumber(mylott_t* newMyLott,int i,int* number){
	while(1){
		printf("\n输入Y/y回车开始摇号：");
		char c=0;
		scanf("%c",&c);
		while(getchar()!=10)
		fflush(stdout);
		if(c=='Y' || c=='y'){
			runLottery(number);//系统分配号码函数
			memcpy(newMyLott->b[i],number,sizeof(int)*5);
			printf("\n购买第%d注成功！\n",i+1);
			fresh();
			break;
		}else{
			printf("\n请输入正确的编号！\n");
		}
	}
}


//添加个人彩票信息
void insertMyLott(user_t* userHead,lott_t* lottHead,mylott_t* myLottHead,char* name,int no){
	int num=0;
	int number[5]={0};
	user_t* user=findUser(userHead,name);//按用户名查找用户
	lott_t* lott=findLott(lottHead,no);//按彩票期号查找彩票
	mylott_t* newMyLott=(mylott_t*)malloc(sizeof(mylott_t));
	mylott_t* p=myLottHead;
	memset(newMyLott,0,sizeof(mylott_t));

	while(1){
		while(num==0){
			printf("\n请输入要购买的注数（最多5注）：\n");
			limitNum(&num);
		}
		if(user->cash-(lott->price)*num<0){
			char ch=0;
			while(1){
				printf("\n余额不足，不能购买！是否充值（是Y/y;否N/n）：\n");
				scanf("%c",&ch);
				while(getchar()!=10);
				if(ch=='Y' || ch=='y'){
					updateCash(userHead,name); //充值
					break;
				}else if(ch=='N' || ch=='n'){
					printf("\n你取消了购买！\n");
					backToLast();
					return;
				}else{
					printf("\n请输入正确的编号\n");
				}
			}
		}else{
			break;
		}
	}
	//第一个用户的第一次购买，对id进行初始化
	if(lastMyLott(myLottHead)==NULL){
		newMyLott->id=20190001;
	}else{
		newMyLott->id=lastMyLott(myLottHead)->id+1;
	}

	newMyLott->no=no;
	strcpy(newMyLott->name,name);
	newMyLott->num=num;
	//购买号码
	for(int i=0;i<num;i++){
		system("clear");
		printf("\n第%d注\n",i+1);
		while(1){
			int ch=0;
			printf("1.手动输入号码\n");
			printf("2.系统分配号码\n");
			printf("请选择：");
			scanf("%d",&ch);
			while(getchar()!=10);
			if(ch==1){
				inputNumber(newMyLott,i,number);//手动输入号码
				break;
			}else if(ch==2){
				aotuNumber(newMyLott,i,number);//系统分配号码
				break;
			}else{
				printf("\n请输入正确的编号！\n");
			}
		}

		lott->saleNum=lott->saleNum+1;
		lott->jackpot=lott->jackpot+lott->price;
		user->cash=user->cash-lott->price;
	}
	while(p->next!=myLottHead){
		p=p->next;
	}
	p->next=newMyLott;
	newMyLott->prev=p;
	newMyLott->next=myLottHead;
	myLottHead->prev=newMyLott;
	printf("\n购票完毕！\n");
	backToLast();
}


//购买彩票
void buyLott(user_t* userHead,lott_t* lottHead,mylott_t* myLottHead,char* name){
	printLastLott(lottHead);
	if(lastLott(lottHead)==NULL || lastLott(lottHead)->status==1){
		return;
	}else{
		if(lastLott(lottHead)!=NULL){
			int no=0;
			while(1){
				char c=0;
				printf("\n\n是否购买当期彩票（是Y/y;否N/n）：");
				scanf("%c",&c);
				while(getchar()!=10);
				if(c=='Y' || c=='y'){
					no=lastLott(lottHead)->no;
					insertMyLott(userHead,lottHead,myLottHead,name,no);
					break;
				}else if(c=='N' || c=='n'){
					printf("\n你取消了购买！\n");
					backToLast();
					break;
				}else{
					printf("\n请输入正确的编号！\n");
				}
			}
		}
	}
}



//删除个人彩票信息
void deleteMyLott(mylott_t* myLottHead,char* name){
	mylott_t* p=myLottHead;
	while(p->next!=myLottHead){
		p=p->next;
		if(strcmp(p->name,name)==0){
			p->prev->next=p->next;
			p->next->prev=p->prev;
			free(p);
			p=myLottHead;
		}
	}
}


//对开奖号码和个人号码进行快速排序
void quickSort(int* arr,int left,int right){
	if(left>=right){
		return;
	}else{
		//k之前为小于key的值，k至l为等于key的值，r之后为大于key的值，当l与r回合，一次排序完毕，再进行下一次递归
		int k=left,l=left+1,r=right;
		int key=arr[k];
		int temp=0;
		while(l<=r){
			if(arr[l]<key){
				temp=arr[l];
				arr[l]=arr[k];
				arr[k]=temp;
				l++;
				k++;
			}else if(arr[l]>key){
				temp=arr[l];
				arr[l]=arr[r];
				arr[r]=temp;
				r--;
			}else{
				l++;
			}
		}
		quickSort(arr,left,k-1);
		quickSort(arr,r+1,right);
	}
}


//开奖后需更新个人彩票信息，彩票信息，用户信息
void updateMyLott(user_t* userHead,lott_t* lottHead,mylott_t* myLottHead,int no,int* number){
	int count=0,addPrize=0;
	int num1=0,num2=0;
	user_t* user=userHead;
	mylott_t* p=myLottHead;
	lott_t* lott=lastLott(lottHead);

	while(p->next!=myLottHead){
		p=p->next;
		if(p->no==no){
			//对每一注进行分析处理
			for(int i=0;i<p->num;i++){
				count=0;
				//对两组号码进行排序
				quickSort(p->b[i],0,4);
				quickSort(number,0,4);
				int m=0,n=0;
				//一对一的进行大小比较，可以避免相同号码的重复判断
				while(m<5 && n<5){
					if(p->b[i][n]<number[m]){
						n++;
					}else if(p->b[i][n]>number[m]){
						m++;
					}else{
						count++;
						m++;
						n++;
					}
				}
				//中0球为没奖，记0，1球5等奖，2球4等奖，3球3等奖，4球2等奖，5球1等奖
				if(count==0){
					p->status[i]=0;
				}else{
					p->status[i]=6-count;
				}
				//5等奖固定单价的2倍，4等奖固定单价的5倍，3等奖固定单价的100倍，其余奖待固定奖分配完再定
				switch(p->status[i]){
					case 0:
						addPrize=0;
						break;
					case 1:
						addPrize=0;
						num1++;
						break;
					case 2:
						addPrize=0;
						num2++;
						break;
					case 3:
						addPrize=100*lott->price;
						break;
					case 4:
						addPrize=5*lott->price;
						break;
					case 5:
						addPrize=2*lott->price;
						break;
					default:
						break;
				}

				lott->jackpot=lott->jackpot-addPrize;
				p->myjack[i]=p->myjack[i]+addPrize;
				user=findUser(userHead,p->name);
				user->cash=user->cash+addPrize;
			}
		}
	}

	p=myLottHead;
	lott->jackpot=lott->jackpot*0.98;//公司抽取(奖池-固定奖)的百分之二作为收入
	while(p->next!=myLottHead){
		p=p->next;
		if(p->no==no){
			for(int i=0;i<p->num;i++){
				if(p->status[i]==2){
					addPrize=(int)(lott->jackpot*0.23/num2);//2等奖
					lott->jackpot -= addPrize;
					p->myjack[i]=p->myjack[i]+addPrize;
					user=findUser(userHead,p->name);
					user->cash=user->cash+addPrize;
				}else if(p->status[i]==1){
					addPrize=(int)(lott->jackpot*0.75/num1);//1等奖
					lott->jackpot -= addPrize;
					p->myjack[i]=p->myjack[i]+addPrize;
					user=findUser(userHead,p->name);
					user->cash=user->cash+addPrize;
				}
			}
		}
	}
}


//查看个人彩票购买历史信息
void lookMyLott(mylott_t* myLottHead,char* name){
	system("clear");
	mylott_t* p=myLottHead;
	if(p->next!=myLottHead){
		printf(" 彩票ID  彩票期号  下  注  号  码  注数  中奖状态  中奖金额\n");
		while(p->next!=myLottHead){
			p=p->next;
			if(strcmp(p->name,name)==0){
				printf("%d     %d     %2d %2d %2d %2d %2d    %d      %d       %d\n",p->id,p->no,p->b[0][0],p->b[0][1],p->b[0][2],p->b[0][3],p->b[0][4],p->num,p->status[0],p->myjack[0]);
				if(p->num>1){
					for(int i=1;i<p->num;i++){
						printf("                   %2d %2d %2d %2d %2d           %d       %d\n",p->b[i][0],p->b[i][1],p->b[i][2],p->b[i][3],p->b[i][4],p->status[i],p->myjack[i]);
					}
				}
			}
		}
	}else{
		printf("\n你还没买过票！\n");
	}
	backLast();
}


//查看个人中奖信息
void lookMyPrize(mylott_t* myLottHead,char* name){
	system("clear");
	mylott_t* p=myLottHead;
	int flag=0;
	if(p->next!=myLottHead){
		printf(" 彩票ID  彩票期号  下  注  号  码  注数  中奖状态  中奖金额\n");
		while(p->next!=myLottHead){
			p=p->next;
			if(strcmp(p->name,name)==0){
				for(int i=0;i<p->num;i++){
					flag += p->status[i];
				}
				if(flag){
					printf("%d     %d     %2d %2d %2d %2d %2d    %d      %d       %d\n",p->id,p->no,p->b[0][0],p->b[0][1],p->b[0][2],p->b[0][3],p->b[0][4],p->num,p->status[0],p->myjack[0]);
					if(p->num>1)
					for(int i=1;i<p->num;i++){
						printf("                   %2d %2d %2d %2d %2d           %d       %d\n",p->b[i][0],p->b[i][1],p->b[i][2],p->b[i][3],p->b[i][4],p->status[i],p->myjack[i]);
					}
				}
			}
		}
	}else{
		printf("\n很遗憾你还没中过奖！\n");
	}
	backLast();
}


//开奖
void createPrize(user_t* userHead,lott_t* lottHead,mylott_t* myLottHead){
	system("clear");
	printf("*******************当前未开奖彩票信息************************\n\n");
	printLastLott(lottHead);
	lott_t* lott=lastLott(lottHead);//获取当前彩票
	int number[5]={0};
	if(lott->status==1){
		return;
	}else{
		if(lott->saleNum==0){
			printf("\n当期彩票尚未有人购买，无法开奖！\n");
			backLast();
			return;
		}else{
			while(1){
				int ch=0;
				printf("1.手动输入号码\n");
				printf("2.系统分配号码\n");
				printf("请选择：");
				scanf("%d",&ch);
				while(getchar()!=10);
				if(ch==1){
				//手动输入开奖号码
					for(int i=0;i<5;i++){
						while(1){
							printf("\n请输入第%d个号码（1～99）：",i+1);
							limitDigit(number+i);//限制输入1～99的数字
							if(number[i]==0){
								printf("\n没有0号码！\n");
							}else{
								break;
							}
						}
					}
					break;
				}else if(ch==2){
				//系统生成开奖号码
					while(1){
						printf("\n输入Y/y回车开始摇号：");
						char c=0;
						scanf("%c",&c);
						while(getchar()!=10)
						fflush(stdout);
						if(c=='Y' || c=='y'){
							runLottery(number);
							break;
						}else{
							printf("\n请输入正确的编号！\n");
						}
					}
					break;
				}else{
					printf("\n请输入正确的编号！\n");
					fresh();
				}
			}
		}

		updateMyLott(userHead,lottHead,myLottHead,lott->no,number);
		lott->status=1;
		memcpy(lott->a,number,sizeof(int)*5);
		printf("\n\n\n\n\n开奖成功！\n");
		backLast();
	}
}


//保存个人彩票
void saveMyLott(mylott_t* myLottHead){
	FILE* fp=fopen("./doc/myLottDB.txt","w");
	mylott_t* p=myLottHead;
	while(p->next!=myLottHead){
		p=p->next;
		fwrite(p,sizeof(mylott_t),1,fp);
	}
	fclose(fp);
}


//加载个人彩票
void loadMyLott(mylott_t* myLottHead){
	FILE* fp=fopen("./doc/myLottDB.txt","r");
	if(fp==NULL){
		return;
	}else{
		mylott_t* p=myLottHead;
		while(feof(fp)==0){
			mylott_t* newMyLott=(mylott_t*)malloc(sizeof(mylott_t));
			memset(newMyLott,0,sizeof(mylott_t));
			fread(newMyLott,sizeof(mylott_t),1,fp);
			if(newMyLott->id>0){
				p->next=newMyLott;
				newMyLott->prev=p;
				newMyLott->next=myLottHead;
				myLottHead->prev=newMyLott;
				p=p->next;
			}else{
				free(newMyLott);
			}
		}
	}
	fclose(fp);
}


//释放个人彩票
void freeMyLott(mylott_t* myLottHead){
	mylott_t* p=myLottHead->next;
	while(p!=myLottHead){
		p=p->next;
		free(p->prev);
	}
	free(p);
}


//退出程序
void quitMain(user_t* userHead,lott_t* lottHead,mylott_t* myLottHead){
	saveUser(userHead);
	saveLott(lottHead);
	saveMyLott(myLottHead);
	freeUser(userHead);
	freeLott(lottHead);
	freeMyLott(myLottHead);
}
