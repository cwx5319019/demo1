#include"issue_link.h"
#define P_1 p_1->next->data.balance
#define P_2 p_1->next->data.amount
#define NUM_6 p->next->data.num[6]


/*
	函数名：init_head
	返回值：返回每期彩票链表头节点
	函数功能：初始化每期彩票链表堆空间
*/
iss_t* init_head(){
	iss_t* head = malloc(sizeof(iss_t));
	memset(head,0,sizeof(iss_t));
	head->next = NULL;
	return head;
}


/*
	函数名：issue_link
	返回值：无
	函数功能：管理员发行彩票
*/
void issue_link(iss_t* head_iss){
	system("clear");
	iss_t* q  = head_iss;
	//遍历到发行彩票链表尾节点
	while( q -> next != NULL){  
		q = q->next;
	}
	//如果发行彩票链表只有头节点和 开奖状态为开奖 满足条件 进行发行彩票
	if(head_iss->next == NULL || strcmp(q->data.state,"已开奖")==0){
		iss_t* p = head_iss;
		iss_t* newiss = malloc(sizeof(iss_t));
		memset(newiss,0,sizeof(iss_t));
		//管理员拟定彩票单价
		printf("请输入彩票单价(元)：\n");
		scanf("%lf",&(newiss->data.price));
		while(getchar() != 10);
		
		while(p->next != NULL){
			p = p->next;
		}
		//期号加入新节点
		newiss->data.date =  p -> data.date + 1; 
		//开奖状态初始化为未开奖
		strcpy(newiss->data.state,"未开奖");
		//上一期的剩余奖池给下一期
		newiss->data.pool_1 = p->data.pool ;
		//链接到每期发行彩票链表
		p-> next = newiss;
		newiss-> next =NULL;
		printf("\033[33m发行成功\n\033[0m");
		
	}else{
		printf("\033[31m上一期未开奖！\n\033[0m");
	}
	
	clear();
}


/*
	函数名： draw_lot_worker
	返回值：无
	函数功能：公证员发布出奖号码
*/
void draw_lot_worker(iss_t* head_iss,lot_t* head_lot){
	system("clear");
	printf("\033[32m欢迎来到开奖界面！\033[0m\n\n");
	iss_t* p = head_iss;
	lot_t* p_x = head_lot;
	//p_x 指向用户彩票链表 尾节点 
	while(p_x ->next != NULL){
		p_x = p_x ->next; 
	}
	//将p 指向尾节点 查看开奖状态
	while(p->next != NULL){
		p = p->next;
	}
	//发行彩票链表 等于头节点  无发行记录 
	if(p == head_iss ){  
		printf("\033[31m管理员尚未发行，请耐心等待！\n\033[0m");
		return ;
	//查看发行彩票链表的 开状态 
	}else if (strcmp(p->data.state , "已开奖")==0){  
		printf("\033[31m下一期尚未发行，请耐心等待！\n\033[0m");
		
		return ;
	//有人下注，尾节点的期号和管理员发行期号一致 
	}else if(p_x->data.date != p->data.date ){
		printf("\033[31m本期无人下注，请耐心等待!\n\033[0m");

	}else{
		//随机7个号码函数体
		srand(time(0));
		int i = 0,j=0,m = 0;
		char ch = 0;
		int data = 0,flag = 0;
		struct termios org_opts;
		struct termios new_opts;
		tcgetattr(STDIN_FILENO,&org_opts);
		new_opts = org_opts;
		new_opts.c_lflag &=~(ICANON |ECHO| ECHOE | ECHOK | ECHOPRT |ECHOKE | ICRNL);
		tcsetattr(0,TCSANOW,&new_opts);
		printf("按回车开始开始\n");
		printf("__-__-__-__-__-__-__");
		while(1){
				ch = getch();
				if(ch == 10){break;}
			}
			printf("\033[18D");
			fflush(stdout);
			for(j = 0;j<7;){
				
				//循环100次，出随机效果	
				for(i= 0; i<100;i++){
					data = rand()%99+1;
					fflush(stdout);
					usleep(10000);
					if(data<10){
						printf("\033[2D");
						if(j==6){printf("\033[34m");}
						else{printf("\033[31m");}
						printf("0");
						printf("\033[0m");
					}else{
						printf("\033[2D");
					}
					if(j==6){printf("\033[34m");}
					else{printf("\033[31m");}
					printf("%d",data);
					printf("\033[0m");
					fflush(stdout);
				}
				flag = 0;
				for(m=0;m<j+1;m++){
					if(p->data.num[m] != data ){ 
						//添加号码到每期彩票链表的 号码数组 
						p->data.num[j] = data;
						flag = 1;
					}else{}
				}				
				if(flag == 1){
					printf("\033[3C");
					j++;
				}else{}
			}	
			printf("\n");
			tcsetattr(STDIN_FILENO,TCSANOW,&org_opts);
			printf("\033[32m开奖成功！\n\n\033[0m");
			//发行彩票链表开将状态置为“已开奖”
			strcpy(p->data.state,"已开奖");	
		}
		clear();
		return ;
}


