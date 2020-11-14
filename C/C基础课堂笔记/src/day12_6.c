#if 0
	结构体
		符合类型
		
	形容一个人
	struct Human {
		int height;
		int weight;
		int age;
		char name[20];
		char sex;
	}
	
	该框架并不占内存，和int一样，使用框架创建的变量，都会拥有以上5种类型 
			类型是struct Human ，不是struct  也不是Human
			
	结构体内存管理
		64位
			一次最多发送8字节 先开辟最大类型字节，容不下在开最大类型内存
		32位
			一次最多发送4字节 对于double8字节则是发送2次
		注意：字节对齐，严格按照8，4，2，1对齐  对半分
	
	结构体访问方式
		结构体变量.结构体属性   ‘.’优先级除了（）外最高  ++比 * 高
	
	结构体不能互相嵌套
		可以放指针 指针开始就已经开辟好字节数
		
	联合体
		只开辟一个最大字节
		
	枚举
		







#endif
#if 0
#include<stdio.h>
typedef struct Human {
	int height;
	int weight;
	int age;
	char name[20];
	char sex;
}human_t;    //加以个_t 类型别名

int main()
{
	int height = 160;
	int weight = 50;
	int age = 30;
	char name[20] = "zhangsan";
	char sex = 'M';

	//struct Human zhangsan = {age,weight,age,"zhangsan",sex};   //初始化方式1  "zhangsan" 不能是name 解释在下面
	human_t zhangsan = {0};                                      //初始化方式2
	
	
/*
	name1 = "zhangsan";
	name[20] = name1;  //这就是把指针给了整数；name[20] 是整数，name1是指针
	
*/	

	//printf("身高：%d\n",zhangsan.height);
	//printf("体重：%d\n",zhangsan.weight);
	//printf("姓名：%s\n",zhangsan.name);
	
	human_t lisi = zhangsan;
	
	printf("身高：%d\n",lisi.height);
	printf("体重：%d\n",lisi.weight);
	printf("姓名：%s\n",lisi.name);


	return 0;
}	
		
#endif
#if 0
#include<stdio.h>
typedef struct type {   //64位   32位
	int a;   		 	//8	     4	
	double b; 			//8		 4+4
	char c;    			//8  	 4
	int d;					   //4
	int e;     			//8 	 4
	float f;				   //4
	double g;  			//8    //4+4
					//总字节40  //总字节36
	
}type_1;

int main()
{
	printf("%lu\n",sizeof(type_1));
	return 0;
}

#endif
#if 0
#include<stdio.h>
typedef struct score {
	int chinese;
	int math;
	int english;

}score_t;

typedef struct student {
	char name[20];
	int id;
	score_t* score;
}stu_t;


