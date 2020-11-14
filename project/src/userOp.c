#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include"userOp.h"
#include"lotteryOp.h"
#include"myLotteryOp.h"
#include"limitIO.h"
#include"menu.h"


//User结构体采用单向链表
user_t* initUser(){
	//在堆空间申请50个模块
	user_t* head=(user_t*)calloc(50,sizeof(user_t));
	//初始化
	head->next=NULL;
	return head;
}


//按用户名查找用户(查重)
user_t* findUser(user_t* userHead,char* name){
	//定义一个结构体指针变量，用于遍历结构体数组
	user_t* user=userHead->next;
	//遍历User链表，如果找到则返回该user
	while(user!=NULL){
		if(strcmp(user->name,name)==0){
			return user;
		}else{
			user=user->next;
		}
	}
	//如果没找到，则返回NULL
	return NULL;
}


//用户注册
void insertUser(user_t* userHead){
	char name[20]={0},pwd[20]={0},rpwd[20]={0};
	//p用于遍历，指向尾节点
	user_t* p=userHead;
	//newuser用于保存新用户的信息
	user_t* newuser=(user_t*)malloc(sizeof(user_t));
	memset(newuser,0,sizeof(user_t));
	while(1){
		//打印注册页面
		printRegister();
		//获取有效的用户名（字母和数字）
		limitNamePwd(name,1);
		char ch=0;
		//输入的用户名为空时，让用户选择是否继续注册
		if(strlen(name)==0){
			printf("\n用户名不能为空！是否退出注册（是Y/y ;否N/n）：\n");
			while(1){
				scanf("%c",&ch);
				while(getchar()!=10);
				if(ch=='Y' || ch=='y'){
					return;
				}else if(ch=='N' || ch=='n'){
					break;
				}else{
					printf("\n请输入正确的编号！\n");
				}
			}
		//用户名已被注册时，让用户选择是否继续注册
		}else if(findUser(userHead,name)!=NULL || strcmp(name,"admin")==0 || strcmp(name,"worker")==0){
			printf("\n该用户名已存在！是否退出注册（是Y/y ;否N/n）：\n");
			while(1){
				scanf("%c",&ch);
				while(getchar()!=10);
				if(ch=='Y' || ch=='y'){
					return;
				}else if(ch=='N' || ch=='n'){
					break;
				}else{
					printf("\n请输入正确的编号！\n");
				}
			}
		}else{
			//密码不能为空，如果为空，则循环提示输入，直至不为空
			while(1){
				printf("\n请输入注册帐号的密码：");
				limitNamePwd(pwd,2);
				if(strlen(pwd)==0){
					printf("\n密码不能为空！\n");
					continue;
				}
				//输入有效密码后，重新输入一遍
				printf("\n请再输入一遍密码：");
				limitNamePwd(rpwd,2);
				if(strcmp(pwd,rpwd)!=0){
					printf("\n两次密码输入不一致，需要重新填写密码！\n");
				}else{
					break;
				}
			}
			//将p指向尾节点
			while(p->next!=NULL){
				p=p->next;
			}
			//赋值给newuser
			strcpy(newuser->name,name);
			strcpy(newuser->pwd,pwd);
			//增加链表信息
			p->next=newuser;
			newuser->next=NULL;
			p=newuser;
			printf("\n注册成功！\n");
			backToLast();
			break;
		}
	}
}


//查看个人信息
void lookUser(user_t* userHead,char* name){
	while(1){
		system("clear");
		printf("\n个人信息\n");
		user_t* user=findUser(userHead,name);
		printf("\n用户名\t余额\n");
		printf("%s\t%d\n",user->name,user->cash);
		backLast();
		break;
	}
}


//查询用户
void queryUser(user_t* userHead){
	while(1){
		system("clear");
		printf("\n请输入要查询的用户名：");
		char name[20]={0};
		limitNamePwd(name,1);
		if(strlen(name)==0){
			printf("\n用户名不能为空！\n");
			fresh();
		}else{
			if(findUser(userHead,name)==NULL){
				printf("\n该用户不存在！\n");
				backToLast();
				break;
			}else{
				lookUser(userHead,name);
				break;
			}
		}
	}
}


//用户注销
int deleteUser(user_t* userHead,mylott_t* myLottHead,char* name){
	while(1){
		system("clear");
		printf("\n确认注销你的帐号吗（是Y/y;否N/n）：");
		char c=0;
		scanf("%c",&c);
		while(getchar()!=10);
		if(c=='Y' || c=='y'){
			deleteMyLott(myLottHead,name);
			user_t* user=findUser(userHead,name);
			user_t* p=userHead;
			while(p->next!=user){
				p=p->next;
			}
			p->next=user->next;
			free(user);
			printf("\n你成功注销了你的帐号！\n");
			printf("\n正在退出登录并返回首页...");
			fflush(stdout);
			sleep(2);
			return 1;
		}else if(c=='N' || c=='n'){
			printf("\n你取消了注销帐号\n");
			backToLast();
			break;
		}else{
			printf("\n请输入正确的字母！\n");
			fresh();
		}
	}
	return 0;
}


