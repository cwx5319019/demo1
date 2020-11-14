/*
	学生系统增删改查 
	atoi ascii 码转化为 int型
		12asd3 转化为 12
		abc12  转化为 0
		
	system("clear")  自动清屏
	在代码中执行shell指令 直接上面的格式
	


*/


#if 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<user.h>

typedef struct Score{
	int chinese ;
	int math ;
	int english;

}score_t;
typedef struct Student{
	char name;
	char pswd;
	int id;
	score_t score;

}stu_t;

int find_stu(stu_t* DB,int len){
	char data[20] ={0};
	printf("请输入学生学号或者姓名：");
	getstring(data,20);
	int num = atoi(data);
	int i = 0;
	for(i = 0;i<len;i++){
		if((num != 0)? (num==DB[i].id):(strcmp(data,DB[i].name)==0)){
			return i;
		}
	}
	return -1;
}
void insert_stu(stu_t* stuDB,int* len)
{
	int id = 190801;
	stu_t newst = {0};
	printf("请输入学生姓名：");
	getstring(newst,20);
	printf("请输入语文数学外语成绩：");
	scanf("%d %d %d ",&newst.score.chinese,&newst.score.math,&newst.score.english);
	while(getchar() != 10);
	strcpy(newst.pswd,"123456");
	newst.id = id + *len;
	
	stuDB[*len] = newst;
	(*len)++;
}	




void print_stu(stu_t* DB,int len){
	int pos = find_stu(DB,len);
	if(pos<0){
		printf("查无此生\n");
		return ;
	}
	printf("******************\n");
	printf("姓名：     %s\n",DB[pos].name);
	printf("密码：     %s\n",DB[pos].pswd);	
	printf("学号：     %d\n",DB[pos].id);	
	printf("语文成绩：     %d\n",DB[pos].score.chinese);	
	printf("数学成绩：     %d\n",DB[pos].score.math);
	printf("英语成绩：     %d\n",DB[pos].score.english);	
	printf("******************\n");	
}


int main(){
	stu_t* stuDB = calloc(50,sizeof(stu_t));
	int len = 0;
	int ch = 0;
	while(1){
		printf("1.添加学生\n");
		printf("2.查看所有学生\n");
		printf("3.根据学号和姓名查看学生\n");
		printf("4.按总分排序学生\n");	
		printf("6.删除学生\n");	
		printf("请选择：\n");	
		scanf("%d",&ch);
		while(getchar() != 10);
		switch(ch){
			case 1:
				insert_stu(stuDB,&len);
				break;
			case 2:
				print_all_stu(stuDB,len);
				break;
			case 3:
				print_stu(stuDB,len);
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				break;
		}
		
	}
		
	return 0;	

}
























#endif
#if 0


#endif
#if 0


#endif





