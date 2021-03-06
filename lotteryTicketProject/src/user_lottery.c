#include"user_lottery.h"
/*
	函数名：init_lot_head
	返回值：返回申请的头节点
	函数功能：初始化个人彩票链表
*/
lot_t* init_lot_head(){
	lot_t* head = malloc(sizeof(lot_t));
	memset(head,0,sizeof(lot_t));
	head->next = NULL;
	return head;
}

/*
	函数名：choice_lot_hand
	返回值：无
	函数功能：用户手动下注
*/
void choice_lot_hand(lot_t* head_lot,lot_t* newlot,iss_t* q){
		newlot->data.date = q->data.date;
		printf("请选择号码：\n"); 
		int i = 0,j = 0, num_1 = 0,flag = 0 ;
		//循环遍历 标志位查重复
		for(i = 0;i<7;){
			flag = 0;
			scanf("%d",&num_1);
			for(j = 0;j<i+1;j++){
				if(newlot->data.num[j] == num_1){
					printf("\033[32m 号码重复，请重新选择！\n\033[0m");
					flag = 1;
					break;
				}else{}	
			}
			if(flag == 0){
				newlot->data.num[i] = num_1;
				i++;   
			}else{}
		}
		while(getchar() != 10);

}

/*
	函数名：choice_lot_machine
	返回值：无
	函数功能：用户机器下注
*/
void choice_lot_machine(lot_t* head_lot,lot_t* newlot,iss_t* q){
		newlot->data.date = q->data.date;
		printf("机选号码：\n"); 
		int i = 0,j = 0, num_1 = 0,flag = 0 ;
		//循环遍历 标志位查重复
		srand(time(0));
		for(i = 0;i<7;){
			flag = 0;
			num_1 = rand()%99+1;
			for(j = 0;j<i+1;j++){
				if(newlot->data.num[j] == num_1){
					flag = 1;
					break;
				}else{}	
			}
			if(flag == 0){
				if(num_1<10){
					printf("0");
					printf("%d ",num_1);
				}else{
					printf("%d ",num_1);
				}
				newlot->data.num[i] = num_1;
				i++;   
			}else{}
		}
		printf("\n");

}
/*
	函数名：choice_lot
	返回值：无
	函数功能：用户下注
*/
void choice_lot(lot_t* head_lot,char* ptr,iss_t* head_iss,user_t* head_user,void (*choice_lot_all)(lot_t*,lot_t*,iss_t*)){
	system("clear");

	//遍历到用户彩票链表尾节点
	lot_t* p = head_lot;
	while(p->next != NULL){
		p = p->next;
	}
	//遍历到发行彩票链表尾节点
	iss_t* q = head_iss;
	while(q->next != NULL){
		q = q->next;
	}
	user_t* res = find_user(head_user,ptr);
	//发行彩票尾节点是头节点和 开奖状态 用户不能下注，直接释放空间并退出
	if(q == head_iss || strcmp(q->data.state,"已开奖" )==0){
		printf("\033[31m彩票未发行，请耐心等待\033[0m\n\n");
		//free(newlot);
	}else if(res == NULL){
		printf("\033[31m未查到相关用户信息!\033[0m\n\n");
	}else{
		//申请用户彩票链表
		lot_t* newlot = malloc(sizeof(lot_t));
		memset(newlot,0,sizeof(lot_t));
		//提示信息
		printf("\033[33m本期期号：%d 期 每注价格：%0.2lf （元）\033[0m\n",q->data.date,q->data.price);
		//调用上面的函数
		choice_lot_all(head_lot,newlot,q);
		//选择注数
		printf("请选择注数：\n");
		int num = 0;
		scanf("%d",&num);
		while(getchar() != 10);
		//单注最多不超过100注
		if(	num>0 && num<=100){
			newlot->data.amount = num;
			q->data.total  += num;
			//名字拷贝到用户彩票链表
			strcpy(newlot->data.name,ptr);
			//本期彩票ID自动++ 
			static int id_lot = 10;
			
			//id_lot++;
			//计算本次购买金额
			newlot->data.custom = num*(q->data.price);
			//加入奖池余额
			q -> data.pool += num*(q->data.price);
			//加入奖池金额
			q -> data.pool_1 += num*(q->data.price);

			//计算用户余额 = 用户存款 - 本次花费
			user_t* user = find_user(head_user,ptr);
			if(user->data.balance- newlot->data.custom >= 0){
				user->data.balance = user->data.balance- newlot->data.custom;
				printf("\033[33m购票成功\n\n\033[0m");
				//一个ID上最多5组号码
				static int count = 0;
				static char str[20] = {0};
				if(strcmp(str,ptr)==0){
					count ++;
					if(count >= 5){
						id_lot++;
						count = 0;
					}
				}else{
					strcpy(str,ptr);
					count = 0;
					id_lot++;
				}
				newlot->data.id = id_lot;
				
			}else{
				printf("\033[31m金额不足,购票失败!\n\n\033[0m");
				q->data.total  -= num;
				q -> data.pool -= num*(q->data.price);
				q -> data.pool_1 -= num*(q->data.price);
				return ;
			}
			//把新节点链接到用户彩票链表
			p->next = newlot;
			newlot ->next = NULL;
		}else{
			printf("\033[31m下注失败!\n\n\033[0m");
			free(newlot);
		}
	}
	
	clear();
}