int main()
{
	score_t score = {80,72,90};
	score_t* pscore = & score;
	
	stu_t zhangsan = {"张三",190801,pscore};
	stu_t* pzhangsan = &zhangsan;
	
	//printf("张三的英语成绩:%d \n",(*pzhangsan).(*score).english);   //不用这种方法 
	printf("张三的英语成绩:%d \n",pzhangsan->score->english);

	return 0 ;
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
#if 1
#include<stdio.h>
#include <unistd.h>
#include<user.h>

typedef struct Hero{
	int atk;
	int def;
	int hp;
	int spd;
	int _spd;
}Hero_t;

typedef struct Mons{
	int atk;
	int def;
	int hp;
	int spd;
	int _spd;
	
}Mons_t;
Mons_t create_mons(){
	//printf("\033[1;31;10m");
	static int hp = 15,atk = 17,def = 2,spd = 2;
	int _hp = rand()%4+2;
	int _atk = rand()%4+1;
	int _def = rand()%6;
	int _spd = rand()%2+1;
	hp += _hp;
	atk += _atk;
	def += _def;
	spd += _spd;
	Mons_t mons = {atk,def,hp,spd};
	printf("更强大的怪物来袭:\n");
	printf("atk : %2d\n",atk);
	printf("def : %2d\n",def);
	printf("h p : %2d\n",hp);
	printf("spd : %2d\n",spd);
	printf("\n\n");
	while(getch()!=10);
	return mons;
}

void hero_opra(Mons_t* pmons,Hero_t* phero){
	if(phero-> _spd  >= 50){
		if(phero->atk > pmons->def){
			int x =  phero->atk - pmons->def;
			printf("怪物受到%d伤害\n",x);
			pmons -> hp -=  x;
			printf("怪物剩余%d血量\n",pmons -> hp);
			if(pmons -> hp <= 0){
				printf("mons died\n");
				//create_mons();
			}
			phero->_spd = 0;
		}else{
			phero-> hp -= 1;
			if(phero -> hp <= 0){
				printf("hero died\n");
				return ;
			}
		}
	}else{
		phero->_spd +=phero->spd;
	}
}

void mons_opra(Mons_t* pmons,Hero_t* phero){
	if(pmons-> _spd  >= 50){
		if(pmons->atk > phero->def){
			int y =  pmons->atk - phero->def;
			printf("英雄受到%d伤害\n",y);
			phero -> hp -=  y;
			printf("英雄剩余血量%d\n",phero -> hp);
			if(phero -> hp <= 0){
				printf("hero died\n");
			}
			pmons->_spd = 0;
		}else{
			pmons-> hp -= 1;
			if(pmons -> hp <= 0){
				printf("mons died\n");
				return ;
			}
		}
	}else {
		pmons->_spd += pmons->spd;
	}
}



int main()
{
	Hero_t hero = {5,15,20,5};
	Hero_t* phero = &hero;
	
	Mons_t mons = {17,2,15,2};
	Mons_t* pmons = &mons;
	while(1){
		if(phero-> spd > pmons-> spd){
			hero_opra(&mons,&hero);
			
		}else{
			mons_opra(&mons,&hero);
		}
		if(hero.hp<=0){
			printf("游戏结束\n");
			break;
		}
		if(mons.hp<=0){	
			mons = create_mons();
			printf("\033[0m");
		}
	}

	return 0;
}


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

#if 0
#include<stdio.h>
#include <unistd.h>
#include<user.h>

typedef struct Hero{
	int hp;
	int atk;
	int def;
	int spd;
	int _spd;
}hero_t;

typedef struct Mons{
	int hp;
	int atk;
	int def;
	int spd;
	int _spd;
	
}mon_t;

void print_hero_data(hero_t hero){
	printf("\n***********************\n");
	printf("h p : %2d\n",hero.hp);
	printf("atk : %2d\n",hero.atk);
	printf("def : %2d\n",hero.def);
	printf("spd : %2d\n",hero.spd);
	printf("***********************\n");
}
mon_t create_mon(){
	printf("\033[1;31;10m");
	static int hp = 15,atk = 17,def = 2,spd = 2;
	int _hp = rand()%4+2;
	int _atk = rand()%4+1;
	int _def = rand()%6;
	int _spd = rand()%2+1;
	hp += _hp;
	atk += _atk;
	def += _def;
	spd += _spd;
	mon_t mon = {hp,atk,def,spd};
	printf("更强大的怪物来袭:\n");
	printf("h p : %2d\n",hp);
	printf("atk : %2d\n",atk);
	printf("def : %2d\n",def);
	printf("spd : %2d\n",spd);
	printf("\n\n");
	while(getch()!=10);
	return mon;
}
void hero_lv_up(hero_t* hero){
	printf("\033[0m");
	hero->atk += 1;
	hero->def += 1;
	hero->hp += 2;
	printf("获得2点技能点，请选择分配方式:\n\n");
	int ch = 0;
	int i=0;
	for( i=0;i<2;i++){
		printf("1: + 2 atk\n");
		printf("2: + 2 def\n");
		printf("3: + 5 h p\n");
		printf("4: + 1 spd\n");
		printf("5:显示属性\n");
		printf("\n");
		while(1){
			ch = getch()-'0';
			if(ch>=1 && ch<=5){
				break;
			}
		}
		switch(ch){
			case 1:
				hero->atk += 2;
				break;
			case 2:
				hero->def += 2;
				break;
			case 3:
				hero->hp += 5;
				break;
			case 4:
				hero->spd += 1;
				break;
			case 5:
				print_hero_data(*hero);
				i--;
				break;
		}
	}
}

void hero_oper(hero_t* hero,mon_t* mon){
	int demage = hero->atk - mon->def;
	if(demage<=0){
		demage = 1;
	}
	mon->hp -= demage;
	printf("英雄攻击了怪物，造成了%d点伤害\n",demage);
	printf("怪物剩余血量:%d\n",mon->hp);
	printf("\n\n");
	sleep(1);
}

void mon_oper(hero_t* hero,mon_t* mon){
	int demage = mon->atk - hero->def;
	if(demage<=0){
		demage = 1;
	}
	hero->hp -= demage;
	printf("怪物攻击了英雄，造成了%d点伤害\n",demage);
	printf("英雄剩余血量:%d\n",hero->hp);
	printf("\n\n");
	sleep(1);
}

void Round(hero_t* hero,mon_t* mon){
	if(hero->spd >= mon->spd){
		if(hero->_spd >= 50){
			printf("\033[0m");
			hero_oper(hero,mon);
			hero->_spd = 0;
		}else{
			hero->_spd += hero->spd;
		}
		if(mon->hp<=0){return;}
		if(mon->_spd >= 50){
			printf("\033[1;31;10m");
			mon_oper(hero,mon);
			mon->_spd = 0;
		}else{
			mon->_spd += mon->spd;
		}
	}else{
		if(mon->_spd >= 50){
			printf("\033[1;31;10m");
			mon_oper(hero,mon);
			mon->_spd = 0;
		}else{
			mon->_spd += mon->spd;
		}
		if(hero->hp<=0){return;}
		if(hero->_spd >= 50){
			printf("\033[0m");
			hero_oper(hero,mon);
			hero->_spd = 0;
		}else{
			hero->_spd += hero->spd;
		}
	}
}


int main(){
	hero_t hero = {20,5,15,5};
	mon_t mon = {15,17,2,2};
	while(1){
		Round(&hero,&mon);
		if(mon.hp<=0){
			hero_lv_up(&hero);
			mon = create_mon();
			
		}else if (hero.hp<=0){
			printf("\033[0m");
			printf("游戏结束\n");
			break;		
		}
	}
	return 0;
}


#endif




