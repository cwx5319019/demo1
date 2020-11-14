/*
自定义两个结构体，分别为英雄结构体和怪物结构体。
	两个结构体暂时拥有属性：攻击力atk，防御力def，生命值hp，速度值spd，速度累加值_spd
	创建一个英雄变量和一个怪物变量，让英雄和怪物互相攻击，直到一方倒下为止
	攻击方式：速度值高的先判断是否攻击，速度累加值超过50，才可以攻击，如果速度累加值不满50，则当前回合 速度累加值类加上当前的速度值(_spd += spd)。当攻击结束后，速度累加值清0
	伤害值 = 攻击方的攻击力 - 防御方的防御力
	如果攻击方的攻击力 <= 防御方的防御力，则伤害值 = 1
	英雄的初始值：hp = 20 ，atk = 5, def = 15, spd = 5
	怪物的初始值: hp = 15 ，atk = 17 ,def = 2 , spd = 2 

	要求②
		设计闯关系统：当英雄击败1个怪物之后，会有更加强大的怪物来袭
		怪物的属性上浮方式：
			hp：3~6
			akt：1~3
			def：0~4
			spd：1~2
		英雄每击败1个怪物，获得2个技能点，每1个技能点对应
			+5 hp
			+2 atk
			+2 def
			+1 spd
		并且固定获得 +2hp，+1atk，+1def
		英雄持续闯关，直到失败为止
	要求③
		为怪物添加技能系统
			技能1：普通攻击
			技能2：降低英雄 2 点攻击力
			技能3：降低英雄 2 点防御力
			技能4：根据英雄的防御力造成比例伤害，伤害为英雄防御力超过怪物攻击力的数值/怪物攻击力*英雄当前血量
		要求：3个技能随机释放
			技能1的释放概率是技能2,3,4的两倍
			一旦英雄遭到neff，3回合之内不能再次受到相同的neff，也就是说，在减益效果持续中，怪物再次释放相同的减益效果，会显示施法失败
			每第4只怪物，怪物的减益效果就会增加2
			减益效果结束后，英雄属性恢复，怪物再次释放减益效果才会成功。
			英雄击败怪物后，减益效果直接结束
		要求4：
			为英雄设计技能：
			技能1：普通攻击，获得5点怒气
			技能2：吸血攻击，造成普通攻击最终伤害的80%的伤害，并且恢复伤害值的一半的生命值
			技能3：舍身攻击，消耗自身20%当前生命值，造成250%的普通攻击的最终伤害，并且获得10点怒气
			当英雄被攻击时，收到伤害超过当前生命值20%的话，就会获得10点怒气，反之获得5点怒气
			终结技：怒气达到100时，允许释放终结技，造成150%的无视防御力的伤害,并且清空怒气。如果成功击杀目标，返回50%怒气
			要求，当怒气不满的时候，终结技显示为红色，并且无法释放


*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<user.h>

typedef struct Hero hero_t;
typedef struct Monster mon_t;

struct Hero{
	int hp;
	int atk;
	int def;
	int spd;
	int _spd;
	int neff_atk_time;
	int neff_def_time;
};

struct Monster{
	int hp;
	int atk;
	int def;
	int spd;
	int neff;
	int _spd;
	void (*atk_meth[5])(hero_t*,mon_t*);
};

void hero_oper(hero_t* hero,mon_t* mon){
	int demage = hero->atk - mon->def;
	if(demage<=0){
		demage = 1;
	}
	mon->hp -= demage;
	printf("英雄攻击了怪物，造成了%d点伤害\n",demage);
	printf("怪物剩余血量:%d\n",mon->hp);
	printf("\n\n");
	if(hero->neff_atk_time > 0){
		hero->neff_atk_time --;
		if(hero->neff_atk_time == 0){
			hero->atk += mon->neff;
		}
	}

	if(hero->neff_def_time > 0){
		hero->neff_def_time --;
		if(hero->neff_def_time == 0){
			hero->def += mon->neff;
		}
	}	
	//sleep(1);
}

void  mon_skill_1(hero_t* hero,mon_t* mon){
	int demage = mon->atk - hero->def;
	if(demage<=0){
		demage = 1;
	}
	hero->hp -= demage;
	printf("怪物攻击了英雄，造成了%d点伤害\n",demage);
	printf("英雄剩余血量:%d\n",hero->hp);
	printf("\n\n");
	//sleep(1);
}

void mon_skill_2(hero_t* hero,mon_t* mon){
	if(hero->neff_atk_time > 0){
		printf("施法失败\n");
		return ;
	}
	printf("怪物降低了英雄 %d 点攻击力\n",mon->neff);
	hero->atk -= mon->neff;
	hero->neff_atk_time = 3;
}

void mon_skill_4(hero_t* hero,mon_t* mon){
	int temp = mon->atk / 1.85;
	mon->atk -= temp;
	int demage = (hero->def - mon->atk)/mon->atk * hero->hp;
	if(demage<=0){
		demage = 1;
	}
	hero->hp -= demage;
	mon->atk += temp;
	printf("怪物对英雄发动了防御比例攻击，造成了%d点伤害\n",demage);
	printf("英雄剩余血量:%d\n",hero->hp);
}

void mon_skill_3(hero_t* hero,mon_t* mon){
	if(hero->neff_def_time > 0){
		printf("施法失败\n");
		return ;
	}
	printf("怪物降低了英雄 %d 点防御力\n",mon->neff);
	hero->def -= mon->neff;
	hero->neff_def_time = 3;
}

void mon_oper(hero_t* hero,mon_t* mon){
	int pos = rand()%5;
	mon->atk_meth[pos](hero,mon);
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
	static int hp = 15,atk = 17,def = 2,spd = 2,neff = 2;
	static int count = 2;
	int _hp = rand()%4+2;
	int _atk = rand()%3+1;
	int _def = rand()%5;
	int _spd = rand()%2+1;
	hp += _hp;
	atk += _atk;
	def += _def;
	spd += _spd;
	mon_t mon = {hp,atk,def,spd,neff};
	if(count%3==0){
		neff += 2;
	}
	mon.atk_meth[0] = mon_skill_1;
	mon.atk_meth[1] = mon_skill_1;
	mon.atk_meth[2] = mon_skill_2;
	mon.atk_meth[3] = mon_skill_3;
	mon.atk_meth[4] = mon_skill_4;
	printf("更强大的怪物来袭:\n");
	printf("h p : %2d\n",hp);
	printf("atk : %2d\n",atk);
	printf("def : %2d\n",def);
	printf("spd : %2d\n",spd);
	printf("\n\n");
	while(getch()!=10);
	count++;
	return mon;
}

void hero_lv_up(hero_t* hero){
	printf("\033[0m");
	hero->atk += 1;
	hero->def += 1;
	hero->hp += 2;
	printf("获得2点技能点，请选择分配方式:\n\n");
	int ch = 0;
	for(int i=0;i<2;i++){
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

int main(){
	srand(time(0));
	hero_t hero = {20,5,15,5};
	mon_t mon = {15,17,2,2,2,0,{mon_skill_1,mon_skill_1,mon_skill_2,mon_skill_3,mon_skill_4}};	
	while(1){
		Round(&hero,&mon);
		if(mon.hp <= 0){
			if(hero.neff_atk_time != 0){
				hero.atk += mon.neff;
				hero.neff_atk_time = 0;
			}
			if(hero.neff_def_time != 0){
				hero.def += mon.neff;
				hero.neff_def_time = 0;
			}
			mon = create_mon();
			hero_lv_up(&hero);
		}
		if(hero.hp <= 0){
			printf("游戏结束\n");
			return 0;
		}
	}
	return 0;
}
