#include<stdio.h>
#include<stdlib.h>
#include<user.h>
#include<string.h>

typedef struct Data
{
	char name[20];
	int id;
}data_t;

typedef struct Student {
	data_t data;
	struct Student* next;
}stu_t;

void getstring(char* str, int len){
	fgets(str,len,stdin);
	int pos = strlen(str);
	if(str[pos-1] == '\n'){
		str[pos -1] = 0;
	}
}
void insert(stu_t* head){
	stu_t* newstu = malloc(sizeof(stu_t));
	memset(newstu,0,sizeof(stu_t));
	printf("请输入学生姓名:");
	getstring(newstu->data.name,20);
	static int id = 190801;
	newstu->data.id = id;
	stu_t* p = head;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = newstu;
	newstu->next = NULL;
	id ++;
	
}

stu_t* head_1(){
	stu_t* head = malloc(sizeof(data_t));
	memset(head,0,sizeof(stu_t));
	head->next = NULL;
	return head;
}

void print(stu_t* head){
	stu_t* p = head;
	while(p->next != NULL){
		printf("%s\n",p->next->data.name);//下一个节点的地址
		printf("%d\n",p->next->data.id);
		p = p-> next;
	}
}

void free_1(stu_t* head){
	stu_t* p = head;
	while(p->next != NULL){
		p = p ->next;
		free(p);
	}
	free(head);

}

stu_t* find(stu_t* head){
	char ch[20] = {0}; 
	printf("请输入要查询的学生的姓名或学号：");
	getstring(ch,20);
	int num = atoi(ch);
	stu_t* p = head->next;  //p单纯的是指针
	while(p != NULL){
		if((num == 0)?(strcmp(ch,p->data.name)==0):(num == p->data.id)){
			return p;
		}
		
		p = p->next;
	}
	return NULL;
}

void bubble_data(stu_t* head){
	stu_t* p = head->next;
	stu_t* q = head->next;
	data_t temp = 0;
	while( p ->next != NULL){
		q = head->next;
		while(q->next != NULL){
			if(p->data > p->next->data){
				temp = p->data;
				p -> data = p->next->data;
				q -> next->data = temp;
			}
			p = p->next;
		}
		p = p->next;
	}
}


void save(stu_t* head){
	FILE* fp = fopen("./DB.txt","w");
	stu_t* p = head->next;
	while(p != NULL){
		fwrite(&(p->data),sizeof(data_t),1,fp);
		p = p->next;
	}
	fclose(fp);
}




void load(stu_t* head ){
	FILE* fp = fopen("./DB.txt","r");
	if(fp == NULL)return ;
	stu_t* p = head; //最好是头节点，因为怕它也是尾节点
	data_t data = {0};
	while(p->next != NULL){
		p = p->next;
	}
	while(1){
		int res = fread(&data,sizeof(data_t),1,fp);
		if(res == 0)break;
		stu_t* newstu = malloc(sizeof(data_t));
		memset(newstu,0,sizeof(stu_t));
		newstu->data = data; //把东西存到数据库
		p->next = newstu;
		newstu ->next =  NULL;
		p = p->next;  //p的指向尾节点也可一是指向newstu
		
	}
	fclose(fp);
}
void delete(stu_t* head){
	printf("请输入要删除的学生名字或学号");
	char ch[20] = {0};
	getstring(ch,20);
	int num = atoi(ch);
	stu_t* p = head;
	stu_t* temp = 0;
	while(p->next!= NULL){
		if(num == 0? strcmp(ch,p->next->data.name)==0:(num == p->next->data.id)){
			temp = p->next;
			p->next = p->next->next;
			free(temp);
		}else{
			p = p->next;
		}
	}
}	


int main()
{
	stu_t* head = head_1();
	while(1){
		//load( head);
		insert(head);
		insert(head);
		insert(head);
		print( head);
		/*
		stu_t* res = find(head);
		if(res != NULL){  //不是res -> next
			printf("%s\n",res->data.name);
		}
		*/
		//save(head);
		//delete(head);
		print(head);
	}
		free_1(head);
	

	return 0;
}


















