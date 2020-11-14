#include<stdio.h>
#include<stdlib.h>
#include<user.h>
#include<string.h>

typedef struct Data{
	char name[20];
	int id;
}data_t;

typedef struct Student{
	data_t data;  //数据域
	struct Student* next;//指向自身
	//指向下一个节点的指针
	struct Student* prev;
}stu_t;

stu_t* init_stu(){
	stu_t* head = malloc(sizeof(stu_t));
	memset(head,0,sizeof(stu_t));
	head->data.id = 190800;
	head->next = NULL;
	return head;
}

void insert_stu(stu_t* head){
	stu_t* newstu = malloc(sizeof(stu_t));
	memset(newstu,0,sizeof(stu_t));
	printf("请输入学生的姓名:");
	getstring(newstu->data.name,20);
	//寻找尾节点，然后让尾节点的next指向newstu
	stu_t* p = head;
	while(p->next != NULL){
		p = p->next;
	}
	newstu->data.id = p->data.id + 1;
	p->next = newstu;
	newstu->next = NULL;
	newstu->prev = p;//单向不循环链表多出这一句，就会变成双向不循环

	//头插法
/*
	newstu->next = head->next;
	head->next->prev = newstu;
	newstu->prev = head;
	head->next = newstu;
*/
	//id++;
}

stu_t* find_stu(stu_t* head){
	int num = 0;
	char name[20] = {0};
	printf("请输入要查询的学生的姓名或者学号:");
	getstring(name,20);
	num = atoi(name);
	stu_t* p = head->next;
	while(p != NULL){
		if((num==0)?(strcmp(name,p->data.name)==0):(num==p->data.id)){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void bubblesort(stu_t* head){ //指针只给 数据域 做了交换，  
	stu_t* p = head->next;
	stu_t* q = head->next;
	data_t temp = {0};
	if(head->next == NULL){return;}
	while(p->next != NULL){
		q = head->next;
		while(q->next != NULL){
			if(q->data.id < q->next->data.id){
				temp = q->data; //q->data 落脚点是data，是个结构体，所以中间变量定义一个data_t 类型的temp
				q->data = q->next->data;
				q->next->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
}

/*单向不循环链表的删除
void remove_stu(stu_t* head){
	char name[20] = {0};
	getstring(name,20);
	stu_t* p = head;
	stu_t* temp = 0;
	while(p->next != NULL){
		if(strcmp(p->next->data.name,name)==0){
			temp = p->next;
			p->next = p->next->next;
			free(temp);
			break;
		}//else{
			p = p->next;
		//}
	}
}*/

//双向不循环链表的删除
void remove_stu(stu_t* head){
	stu_t* tar = find_stu(head);
	if(tar==0){return;}
	tar->prev->next = tar->next;
	if(tar->next != NULL){
		tar->next->prev = tar->prev;
	}
	free(tar);
}

void free_stu(stu_t* head){
	stu_t* p = head;
	//stu_t* temp = 0;
	while(p->next != NULL){
		p = p->next;
		free(p->prev);
	}
	free(p);
}

void print_all(stu_t* head){
	stu_t* p = head->next;
	while(p != NULL){
		printf("**************\n");
		printf("姓名：%s\n",p->data.name);
		printf("学号：%d\n",p->data.id);
		p = p->next;
	}
	printf("**************\n");
}

void print_stu(stu_t* head){
	stu_t* tar = find_stu(head);
	if(tar == NULL){
		printf("查无此人\n");
		return;
	}
	printf("**************\n");
	printf("姓名：%s\n",tar->data.name);
	printf("学号：%d\n",tar->data.id);
	printf("**************\n");
}

void save_stu(stu_t* head){
	FILE* fp = fopen("./DB.txt","w");
	stu_t* p = head;
	while(p->next != NULL){
		fwrite(&p->data,sizeof(data_t),1,fp);
		p = p->next;
	}
	fclose(fp);
}

void load_stu(stu_t* head){
	FILE* fp = fopen("./DB.txt","r");
	if(fp == NULL){return;}
	data_t data = {0};
	int res = 0;
	stu_t* p = head;
	while(p->next != NULL){
		p =p->next;
	}
	while(1){
		res = fread(&data,sizeof(data_t),1,fp);
		if(res == 0){break;}
		stu_t* newstu = malloc(sizeof(stu_t));
		memset(newstu,0,sizeof(stu_t));
		newstu->data = data;
		p->next = newstu;
		newstu->next = NULL;
		newstu->prev = p;
		p = newstu;
	}
	fclose(fp);
}

int main(){
	stu_t* head = init_stu();
	load_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	//print_all(head);
	save_stu(head);
	print_all(head);
/*	while(1){
		remove_stu(head);
		print_all(head);
	}*/
	free_stu(head);
	return 0;
}
