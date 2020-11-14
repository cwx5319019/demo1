#include<stdio.h>
#include<stdlib.h>
#include<user.h>
#include<string.h>

typedef struct Data{
	char name[20];
	int id;
}data_t;

typedef struct Student{
	data_t data;
	struct Student* next;//指向下一个节点的指针
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
	stu_t* p = head;
	while(p->next != NULL){
		p = p->next;
	}
	newstu->data.id = p->data.id + 1;
	p->next = newstu;
	newstu->next = NULL;
}
/*
	编写一个函数，将一条单向链表逆序
*/
void reverse(stu_t* head){
	stu_t* p = head;
	stu_t* q = head;
	stu_t* k = 0;
	while(1){
		while(p->next != NULL){
			k = p;
			p = p->next;
		}
		p->next = q->next;
		q->next = p;
		k->next = NULL;
		q = p;
		if(q->next == k){break;}
	}
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

int main(){
	stu_t* head = init_stu();
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	print_all(head);
	printf("\n\n");
	reverse(head);
	print_all(head);
	return 0;
}