/*
	函数名：draw
	返回值：无
	函数功能：公证员手动出奖
*/
void draw(iss_t* head_iss,lot_t* head_lot){
	system("clear");
	printf("\033[32m欢迎来到开奖界面！\033[0m\n\n");
	iss_t* p = head_iss;
	lot_t* p_x = head_lot;
	//p_x指向最后，检测本期是否有人打号
	while(p_x ->next != NULL){
		p_x = p_x ->next;
	}
	//将p 指向尾节点 查看开奖状态
	while(p->next != NULL){
		p = p->next;
	}
	//发行彩票链表 等于头节点  无发行记录 
	if(p == head_iss ){
		printf("\033[31m管理员尚未发行，请耐心等待！\n\033[0m");
		return ;
	//查看发行彩票链表的 开状态 
	}else if (strcmp(p->data.state , "已开奖")==0){  
		printf("\033[31m下一期尚未发行，请耐心等待！\n\033[0m");
		return ;
	//有人下注，尾节点的期号和管理员发行期号一致 
	}else if(p_x->data.date != p->data.date ){
		printf("\033[31m本期无人下注，请耐心等待!\n\033[0m");
		return ;
	}else{
		//随机7个号码 函数体
		printf("请输入号码：\n");
		int i = 0,j = 0,flag = 0,num = 0;
		for(i= 0;i<7;){
			flag = 0;
			scanf("%d",&num);  //1
			for(j=0;j<i+1;j++){
				if(p->data.num[j] == num){
					flag = 1;
				}else{}
			}
			if(flag == 0){
				//添加号码到每期彩票链表的 号码数组 
				p->data.num[i] = num;
				i++;
			}else{
				printf("\033[31m出奖号码重复，请重新输入！\n\033[0m");
			}
		}
		while(getchar() != 10);
		//发行彩票链表开将状态置为“已开奖”
		strcpy(p->data.state,"已开奖");
		printf("\033[33m开奖成功！\033[0m\n");
	}
	clear();
}


/*
	函数名：grade_num
	返回值：返回中奖等级
	函数功能：计算某等奖用户个数
*/
int grade_num(lot_t* head_lot,int grade){
	lot_t* p = head_lot;
	int count = 0;
	while(p->next != NULL ){
		//循环本期链表的中奖个数做累加
		if(p->next->data.grade == grade){
			count += p->next->data.amount;
		}else{}
		p = p->next;
	}
	return count;
}


/*
	函数名：compare_iss
	返回值：无
	函数功能：比较彩民号码是否中奖
*/
void compare_iss(iss_t* head_iss,lot_t* head_lot,user_t* head_user){
	iss_t* p = head_iss;
	while(p->next != NULL){
		p = p->next;
	}
	if(p == head_iss ){ 
		return ;
	}else if (strcmp(p->data.state , "未开奖")==0){ 
		return ;
	}
	//以上是防止未开奖进行操作
	else{ 
		int i = 0,j = 0,count = 0;
		lot_t* p = head_lot;
		iss_t* q = head_iss;
		while(q->next != NULL){
			q = q->next;
		}
		//遍历用户本期彩票链表
		while(p->next != NULL){
			count = 0;
			if(p->next->data.date == q->data.date){
				//循环去对比用户号码和每期开奖号码
				for(j =0; j<6;j++){
					for(i = 0;i<6;i++){
						if(p->next->data.num[i] == q->data.num[j]){
							//计算中号码的个数
							count++;
						}
					}
				}
				//前六个中奖号码个数和 对比最后一个号码是否中奖
				if(count==6 && NUM_6 ==q->data.num[6] ){
					p->next->data.grade = 1 ;
				}else if(count==6 ){
					p->next->data.grade = 2;
				}else if(count==5 && NUM_6 ==q->data.num[6]){
					p->next->data.grade = 3;		
				}else if(count==5 ||(count==4 && NUM_6 ==q->data.num[6])){
					p->next->data.grade = 4;
				}else if(count==4 || (count==3 && NUM_6 ==q->data.num[6])){
					p->next->data.grade = 5;
				}else if( (NUM_6 == q->data.num[6])){
					p->next->data.grade = 6;
				}else{
					p->next->data.grade = 0;
				}
			}else{}
			p = p->next;
		}
		//发放金额
		double temp = q->data.pool;
		lot_t* p_1 = head_lot;
		user_t* p_y = head_user;
		
		while(p_1->next != NULL){
			if(p_1->next->data.date == q->data.date){
				while(p_y->next != NULL){
					if(strcmp(p_y->next->data.name,p_1->next->data.name)==0){
						break;
					}
					p_y = p_y -> next;
				}
				if(p_1->next->data.grade == 1){
					P_1 = temp*0.3/grade_num(head_lot,1)*P_2;
					p_y->next->data.balance += P_1;
				
				}else if(p_1->next->data.grade == 2) {
					P_1 = temp*0.2/grade_num(head_lot,2)*P_2;
					p_y->next->data.balance += P_1;
					
				}else if(p_1->next->data.grade == 3){
					P_1 = temp*0.2/grade_num(head_lot,3)*P_2;
					p_y->next->data.balance += P_1;
					
				}else if(p_1->next->data.grade == 4){
					P_1 = temp*0.1/grade_num(head_lot,4)*P_2;
					p_y->next->data.balance += P_1;
					
				}else if(p_1->next->data.grade == 5){
					P_1 = temp*0.1/grade_num(head_lot,5)*P_2;
					p_y->next->data.balance += P_1;
				
				}else if(p_1->next->data.grade == 6){
					P_1 = temp*0.1/grade_num(head_lot,6)*P_2;
					p_y->next->data.balance += P_1;
				
				}else{
					P_1 = 0;
				}
			
				//奖池余额 = 全部金额 - 中奖金额
				q->data.pool = q->data.pool - P_1;
				
			}else{}
			
			p_1 = p_1 ->next;
		}
		
		
		
	}
}

