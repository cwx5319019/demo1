//注释：函数名  返回值  函数功能
#include"user_link.h"

/*
	函数名：getstring
	返回值：无
	函数功能：获取字符串
*/
void getstring(char* str,int len){
	fgets(str,len,stdin);
	int res = strlen(str);
	if(str[res-1] == 10){
		str[res-1] = 0;
	}
}


/*
	函数名：getch
	返回值：返回获得字符
	函数功能：获取字符
*/ 
char getch(){
	char c = 0;
	struct termios org_opts;
	struct termios new_opts;
	int res = 0;
	res = tcgetattr(STDIN_FILENO,&org_opts);
	assert(res == 0);
	new_opts = org_opts;
	new_opts.c_lflag &=~(ICANON |ECHO| ECHOE | ECHOK | ECHOPRT |ECHOKE | ICRNL);
	tcsetattr(STDIN_FILENO,TCSANOW,&new_opts);
	c = getchar();
	res = tcsetattr(STDIN_FILENO,TCSANOW,&org_opts);
	assert(res ==0);
	return c;	
}


/*
	函数名：clear
	返回值：无
	函数功能：按回车清屏
*/
void clear(){
	printf("\n请按回车继续：");
	while(getchar() != 10);	
	system("clear");
}



/*
	函数名：get_pwd
	返回值：无
	函数功能：获取密码同时隐藏密码
*/
void get_pwd(char* str){
	char ch = 0;
	int i = 0;
	while(1){
		ch = getch();
		if(ch == '\n'){
			printf("\n");
			str[i] = 0; 
			break;
		}else if((ch>='0' && ch<='9')||(ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){
			printf("*");
			//把获得字符存入数组
			str[i++] = ch; 
		}else if(ch == 127){
			printf("\b \b");
			if(i>0){i--;}  
		}
	}
}


/*
	函数名：init_user_head
	返回值：创建的头节点
	函数功能：初始化链表，创建头节点 
*/
user_t* init_user_head(){      
	user_t* head = malloc(sizeof(user_t));
	memset(head,0,sizeof(user_t));
	head->next = NULL;
	return head;  
	
}


/*
	函数名：insert_user_node
	返回值：无
	函数功能：用户注册
*/
void insert_user_node(user_t* head_user){
	system("clear");
	//用于查找重复的账户名
	user_t* q = head_user; 
	//用于增加注册成功的节点
	user_t* p = head_user;
	while(p->next != NULL){
		p = p->next;
	}
	//申请用户链表的节点
	user_t* newnode = malloc(sizeof(user_t));
	memset(newnode,0,sizeof(user_t));
	int flag = 0;
	while(1){
		printf("\033[32m欢迎来到用户注册页面！\033[0m\n\n");
		printf("请输入用户名：\n");
		char name[20] = {0};
		getstring(name,20);
		if(strcmp(name,"") != 0 ){
			//遍历查找用户是否重复
			while(q->next != NULL){
				if(strcmp (q->next->data.name , name)==0){
					printf("\033[31m该用户已经存在！\n\033[0m");
					//重复直接退出，释放空间
					free(newnode);
					clear();
					return ;
				}
				q = q->next;
			}
			//注册对比管理员和公证员用户名
			if(strcmp(name,"admin")!= 0 && strcmp(name,"worker")!=0){
				strcpy(newnode->data.name,name);
				flag = 1;
				break;
			}else{
				printf("\033[31m注册帐号不能和管理员帐号相同\n\033[0m");
				clear();
			}
		}else{
			printf("\033[31m账户名不能为空！\033[0m\n");
			clear();
		}
	}
	//满足注册要求进行密码设置
	if(flag == 1){
		int count_1 = 1;
		//密码三次错误退出循环
		while(1){
			printf("请设置密码：\n");
			char pwd_4[20] ={0};
			get_pwd(pwd_4);
			if(strcmp(pwd_4,"")!=0){
				printf("再次确认密码：\n");
				char pwd_5[20] ={0};
				get_pwd(pwd_5);
				if(strcmp(pwd_4,pwd_5)==0){
					strcpy(newnode->data.pwd,pwd_5);
					printf("\033[33m注册成功！\n\033[0m");
					//注册成功存入用户链表
					p->next = newnode;
					newnode->next = NULL;
					clear();
					break;
				}else{
					printf("\033[31m前后密码不一致，请重新设置密码!\033[0m\n");
					count_1++;
				}
				if(count_1 == 3){
					break;
				}
			}else{
				printf("\033[31m密码不能为空！\033[0m\n");
			}
		}
	}
}


/*
	函数名：login
	返回值：管理员登录成功返回1，公证员登录成功返回2，用户登录成功返回3
	函数功能：登录
*/
int login(user_t* head_user,char* ptr){
	printf("请输入帐号：\n");
	char str[20] = {0};
	getstring(str,20);
	strcpy(ptr,str);
	//管理员登录
	if(strcmp(str,"admin") == 0){ 
		int count_1 = 0;
		while(1){
			printf("请输入密码：\n");
			char ptr_1[20] ={0};
			get_pwd(ptr_1);
			if(strcmp(ptr_1,"12345")==0){
				int res_1 = identify_code();
				if(res_1 ==1){
				printf("\033[32m登录成功!\n\033[0m");
				//登录成功返回 1
				return 1;   
				}else{
					printf("\033[31m验证码错误！\n\033[0m");
					return -1;
				}			
			}else{
				printf("\033[31m密码错误!\n\033[0m");
				count_1++;
			}
			if(count_1 >=3){ 
				system("clear");
				return -1;
			}
		}
	//公正员登录
	}else if(strcmp(str,"worker") == 0 ){ 
		int count_2 = 0;
		while(1){
			printf("请输入密码：\n");
			char ptr_2[20] ={0};
			get_pwd(ptr_2);
			if(strcmp(ptr_2,"12345")==0){
				int res_2 = identify_code();
				if(res_2==1){
					printf("\033[32m登录成功!\n\033[0m");
					//登录成功返回 2
					return 2;
				}else{
					printf("\033[31m验证码错误！\n\033[0m");
					return -1;
				}
			}else{
				printf("\033[31m密码错误!\n\033[0m");
				count_2++;
			}
			if(count_2 >= 3){
				system("clear");
				return -1;
			}
		}
	}else{}	
	//调用查询函数查账户名是否存在
	user_t* p = find_user(head_user,ptr);   
	//判断返回值是否为NULL   后序如果操作NULL 会出现段错误
	if(p ==NULL){  
		printf("\033[31m无此帐号！\n\033[0m");
		
		clear();
		return -2;
	//判断输入的用户名和用户链表里的名字是否一致
	}else if(strcmp(str,p->data.name)==0){ 
		int count_3 = 0;
		while(1){
			printf("请输入密码：\n");
			char ptr_3[20] = {0};
			get_pwd(ptr_3);
			//对比两次密码
			if(strcmp(ptr_3,p->data.pwd)==0){   
				int res_3 = identify_code();
				if(res_3 == 1){
					printf("\033[32m登录成功!\n\033[0m");
					//登录成功返回 3
					return 3;           
				}else{
					printf("\033[31m验证码错误！\n\033[0m");
					return -1;
				}
			}else{
				printf("\033[31m密码错误\n \033[0m");
				count_3++;
			}
			if(count_3 >=3){
				system("clear");
				return -1;
			}
		}
	}else{
		printf("\033[31m无此帐号！\n\033[0m");
		
		clear();
	}
	return -1;	
}


/*
	函数名：find_user
	返回值：查询到的用户指针，否则返回 NULL
	函数功能：查询用户
*/
user_t* find_user(user_t* head_user,char* ptr){
	user_t* p = head_user->next;
	while(p != NULL){
		if(strcmp(p->data.name ,ptr)==0){
			//查询成功返回对应指针
			return p;
		}
		p = p->next;
	}
	return NULL;
}


/*
	函数名：print_user
	返回值：无
	函数功能：查看个人信息
*/
void print_user(user_t* head_user,char* ptr){
	system("clear");
	//调用查询函数 
	user_t* p = find_user(head_user,ptr);
	//如果注销个人信息则不会输出
	if(p == NULL ){ 
		printf("\033[31m 无信息\n\n\033[0m");
	}else{
		printf("\033[32m \n==============\n\033[0m");
		printf("账户：%s\n",p->data.name);
		printf("密码：%s\n",p->data.pwd);
		printf("余额：%.2lf",p->data.balance);
		printf("\033[32m \n==============\n\n\033[0m");
	}
	
	clear();
}


/*
	函数名：updata_user_code
	返回值：1
	函数功能：修改密码
*/
int updata_user_code(user_t* head_user,char* ptr){
	system("clear");
	printf("\033[33m 欢迎进入修改密码界面!\n\n\033[0m ");
	//调用查询函数先查询是否存在 
	user_t* p = find_user(head_user,ptr);
	//判断是否为空
	if( p== NULL){      
		printf("\033[31m无信息!\n\033[0m ");
	}else{
		int count_1 = 0;
		while(1){
			printf("请输入原始密码:\n");
			char pwd_1[20] = {0};
			get_pwd(pwd_1);
			if(strcmp(pwd_1,p->data.pwd)==0){
				int count = 1;
				//三次错误后退出
				while(1){
					printf("请输入新密码：\n");
					char pwd_2[20] ={0};
					get_pwd(pwd_2);
					if(strcmp(pwd_2,"")!= 0 ){
						//新旧密码不能一样
						if(strcmp(pwd_2,pwd_1)!= 0 ){
							printf("再次确认新密码：\n");
							char pwd_3[20] ={0};
							get_pwd(pwd_3);
							if(strcmp(pwd_2,pwd_3)==0){
								strcpy(p->data.pwd,pwd_2);
								printf("\n\033[33m 成功修改密码！2s后退出，请重新登录！\n\n\033[0m");					
								sleep(2);	
								system("clear");
								return 1;
							}else{
								if(count >= 3){ 
									break;
								}else{
								printf("\n\033[31m 前后密码不一致, 请重新输入!\n\n\033[0m");
								count++;
								}
							}
						}else{
							printf("\033[31m新旧密码不能一致！\033[0m\n");
						}
					}else{
						printf("\033[31m密码不能为空！\033[0m\n");
					}
				}
			
			}else{
				printf("\n\033[31m 密码错误！\n\n\033[0m");
				count_1++;
			}
			if(count_1 >=3){
				printf("\n\033[31m 密码错误三次，已退出！\n\n\033[0m ");	
				clear();
				return -1;				
			}
		}
	}
	
	clear();
	return -2;
}

  
/*
	函数名：delete_user
	返回值：无
	函数功能：注销用户；注销用户彩票链表
*/
int delete_user(user_t* head_user,char* ptr,lot_t* head_lot ){
	system("clear");
	printf("\033[31m请再次确认是否注销：1->是 2->否\n\033[0m");
	int num = 0;
	scanf("%d",&num);
	while(getchar() != 10);
	if(num == 1){
		user_t* p = head_user;
		user_t* temp = 0;
		//查询到删除的账户，释放该节点，把后面的用户节点向前移动
		while(p->next != NULL){
			if(strcmp(ptr,p->next->data.name)==0){
				temp = p->next;
				p->next = p->next->next;
				free(temp);
			}else{
				//必须再else里，防止漏值操作空指针
				p = p->next;
			}
			
		}
		lot_t* q = head_lot;
		lot_t* temp_1 = 0;
		while(q->next != NULL){
			if(strcmp(ptr,q->next->data.name)==0){
				temp_1 = q->next;
				q->next = q->next->next;
				free(temp_1);
			}else{
				
				q = q->next;
			}
		}
		printf("\n\033[33m注销成功!\033[0m\n");
	}else{}
	
	clear();
	return 1;
}


/*
	函数名：recharge_user
	返回值：无
	函数功能：用户充值
*/
void recharge_user(user_t* head_user,char* ptr){
	system("clear");
	//查询用户存在再充值
	user_t* p = find_user(head_user,ptr);
	if(p == NULL){
		printf("\033[31m充值失败\n\033[0m");
	}else{
		printf("请输入充值金额（元）：\n");
		double num = 0.0;
		scanf("%lf",&num);
		while(getchar() != 10);
		if(num > 0.0){
			p->data.balance += num;
			printf("\033[33m充值成功！\n\033[0m");
		}else{
			printf("\033[31m充值失败\n\033[0m");
		}
	}
	clear();
}


/*
	函数名：admin_find_user
	返回值：无
	函数功能：管理员查询单个用户信息
*/
void admin_find_user(user_t* head_user){
	system("clear");
	char name[20] ={0};
	printf("请输入要查询的用户帐号：");
	getstring(name,20);
	user_t* p = head_user->next;
	while(p != NULL){
		if(strcmp(p->data.name ,name)==0){
			printf("\033[35m\n==============\n\033[0m");
			printf("账户：%s\n",p->data.name);
			printf("密码：%s\n",p->data.pwd);
			printf("余额：%.2lf\n",p->data.balance);
			printf("\033[35m==============\n\n\033[0m");
			
			clear();
			return ;
		}
		p = p->next;
	}
	printf("\033[31m\n查无此人！\n\033[0m");
	
	clear();
}

/*
	函数名：print
	返回值：无
	函数功能：管理员查询全部注册人员的信息
*/
void print(user_t* head){
	system("clear");
	user_t* p = head;
	if(p->next ==NULL){
		printf("\033[31m\n无人员信息!\n\033[0m");
		return ;
	}
	printf("     账户  ");
	printf("     密码  ");
	printf("   余额\n");
	//遍历用户链表
	printf("\033[35m===============================\n\033[0m");
	while(p->next != NULL){
		printf("%10s",p->next->data.name);
		printf("%10s",p->next->data.pwd);
		printf("%10.2lf\n",p->next->data.balance);
		p = p->next;
	}
	printf("\033[35m===============================\n\n\033[0m");

	clear();
}


/*
	函数名：bubble_user
	返回值：无
	函数功能：按照用户余额排序
*/
void bubble_user(user_t* head_user){
	user_t* p = head_user->next;
	user_t* q = head_user->next;
	if(p ==NULL ){
		return ;
	}
	data_t temp = {{0}};
	//冒泡排序
	while(p->next != NULL){
		q = head_user->next;
		while(q->next != NULL	){
			if(q->data.balance < q->next->data.balance){
				temp = q->data;
				q ->data =q->next->data ;
				q->next->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
	printf("\033[33m\n排序完成！\n\033[0m");
	clear();
}


/*
	函数名：save_user
	返回值：无
	函数功能：保存用户名和密码
*/
void save_user(user_t* head){
	FILE* fp = fopen("./doc/user.txt","w");
	user_t* p = head;
	while(p->next != NULL){
		fwrite(&(p->next->data),sizeof(data_t),1,fp);
		p = p->next;	
	}
	fclose(fp);
}


/*
	函数名：load_user
	返回值：无
	函数功能：载入用户名和密码
*/
void load_user(user_t* head){ 
	FILE* fp = fopen("./doc/user.txt","r");
	if(fp ==NULL)return ;
	int res = 0;
	user_t* p = head;
	data_t temp = {{0}};
	while(1){
		res = fread(&temp,sizeof(data_t),1,fp);
		if(res == 0)break;
		user_t* newuser = malloc(sizeof(user_t));
		memset(newuser,0,sizeof(user_t));
		newuser->data = temp;
		
		p->next = newuser;
		newuser -> next = NULL;  //注意尾节点置为NULL
		p = p->next;
	}
	fclose(fp);
}



/*
	函数名：free_user
	返回值：无
	函数功能：释放user的堆空间
*/
void free_user(user_t* head_user){
	user_t* p = head_user->next;
	while( p != NULL){
		//注意申请一个中间量，否则会操作空指针
		user_t* q = p;
		p = p->next; 
		free(q);
	}
	free(head_user);
}


/*
	函数名：identify_code
	返回值：输入正确返回1 错误返回0
	函数功能：验证码函数
*/
int identify_code(void)
{
	char array[100]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	char a[5]="";
	char b[5]="";

	while(1)
	{
		//得到验证码
		srand(time(NULL));
		a[0] = array[rand()%26];
		a[1] = array[rand()%26+26];
		a[2] = array[rand()%10+52];
		a[3] = array[rand()%10+52];
		a[4] = '\0';

		printf("验证码:");
		printf("\033[44m%s\033[0m\n",a); //\033[44m
		printf("请输入验证码（Esc强制退回）：\n");
		scanf("%5s",b);
		while('\n'!=getchar());

		if(strcmp(a,b) != 0)
		{
			printf("\033[31m验证码错误，请重新输入！\n\033[0m");
			if(b[0]==27)
			{
				return 0;
			}
		}
		else
		{
			return 1;
		}
	}
}











