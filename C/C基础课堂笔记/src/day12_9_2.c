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
	struct Student* next;
	struct Student* prev;
}stu_t;

stu_t* init_stu(){
	stu_t* head = malloc(sizeof(stu_t));
	memset(head,0,sizeof(stu_t));
	head->data.id = 190800;
	head->next = NULL;
	head->prev = NULL;
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
	head->prev = newstu;
	newstu->prev = p;
}
void print_stu(stu_t* head){
	stu_t* p = head->next;
	while(p != NULL ){
		printf("*******************\n");
		printf("%s \n",p->data.name);
		printf("%d \n",p->data.id);
		printf("*******************\n");
		p = p->next;
	}
	
}
int main(){
	stu_t* head = init_stu();
	//load_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	print_stu(head);
	return 0;
}
