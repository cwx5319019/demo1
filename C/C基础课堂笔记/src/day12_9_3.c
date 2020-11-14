//双向循环列表

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
	head->next = head;
	head->prev = head;
	return head;
}

void insert_stu(stu_t* head){
	stu_t* newstu = malloc(sizeof(stu_t));
	memset(newstu,0,sizeof(stu_t));
	printf("请输入学生的姓名:");
	getstring(newstu->data.name,20);
	stu_t* p = head;
	while(p->next != head){
		p = p->next;
	}
	newstu->data.id = p->data.id + 1;
	p->next = newstu;
	newstu->next = head;
	head->prev = newstu;
	newstu->prev = p;
}
void print_stu(stu_t* head){
	stu_t* p = head->next;
	while(p != head ){
		printf("*******************\n");
		printf("%s \n",p->data.name);
		printf("%d \n",p->data.id);
		printf("*******************\n");
		p = p->next;
	}
	
}

void quicksort(stu_t* left,stu_t* right){
	if(left == right || right->next == left)return;
	stu_t* l = left;
	stu_t* r = right;
	stu_t* key = left;
	data_t temp ={0};
	while(l != r){
		while(l != r){
			if(r->data.id > key->data.id){
				break;
			}
			r = r->prev;
		}
		while(l != r){
			if(l->data.id < key->data.id){
				break;
			}
			l = l->next;
		}
		temp = l->data;
		l->data = r->data;
		r->data = temp;
	}
	temp = key ->data;
	key->data = l->data;
	l->data = temp;
	quicksort(left,l->prev);
	quicksort(l->next,right);
	return ;
}



int main(){
	stu_t* head = init_stu();
	//load_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	insert_stu(head);
	quicksort( head->next,head->prev);
	print_stu(head);
	return 0;
}
