//单向列表

#if 0
	链表：结构体里存放指针，指向下一个结构体地址，称为链
#endif

#if 1
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
	head->next = NULL;
	return head;
}

void insert_stu(stu_t* head){
	stu_t* newstu = malloc(sizeof(stu_t));
	memset(newstu,0,sizeof(stu_t));
	printf("请输入学生的姓名:");
	getstring(newstu->data.name,20);
	static int id = 190801;
	newstu->data.id = id;
	//寻找尾节点，然后让尾节点的next指向newstu

	stu_t* p = head ;         //p指向head结构体       
	while(p->next != NULL){  
		p = p-> next;
	}
	p->next = newstu;     //p->next更改了结构体内部指针指向
	
	//stu_t* p = head->next ;  //p单纯指向一个指针  head->next 是个指针      
	//while(p != NULL){  
	//	  p = p-> next;
	//}
	//p  = newstu;      //p由指向head->next 指向了newstu
	
	newstu->next = NULL;
/*	
    newstu->next = head -> next;
	head -> next = newstu;
	
	
*/
	id++;
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
void reverse(stu_t* head){
	stu_t* p = head;
	stu_t* q = head;
	stu_t* k = 0;
	while(1){
		while(1){
			k = p;
			p = p->next;
		}
		p->next = q->next;
		q->next = p;
		k->next = NULL;
		q= p;
		if(q->next == k)break;
	
	}



}

void load_stu(stu_t* head){
	FILE* fp = fopen("./DB.txt","r");
	if(fp == NULL)return;
	data_t data = {0};
	int res = 0;
	stu_t* p = head;
	while(p->next != NULL){
		p = p->next;
	}
	while(1){
		res = fread(&data,sizeof(data_t),1,fp);
		if(res == 0)break;
		stu_t* newstu = malloc(sizeof(stu_t));
		memset(newstu,0,sizeof(stu_t));
		newstu->data = data;
		p->next = newstu;
	}
}

int main(){
	stu_t* head = init_stu();
	while(1){
		insert_stu(head);
		print_stu(head);
	}
	return 0;
}
#endif
#if 0

#endif
#if 0

#endif
#if 0

#endif
#if 0

#endif
#if 0

#endif
#if 0

#endif





