void recode_draw(lot_t* p){
	printf("%8d",p->data.grade);
	printf("%8d",p->data.amount);
	printf("%12.2lf",p->data.balance);
}

void recode_purchase(lot_t* p){
	printf("%8d",p->data.amount);
	printf("%12.2lf",p->data.custom);
}

void head_purchase(){
	printf("    注数   ");
	printf(" 花费金额(元)\n");
}
void head_draw(){
	printf("  中奖等级");
	printf("  注数  ");
	printf(" 中奖金额(元)\n");
}


/*
	函数名：find_lot
	返回值：无
	函数功能：查询个人购票记录；查询个人中奖记录
*/
void find_lot(lot_t* head_lot,char* ptr,void (* recode)(lot_t*),void (* head)()){
	system("clear");
	int flag = 0;
	lot_t* p = head_lot->next;
	printf("      期号");
	printf("   彩票ID      ");
	printf("     票号       ");
	printf("      用户名  ");
	//调用上面的函数
	head(); 
	while(p != NULL){
		if(strcmp(p->data.name ,ptr)==0){
			flag = 1;
			printf("%8d",p->data.date);
			printf("%8d",p->data.id);
			printf("      ");
			int i = 0;
			for(i=0;i<7;i++){
				//个位数前面添加 0
				if(p->data.num[i] <10){ 
					printf("0");
					printf("%d",p->data.num[i]);
				}else{
					printf("%d",p->data.num[i]);
				}
				if(i !=6 ){
					printf("-");
				}else{}
			}
			printf("   ");
			printf("%8s",p->data.name);
			//通用函数指针，调用上面的
			recode(p); 
			printf("\n");
		}
		p = p->next;
	}
	if(flag == 0){
		printf("\033[31m\n无信息\n\033[0m");
	}
	
	clear();
}



/*
	函数名：lot_print
	返回值：无
	函数功能：查询所有用户购票记录
*/
void lot_print(lot_t* head_lot){
	system("clear");
	lot_t* p = head_lot;
	printf("      期号");
	printf("   彩票ID      ");
	printf("     票号        ");
	printf("       用户名 ");
	printf("     注数     ");
	printf(" 金额(元)\n");
	while(p->next != NULL){
		printf("%8d",p->next->data.date);
		printf("%8d",p->next->data.id);
		printf("     ");
		int i = 0;
		for(i=0;i<7;i++){
			if(p->next->data.num[i] <10){
				printf("0");
				printf("%d",p->next->data.num[i]);
			}else{
				printf("%d",p->next->data.num[i]);
			}
			if(i !=6 ){
				printf("-");
			}else{}
		}
		printf("      ");
		printf("%8s",p->next->data.name);
		printf("%8d",p->next->data.amount);
		printf("%12.2lf",p->next->data.custom);
		printf("\n");
		p = p->next;
	}
	clear();
}




/*
	函数名：save_lot_data
	返回值：无
	函数功能：保存个人彩票数据
*/
void save_lot_data(lot_t* head_lot){
	FILE* fp = fopen("./doc/user_lottery.txt","w");
	lot_t* p = head_lot;
	while(p->next != NULL){
		fwrite(&(p->next->data),sizeof(data_lot_t),1,fp);
		p = p->next;
	}
	fclose(fp);
} 


/*
	函数名：load_lot_data
	返回值：无
	函数功能：加载个人彩票数据
*/
void load_lot_data(lot_t* head_lot){
	FILE* fp = fopen("./doc/user_lottery.txt","r");
	if(fp ==NULL){
		return;
	}
	int res = 0;
	data_lot_t data = {0};
	lot_t* p = head_lot;
	while(1){
		res = fread(&data,sizeof(data_lot_t),1,fp);
		if(res == 0)break;
		lot_t* newlot = malloc(sizeof(lot_t));
		memset(newlot,0,sizeof(lot_t));
		newlot->data = data;
		p->next = newlot;
		p->next->next = NULL;
		p = p->next;
	}
	fclose(fp);
}


/*
	函数名：free_lot
	返回值：无
	函数功能：释放彩票链表堆空间
*/
void free_lot(lot_t* head_lot){
	lot_t* p = head_lot;
	lot_t* q = head_lot;
	while(p->next!= NULL){
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
}



































































































