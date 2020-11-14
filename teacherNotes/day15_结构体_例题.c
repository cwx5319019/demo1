/*
	既然已经学习完了结构体，那么，我们现在就有一个完整的手段去存储任意结构的数据
*/
/*
	函数名：system
	函数参数：const char* cmd字符串
	函数功能：将 cmd中的内容，当做shell指令在终端上直接执行，如果cmd中的内容不是一条shell指令，则终端显示没有找到该指令4
	也就是说，如果想要在代码中执行shell指令的话，直接调用system函数并且传入想要执行的shell指令即可
*/

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<user.h>

int main(){
	char data[20] = {0};
	getstring(data,20);
	int num = atoi(data);
	printf("num = %d\n",num);
/*
	atoi这个函数，会去寻找字符串中的非数字字符，寻找到之后，将该非数字字符之前的所有数字字符转换成一个整型数
*/
	return 0;
}

#endif
#if 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<user.h>

typedef struct Score{
	int chinese;
	int math;
	int english;
}score_t;

typedef struct Student{
	char name[20];
	char pswd[20];
	int id;
	score_t score;
}stu_t;

typedef int (*comp_t)(stu_t,stu_t);

void insert_stu(stu_t* stuDB,int* len){
	int id = 190801;
	stu_t newst = {0};
	printf("请输入学生姓名:");
	getstring(newst.name,20);
	//printf("请输入语数外成绩:");
	//scanf("%d %d %d",&newst.score.chinese,&newst.score.math,&newst.score.english);
//	while(getchar()!=10);
	strcpy(newst.pswd,"123456");
	newst.id = id + *len;

	stuDB[*len] = newst;
	(*len)++;
}



void print_all_stu(stu_t* DB,int len){
	int i = 0;
	for(i=0;i<len;i++){
		printf("***************\n");
		printf("姓名:    %s\n",DB[i].name);
		printf("密码:    %s\n",DB[i].pswd);
		printf("学号:    %d\n",DB[i].id);
		printf("语文成绩: %d\n",DB[i].score.chinese);
		printf("数学成绩: %d\n",DB[i].score.math);
		printf("英语成绩: %d\n",DB[i].score.english);		
	}
	printf("***************\n");
}

/*
	查询函数返回下标位置
	可以根据姓名或者学号来进行查询
*/
int find_stu(stu_t* DB,int len){
	char data[20] = {0};
	printf("请输入学生的姓名或者学号:");
	getstring(data,20);
	int num = atoi(data);
	int i = 0;
	//如果输入的是姓名，atoi的结果就是0，如果输入的是学号，那么atoi的结果就是学号本身
	for(i=0;i<len;i++){
		//三目运算符，如果num!=0，意味着输入的是学号，则直接使用num==DB[i].id进行整型数比较，反之，进行字符串的比较
		if((num!=0)?(num==DB[i].id):(strcmp(data,DB[i].name)==0)){
			return i;
		}
	}
	return -1;
}



void print_stu(stu_t* DB,int len){
	int pos = find_stu(DB,len);
	if(pos<0){
		printf("查无次生\n");
		return ;
	}
	printf("***************\n");
	printf("姓名:    %s\n",DB[pos].name);
	printf("密码:    %s\n",DB[pos].pswd);
	printf("学号:    %d\n",DB[pos].id);
	printf("语文成绩: %d\n",DB[pos].score.chinese);
	printf("数学成绩: %d\n",DB[pos].score.math);
	printf("英语成绩: %d\n",DB[pos].score.english);
	printf("***************\n");
}

void update_stu(stu_t* DB,int len){
	int pos = find_stu(DB,len);
	if(pos<0){
		printf("查无此生\n");
		return ;
	}
	printf("请输入该生的新的三科成绩:");
	scanf("%d %d %d",&DB[pos].score.chinese,&DB[pos].score.math,&DB[pos].score.english);
}

int comp_total(stu_t a,stu_t b){
	return a.score.chinese + a.score.math + a.score.english - (b.score.chinese + b.score.math + b.score.english);
}

int comp_chinese(stu_t a,stu_t b){
	return a.score.chinese - b.score.chinese;
}

int comp_math(stu_t a,stu_t b){
	return a.score.math - b.score.math;
}

int comp_english(stu_t a,stu_t b){
	return a.score.english - b.score.english;
}

void bubblesort(stu_t* DB,int len,comp_t comp){
	int i = 0,j = 0;
	stu_t temp = {0};
	for(i=0;i<len-1;i++){
		for(j=0;j<len-1;j++){
			if(comp(DB[j],DB[j+1])<0){
				temp = DB[j];
				DB[j] = DB[j+1];
				DB[j+1] = temp;
			}
		}
	}
}

void remove_stu(stu_t* DB,int* len){
	int pos = 0;
	char data[20] = {0};
	int num = 0;
	int i = 0,j = 0;
	printf("请输入要删除的学生的姓名或者学号:");
	getstring(data,20);
	num = atoi(data);
		for(i=0;i<*len;){
			if((num!=0)?(num==DB[i].id):(strcmp(data,DB[i].name)==0)){
				for(j=i;j<*len-1;j++){
					DB[j] = DB[j+1];
				}
				memset(&DB[j],0,sizeof(stu_t));
				(*len)--;
			}else{
				i++;
			}
		}
}



int main(){
	stu_t* stuDB = calloc(50,sizeof(stu_t));
	comp_t comp_arr[4] = {comp_total,comp_chinese,comp_math,comp_english};
	int len = 0;
	int ch = 0;
	while(1){
		printf("1:添加学生\n");
		printf("2:查看所有学生\n");
		printf("3:根据姓名或者学号查询学生\n");
		printf("4:排序学生\n");
		printf("5:修改学生信息\n");
		printf("6:删除学生\n");
		printf("请选择:");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				insert_stu(stuDB,&len);
				system("clear");
				break;
			case 2:
				system("clear");
				print_all_stu(stuDB,len);
				printf("\n\n");
				break;
			case 3:
				system("clear");
				print_stu(stuDB,len);
				printf("\n\n");
				break;
			case 4:{
				system("clear");
				int ch = 0;
				printf("1:按总成绩排序\n");
				printf("2:按语文成绩排序\n");
				printf("3:按数学成绩排序\n");
				printf("4:按英语成绩排序\n");
				printf("请选择:");
				scanf("%d",&ch);
				while(getchar()!=10);
//comp_t comp_arr[4] = {comp_total,comp_chinese,comp_math,comp_english};
				bubblesort(stuDB,len,comp_arr[ch-1]);
				system("clear");
				break;
			}
			case 5:
				update_stu(stuDB,len);
				break;
			case 6:
				remove_stu(stuDB,&len);
				system("clear");
				break;
			default:
				break;
		}
	}
	return 0;
}

#endif
#if 0

	编写一个水果管理系统，要求：
		系统中有两种身份的人
		①摊主
			摊主拥有功能：摊主使用固定的账号和密码登录系统
				1：上架水果
				2：修改水果单价
				3：补充水果库存
				4：下架水果
				5：根据销量最高的水果排序
				6：查看已经上架在售水果
		②用户
			用户拥有功能：
				1：注册登录
				2：查看所有在售水果列表
				3：选择在售水果列表中的某一个水果，具体重量加入购物车
				4：修改购物车中购买的水果重量
				5：删除购物车中某个水果
				6：结算购物车
*/
/*
	这个项目，总共需要3个数组来实现：
		① 摊主上架的水果信息
		② 用户的账号密码
		③ 用户的水果购物车
	其中，数组②相对独立，数组①和数组③练习较大
*/

#endif














