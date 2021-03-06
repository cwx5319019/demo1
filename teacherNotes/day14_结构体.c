/*
	结构体：结构体是用由多个相同或者不同的变量复合而成的一个自定义数据类型。
	那么如何去自定义一个结构体类型呢：
	举例：现在想要自定义一个结构体类型用来专门形容一个人：
		struct Human{
			int heigth;
			int weight;
			int age;
			char name[20];
			char sex;
		};
	所以，该结构体就是由3个int数据,1个char数组，1个char数据所复合而成的新的数据类型
	所以，只要使用该数据类型创建出来的所有变量，都会拥有以上5种数据
	注意：该结构体的结构体类型是 struct Human , 他的使用方式，就相当于int，char，double一样
*/
/*
	结构体的内存管理方式：
		结构体分配内存的时候，都是遵循字节对齐原则：
			结构体并不是一口气将所有的内存开辟出来，而是先开辟最大成成员的内存(案例中最大类型为double 8个字节),然后从第一个成员开始存储，如果这8个字节不够存储的话，则继续开辟8个字节来存储，直到所有成员存储完毕
		注意：字节对齐原则，严格遵循8,4,2,1对齐
*/
/*
	结构体的访问方式：访问结构体并不是最终目的，最终目的是通过结构体访问到结构体内部的属性
	如何访问结构体内部的属性：结构体变量.结构体属性，就能访问到该结构体的该属性,这里的'.'也是一个运算符，优先级最高
*/
/*
	结构体中，允许存放任何类型的数据
	但是，唯独不允许存放结构体自身类型
*/
/*
	联合体:联合体使用方式和结构体一模一样，自定义的时候只需要将struct更换成union即可
	联合体和结构体的区别就在于他们的内存管理方式
*/
/*
	枚举：
		enum type{

		};
*/


#if 0
#include<stdio.h>

typedef struct Human{
	int age;
	int weight;
	int height;
	char name[20];
	char sex;
}human_t;

int main(){
	int age = 10;
	int weight = 50;
	int height = 150;
	char name[20] = "张三";
	char sex = 'M';	
	struct Human zhangsan = {age,weight,height,"张三",sex};
	human_t lisi = {0};
	//printf("姓名:%s\n",zhangsan.name);
	//printf("年龄:%d\n",zhangsan.age);
	//printf("性别:%c\n",zhangsan.sex);
	lisi = zhangsan;
	//shuman_t temp = {0};
	//lisi = temp;
	//memset(&lisi,0,sizeof(lisi));
	printf("姓名:%s\n",lisi.name);
	printf("年龄:%d\n",lisi.age);
	printf("性别:%c\n",lisi.sex);
	return 0;
}

#endif
#if 0
#include<stdio.h>

typedef struct type1{
	int a;//4
	double b;//8
	char c;//4
	int d;//4
	int e;//4
	float f;//4
	double g;//8
}type_1;

typedef struct type2{
	double a;
	short b;
	int c;
	short d;
}type_2;

typedef struct type3{
	int a[25];//12*8+8 = 96+8=104
	double b;//8
	int c[25];//12*8+8 = 104
}type_3;

int main(){
	printf("%lu\n",sizeof(type_3));
	return 0;
}

#endif
#if 0
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

#endif
#if 0
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

#endif
#if 0
typedef union Data{
	int a ;
	int b ;
	int c ;
}data_t;

int main(){
	data_t data = {0};
	data.a = 1;
	printf("a = %d\n",data.a);
	data.b = 2;
	printf("a = %d,b = %d\n",data.a,data.b);
	data.c = 3;
	printf("a = %d,b = %d,c = %d\n",data.a,data.b,data.c);

	printf("%lu\n",sizeof(data));
	return 0;
}

#endif
#if 0
#include<stdio.h>

enum Type{
	a=5,//默认从0开始
	b,
	c,
	d
};

int main(){
	enum Type type = b;
	printf("type = %d\n",type);
	return 0;
}

#endif
#if 0
/*
	自定义两个结构体，分别为英雄结构体和怪物结构体。
	两个结构体暂时拥有属性：攻击力atk，防御力def，生命值hp，速度值spd，速度累加值_spd
	创建一个英雄变量和一个怪物变量，让英雄和怪物互相攻击，直到一方倒下为止
	攻击方式：速度值高的先判断是否攻击，速度累加值超过50，才可以攻击，如果速度累加值不满50，则当前回合 速度累加值类加上当前的速度值(_spd += spd)。当攻击结束后，速度累加值清0
	伤害值 = 攻击方的攻击力 - 防御方的防御力
	如果攻击方的攻击力 <= 防御方的防御力，则伤害值 = 1
	英雄的初始值：hp = 20 ，atk = 5, def = 15, spd = 5
	怪物的初始值: hp = 15 ，atk = 17 ,def = 2 , spd = 2 
*/
#endif














