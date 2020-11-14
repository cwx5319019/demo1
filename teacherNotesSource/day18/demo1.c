#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<user.h>
#include<unistd.h>

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
	head->next = head;
	head->prev = head;
	return head;
}

void* insert_stu(){
	stu_t* data = malloc(sizeof(stu_t));
	memset(data,0,sizeof(stu_t));
	printf("请输入学生姓名:");
	getstring(data->name,20);
	printf("请输入学生语数外三科成绩:");
	scanf("%d %d %d",&data->chinese,&data->math,&data->english);
	while(getchar()!=10);
	return data;
}

void* insert_tea(){
	tea_t* data = malloc(sizeof(tea_t));
	memset(data,0,sizeof(tea_t));
	printf("请输入老师的姓名:");
	getstring(data->name,20);
	static int id = 201901;
	data->id = id;
	id++;
	printf("请输入老师的教龄:");
	scanf("%d",&data->age);
	while(getchar()!=10);
	return data;
}

void insert_data(link_t* head,void* (*insert)()){
	link_t* newnode = malloc(sizeof(link_t));
	memset(newnode,0,sizeof(link_t));
	newnode->data = insert();
	link_t* p = head->prev;
	p->next = newnode;
	newnode->next = head;
	head->prev = newnode;
	newnode->prev = p;	
}

void print_stu(void* data){
	printf("姓名 : %s\n",((stu_t*)data)->name);
	printf("语文 : %2d\n",((stu_t*)data)->chinese);
	printf("数学 : %2d\n",((stu_t*)data)->math);
	printf("英语 : %2d\n",((stu_t*)data)->english);
}

void print_tea(void* data){
	printf("姓名 : %s\n",((tea_t*)data)->name);
	printf("工号 : %d\n",((tea_t*)data)->id);
	printf("教龄 : %d\n",((tea_t*)data)->age);
}

void print_data(link_t* head,void (*print)(void*)){
	link_t* p = head->next;
	while(p != head){
		printf("*************\n");
		print(p->data);
		p = p->next;
	}
	printf("*************\n");
}

int find_stu(void* data,char* name){
	return 	strcmp(name,((stu_t*)data)->name);
}

int find_tea(void* data,char* name){
	return strcmp(name,((tea_t*)data)->name);
}

link_t* find_data(link_t* head,int (*find)(void*,char*)){
	char name[20] = {0};	
	link_t* p = head->next;
	printf("请输入要查询的姓名:");
	getstring(name,20);
	while(p != NULL){
		if(find(p->data,name)==0){
			return p;
		}
		p = p->next;
	}	
	return NULL;
}

void remove_data(link_t* head,int (*comp)(void*,char*)){
	link_t* tar = find_data(head,comp);
	if(tar==0){
		printf("没有查询结果\n");
		return ;
	}
	tar->prev->next = tar->next;
	tar->next->prev = tar->prev;
	free(tar->data);
	free(tar);
}

int comp_stu_chinese(void* a,void* b){
	return ((stu_t*)a)->chinese - ((stu_t*)b)->chinese;
}

int comp_tea_age(void* a,void* b){
	return ((tea_t*)a)->age - ((tea_t*)b)->age;
}

void sort_data(link_t* head,int (*comp)(void*,void*)){
	link_t* p = head->next;
	link_t* q = head->next;
	void* temp = 0;
	while(p->next != head){
		q = head->next;
		while(q->next != head){
			if(comp(q->data,q->next->data)<0){
				temp = q->data;
				q->data = q->next->data;
				q->next->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
}

void free_data(link_t* head){
	link_t* p = head->next;
	while(p != head){
		p =p->next;
		free(p->prev->data);
		free(p->prev);
	}
	free(head);
}

void save_data(link_t* head,int size,char* filename){
	link_t* p = head->next;
	FILE* fp = fopen(filename,"w");
	while(p != head){
		fwrite(p->data,size,1,fp);
		p = p->next;
	}
	fclose(fp);
}

void load_data(link_t* head,int size,char* filename){
//可以外部传入函数指针针对不同的数据域进行不同的模块大小的加载
//也可以直接外部传入不同模块的大小，内部直接根据不同的大小进行加载
	FILE* fp = fopen(filename,"r");
	if(fp == NULL){return;}
	int res = 0;
	link_t* p = head->prev;
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
		head->prev = newnode;
		newnode->prev = p;
		p = p->next;
	}
	fclose(fp);
}

int main(){
	link_t* stu_head = init_data();
	link_t* tea_head = init_data();
	
	load_data(stu_head,sizeof(stu_t),"stuDB.txt");
	load_data(tea_head,sizeof(tea_t),"teaDB.txt");

	//insert_data(stu_head,insert_stu);
	insert_data(tea_head,insert_tea);

	//insert_data(stu_head,insert_stu);
	insert_data(tea_head,insert_tea);

	//insert_data(stu_head,insert_stu);
	insert_data(tea_head,insert_tea);

	//print_data(stu_head,print_stu);
	//print_data(tea_head,print_tea);

	print_data(stu_head,print_stu);
	print_data(tea_head,print_tea);
	//printf("\n\n");
	//sort_data(stu_head,comp_stu_chinese);
	//print_data(stu_head,print_stu);

	save_data(stu_head,sizeof(stu_t),"stuDB.txt");
	save_data(tea_head,sizeof(tea_t),"teaDB.txt");

	free_data(stu_head);	
	free_data(tea_head);	
	return 0;
}













     