/*
	函数名：print_iss_link
	返回值：无
	函数功能：打印每期彩票链表；查看历史发布
*/
void print_iss_link(iss_t* head_iss){
	system("clear");
	iss_t* p = head_iss->next;
	printf("     期号  ");
	printf("  开奖状态    ");
	printf("    开奖号码     ");
	printf("         总投注  ");
	printf("    奖池金额   \n");
	while(p != NULL){
		printf("%8d",p->data.date);		
		printf("%15s",p->data.state);
		printf("   ");	
		int i = 0;
		for(i = 0;i<7;i++){
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
		printf("%8d",p->data.total);
		printf("%15.2lf\n",p->data.pool_1);
		p = p->next;
	}
	clear();
}


/*
	函数名：save_iss
	返回值：无
	函数功能：保存每期彩票链表
*/
void save_iss(iss_t* head_iss){
	FILE* fp = fopen("./doc/issue_link.txt","w");
	iss_t* p =  head_iss;
	while(p->next != NULL){
		fwrite(&(p->next->data),sizeof(data_iss_t),1,fp);
		p = p->next;
	}
	fclose(fp);
}

/*
	函数名：load_iss
	返回值：无
	函数功能：加载每期彩票链表
*/
void load_iss(iss_t* head_iss){
	FILE* fp = fopen("./doc/issue_link.txt","r");
	if(fp == NULL)return ;
	iss_t* p =  head_iss;
	int res = 0;
	data_iss_t temp = {0};
	while(1){
		res = fread(&temp,sizeof(temp),1,fp);
		if(res == 0)break;
		iss_t* newiss = malloc(sizeof(iss_t));
		memset(newiss,0,sizeof(iss_t));
		newiss->data = temp;
		p ->next = newiss;
		p->next->next = NULL;
		p = p->next;
	}
	fclose(fp);
}

/*
	函数名：free_iss
	返回值：无
	函数功能：释放每期彩票链表
*/
void free_iss(iss_t* head_iss){
	iss_t* p = head_iss->next;
	while(p != NULL){
		iss_t* q = p;
		p = p->next;
		free(q);
	}
	free(head_iss);
}


/*
	函数名：free_all
	返回值：无
	函数功能：释放所有空间
*/
void free_all(user_t* head_user,iss_t* head_iss,lot_t* head_lot){
	free_user(head_user);
	free_lot(head_lot);
	free_iss(head_iss);
}


/*
	函数名：save_all
	返回值：无
	函数功能：保存所有数据
*/
void save_all(user_t* head_user,iss_t* head_iss,lot_t* head_lot){
		save_user(head_user);
		save_lot_data(head_lot); 
		save_iss(head_iss); 
}

/*
	函数名：load_all
	返回值：无
	函数功能：加载所有数据
*/
void load_all(user_t* head_user,iss_t* head_iss,lot_t* head_lot){
	load_user(head_user);
	load_lot_data(head_lot);
	load_iss(head_iss);   

}














