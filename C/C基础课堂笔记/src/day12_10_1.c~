//上一节课  链表倒序重点  课后补上

#if 1
#include<stdio.h>
#include<stdlib.h>
#include<user.h>
#include<string.h>
#include<unistd.h>
void getstring(char* str, int len){
	fgets(str,len,stdin);
	int pos = strlen(str);
	if(str[pos-1] == '\n'){
		str[pos -1] = 0;
	}
}

typedef struct Student{
	char name[20];
	int chinese;
	int math;
	int english;

}stu_t;

typedef struct Teacher{
	char name[20];
	int id;
	int age;
}tea_t;

typedef struct Link{
	void* data;
	struct Link* next;
	struct Link* prev;

}link_t;

link_t* init_data(){
	link_t* head = malloc(sizeof(link_t));
	memset(head,0,sizeof(link_t));
	head -> next = head;
	head -> prev = head;
	return head;
}

stu_t* insert_stu(){
	stu_t* data = malloc(sizeof(stu_t));
	memset(data,0,sizeof(stu_t));
	printf("请输入学生的姓名：");
	getstring(data->name,20);
	printf("请输入语数外成绩：");
	scanf("%d %d %d",&data->chinese,&data->math,&data->english);
	while(getchar() != 10);
	return data;
}

tea_t* insert_tea(){
	tea_t* data = malloc(sizeof(tea_t));
	memset(data,0,sizeof(tea_t));
	printf("请输入老师的名字：");
	getstring(data->name,20);
	static int id = 190801;
	data->id = id++;
	printf("请输入教龄：");
	scanf("%d",&data->age);
	while(getchar() != 10);
	return data;	
}

void insert_data(link_t* head,void* (*insert)()){
	link_t* newnode = malloc(sizeof(link_t));
	memset(newnode,0,sizeof(link_t));
	newnode->data = insert();
	link_t* p = head->prev;
	p->next = newnode;
	newnode -> next = head;
	head -> prev = newnode;
	newnode -> prev = p;
}

void print_stu(void* data){
	printf("姓名：%s\n",((stu_t*)data)->name);
	printf("语文：%2d\n",((stu_t*)data)-> chinese);
	printf("数学：%2d\n",((stu_t*)data)-> math);
	printf("英语：%2d\n",((stu_t*)data)-> english);

}
void print_tea(void* data){
	printf("姓名：%s\n",((tea_t*)data)->name);
	printf("工号：%2d\n",((tea_t*)data)-> id);
	printf("教龄：%2d\n",((tea_t*)data)-> age);
	
}


void print_data(link_t* head , void* (*print)(void*)){
	link_t* p = head->next;
	while(p != NULL){
		printf("************\n");
		print(p->data);
		p = p->next;
	}
	printf("************\n");

}

int comp_stu(void* data,char* name){
	return strcmp(name,((stu_t*)data)->name);
}
int comp_tea(void* data,char* name){
	return strcmp(name,((tea_t*)data)->name);
}

link_t* find_data(link_t* head,int (*comp)(void*,char*)){
	char name[20] = {0};
	link_t* p = head ->next;
	printf("请输入查询的姓名：");
	getstring(name,20);
	while(p != NULL){
		if(comp(p->data,name)==0){
			return p;
		}
		p = p->next;
	}
	return NULL;
}


void remove_data(link_t* head,int (*comp)(void* , char*)){
	link_t* tar = find_data(head,comp);
	if(tar == 0 ){
		printf("没有查询结果\n");
		return;
	}
	tar -> prev ->next = tar->next ;
	tar -> next ->prev = tar ->prev;
	free(tar->data);
	free(tar);
}

int comp_stu_chinese(void* a,void* b){
	return ((stu_t* )a)->chinese-((stu_t*)b)->chinese;
}

int comp_tea_age(void* a,void* b){
	return ((tea_t* )a)->age-((tea_t*)b)->age;
}

void sort_data(link_t* head,int (*comp)(void* ,void*)){
	link_t* p = head->next;
	link_t* q = head->next;
	void* temp = 0;
	while(p->next != head){
		q = head->next;
		while(q->next != head){
			if(comp(q->data,q->next->data)<0){
			temp = q-> data;
			q->data = q->next->data;
			q->next->data = temp;
			}
			q = q->next;
		}
		p = p->next;	
	}
	
}

void save_data(link_t* head,int size){
	link_t* p = head->next;
	FILE* fp = fclose("./DB.txt","w");
	while( p != NULL){
		fwrite(p->data,size,1,fp);
		p = p->next;
	}
	fclose(fp);
}

void load_data(link_t* head,int size,char* filename){
	FILE* fp = (filename,"r");
	if(fp == NULL)return;
	link_t* p = head ->prev;
	int res = 0;
	while(1){
		void* data = malloc(size);
		memset(data,0,size);
		res = fread(data,size,1,fp);
		if(res == 0){
			free(data);
			break;
		}
		link_t* newnode = malloc(sizeof(link_t));
		memset(newnode,0,sizeof(link_t));
		newnode->data = data;
		p->next = newnode;
		newnode->next = head;
		head ->prev = newnode;
		newnode->prev = p;
		p = p->next;
	}
	fclose(fp);

}

int main(){
	link_t* stu_head = init_data();
	link_t* tea_head = init_data();
	
	
	insert_data(stu_head,insert_stu);
	printf(stu_head,print_stu);
	
	

	return 0;
}















#endif 




















