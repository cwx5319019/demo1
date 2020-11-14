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
	score_t* score;
};

int main(){
	score_t score = {80,85,90};
	score_t* pscore = &score;
	stu_t zhangsan = {"张三",190801,pscore};
	stu_t* pzhangsan = &zhangsan;
	printf("张三的英语成绩为:%d\n",(*pzhangsan).(*score).english);
	printf("张三的数学成绩为:%d\n",pzhangsan->score->math);
	return 0;
}