//用户充值
void updateCash(user_t* userHead,char* name){
	system("clear");
	while(1){
		printf("\n请输入要充值的金额：");
		int cash=0;
		limitCash(&cash);
		if(cash==0){
			printf("\n请输入大于0的金额！\n");
		}else{
			user_t* user=findUser(userHead,name);
			user->cash=user->cash+cash;
			printf("\n你成功充值了%d元\n",cash);
			backToLast();
			break;
		}
	}
}


//用户修改密码
void updatePwd(user_t* userHead,char* name){
	system("clear");
	char oPwd[20]={0},nPwd[20]={0},rnPwd[20]={0};
	user_t* user=findUser(userHead,name);
	int oCount=0,nCount=0;
	while(oCount<3){
		system("clear");
		printf("\n请输入旧密码：");
		limitNamePwd(oPwd,2);
		if(strcmp(user->pwd,oPwd)==0){
			while(nCount<3){
				printf("\n请输入新密码：");
				limitNamePwd(nPwd,2);
				printf("\n请再输入一遍新密码：");
				limitNamePwd(rnPwd,2);
				if(strcmp(nPwd,rnPwd)==0){
					strcpy(user->pwd,nPwd);
					printf("\n你的密码修改成功！\n");
					printf("\n返回上一级（是enter;否[other key]）：");
					if(getchar()==10){
						return;
					}
				}else{
					printf("\n两次新密码输入不一致\n");
					nCount++;
				}
			}
			printf("\n三次确认新密码错误，密码修改失败！\n");
			backToLast();
			return;
		}else{
			printf("\n旧密码不正确！\n");
			oCount++;
			fresh();
		}
	}
	printf("\n三次旧密码输入错误，修改密码失败！\n");
	backToLast();
}


//按余额降序排序
void bubbleSort(user_t* userHead){
	if(userHead->next==NULL){
		return;
	}else{
		user_t* p=userHead->next;
		user_t* q=userHead->next;
		user_t* temp=(user_t*)malloc(sizeof(user_t));
		memset(temp,0,sizeof(user_t));
		while(p->next!=NULL){
			q=p->next;
			while(q!=NULL){
				if(q->cash>p->cash){
					strcpy(temp->name,p->name);
					strcpy(temp->pwd,p->pwd);
					temp->cash=p->cash;
					strcpy(p->name,q->name);
					strcpy(p->pwd,q->pwd);
					p->cash=q->cash;
					strcpy(q->name,temp->name);
					strcpy(q->pwd,temp->pwd);
					q->cash=temp->cash;
				}
				q=q->next;
			}
			p=p->next;	
		}
		free(temp);
	}
}


//查看所有用户
void printAllUser(user_t* userHead){
	if(userHead->next==NULL){
		return;
	}else{
		system("clear");
		printf("用户名\t余额\n");
		user_t* p=userHead->next;
		while(p!=NULL){
			printf("%s\t%d\n",p->name,p->cash);
			p=p->next;
		}
	}
}


//排序并显示
void sort(user_t* userHead){
	bubbleSort(userHead);//按余额冒泡降序排序
	printAllUser(userHead);//打印所有用户信息
	backLast();//提示是否返回上一级
}


//保存用户
void saveUser(user_t* userHead){
	FILE* fp=fopen("./doc/userDB.txt","w");
	user_t* p=userHead;
	while(p->next!=NULL){
		p=p->next;
		fwrite(p,sizeof(user_t),1,fp);
	}
	fclose(fp);
}


//加载用户
void loadUser(user_t* userHead){
	FILE* fp=fopen("./doc/userDB.txt","r");
	if(fp==NULL){
		return;
	}else{
		user_t* p=userHead;
		while(1){
			if(feof(fp)){
				break;
			}else{
				user_t* newuser=(user_t*)malloc(sizeof(user_t));
				memset(newuser,0,sizeof(user_t));
				fread(newuser,sizeof(user_t),1,fp);
				if(strlen(newuser->name)>0){
					p->next=newuser;
					newuser->next=NULL;
					p=p->next;
				}else{
					free(newuser);
				}
			}		
		}
	}
	fclose(fp);
}


//释放用户
void freeUser(user_t* userHead){
	user_t* p=userHead;
	while(p->next!=NULL){
		while(p->next->next!=NULL){
			p=p->next;
		}
		free(p->next);
		p->next=NULL;
		p=userHead;
	}
	free(userHead);
}
