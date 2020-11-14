#include<stdio.h>

typedef struct Student stu_t;

typedef struct Score{
	int chinese;
	int math;
	int english;
}score_t;

struct Student{
	char name[20];
	int id;
	score_t score;
};

int main(){
	score_t score = {80,85,90};
	stu_t zhangsan = {"张三",190801,score};
	stu_t lisi = {"李四",190802,{70,75,80}};
	stu_t wangwu = {"王五",190803,100,100,100};

	stu_t* plisi = &lisi;

	printf("李四的语文成绩为:%d\n",(*plisi).score.chinese);
	return 0;
}
