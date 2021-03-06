/*
	C语言的代码总共有3种结构形式:
		顺序结构：代码从上到下，从左到右，依次执行(优先级问题不纳入考虑)
		分支结构：根据分支条件，直接跳转到满足条件的分支语句中。这里一定注意是直接跳转，而不是依次判断，满足则跳转
		循环结构：根据给定的循环条件，判断该条件是否满足，满足则执行依次循环语句。不满足则退出该循环。所以循环就会一直执行，直到循环条件不满足为止

	顺序结构中的语句:
		if 判断语句
		语法结构: if(判断条件){
					语句；
				}剩余代码
		分析：如果“判断条件”为真，则执行“语句”，执行完成后，再执行“剩余代码”，如果“判断条件”为假，则直接执行“剩余代码”
		注意：当if语句后面没有{},也没有；的情况下，那么默认紧跟的一条语句属于if语句
		if中就出现了作用域的概念：
			所有的变量，他的有效范围，仅仅在他所申明的{}内，这个{}就是我们所说的作用域。
			小的的作用域，能够使用大的作用域中的数据，大的作用域不能使用专属于小的作用域的数据。
			不同的作用域当中，允许声明相同名字的变量，当出现相同名字变量的时候，访问该变量的时候，会选择离自己最近的作用域进行访问

//-------------------------------
#include<stdio.h>

int main(){
	int a = 5;
	if(1){
		int a = 15;
	}
	printf("a = %d\n",a);    //a = 5  如果if里去掉声明的int  则输出15
	return 0;
}
//---------------------------------
		
		二选一选择语句:
		语法结构 if(判断条件){
					语句1；
				}else{
					语句2；
				}剩余代码;
		分析：当“判断条件”成立，则执行“语句1”，之后再执行“剩余代码”，当“判断条件”不成立，则执行“语句2”，之后再执行“剩余代码”

		多选一选择语句：
		语法结构 if(判断条件1){
					语句1;
				}else if(判断条件2){
					语句2;
				}...else if(判断条件n){
					语句n;
				}else{
					语句0；
				}剩余代码；
		分析：当执行 if else if语句的时候，系统会从“判断条件1”开始，逐一判断哪一条判断语句成立，然后直接执行对应的语句。如果有多条判断语句同时成立，则会执行第一条成立的判断条件对应的语句。如果没有判断条件成立，则执行“语句0”后，执行剩余代码
		
		if系列语句，本身没有任何的逻辑难点，但是当他们嵌套使用的时候，每一个if判断都会被嵌套的if判断的先决条件。
*/


//-----------------练习---------------
/*
	从键盘输入三角形的3条边
	首先判断是否能够构成三角形
		如果能够构成三角形，再判断是等腰还是普通三角形
			如果是等腰三角形再判断是否为等边
		同时判断该三角形是直角，钝角，锐角
*/
/*
#include<stdio.h>

int main(){
	int x = 0,y = 0,z = 0;
	scanf("%d %d %d",&x,&y,&z);
	while(getchar()!=10);
	int bigger = (x>y)?x:y;
	int c = (bigger>z)?bigger:z;
	
	int smaller = (x<y)?x:y;
	int a = (smaller<z)?smaller:z;
	
	int b = x + y + z - a - c;
	if(a+b>c){
		if(a==b||a==c||b==c){
			if(a==b&&b==c){
				printf("等边");
			}else{
				printf("等腰");
			}
		}
		if(a*a+b*b==c*c){
			printf("直角");
		}else if(a*a+b*b<c*c){
			printf("钝角");
		}else{
			printf("锐角");
		}
		printf("三角形\n");
	}else{
		printf("不能构成三角形\n");
	}
	return 0;
}

*/

//-------------------------------------
/*
	从键盘输入一个年份，判断是否为闰年(4年一闰，100年不闰，400年又一闰)，如果是如年，则继续输出月份，判断有几天，属于哪个季节(3,4,5为春季)
	如果不是闰年，则提示该年的前一个闰年和后一个闰年是哪两年
*/
/*
#include<stdio.h>

int main(){
	int year = 0,month = 0,day = 0;
	scanf("%d",&year);
	while(getchar()!=10);
	if((year%4==0&&year%100!=0)||year%400==0){
		printf("请输入月份:");
		scanf("%d",&month);
		while(getchar()!=10);
		if(month==4||month==6||month==9||month==11){
			day = 30;
		}else if(month == 2){
			day = 29;
		}else if(month>12){
			day = 0;
		}else{
			day = 31;
		}
		
		if(month==3||month==4||month==5){
			printf("该月属于春季,");
		}else if(month==6||month==7||month==8){
			printf("该月属于夏季,");
		}else if(month==9||month==10||month==11){
			printf("该月属于秋季,");
		}else if(month>12){
			printf("输入错误,");
		}else{
			printf("该月属于冬季,");
		}
		printf("有%d天\n",day);
	}else{
		int temp = year%4;
		int year1 = year - temp;
		int year2 = year + (4-temp);
		if(year1%100==0 && year1%400!=0){
			year1 -= 4;
		}
		if(year2%100==0 && year2%400!=0){
			year2 += 4;
		}
		printf("离%d年最近的前一个闰年和后一个闰年分别为:%d和%d年\n",year,year1,year2);
		
	}
	return 0;
}
*/

//------------------------------------
/*
	从键盘输入一个数据(如果该数据为数字，则只能是-9~9，如果是单词，只取首字母)
	如果是小写字母，则输出他的大写，如果是大写字母则输出他的小写，如果是-9～9的数组，则输出他的相反数，如果是其他字符，则输出0。
*/

#include<stdio.h>
int main(){
	char data = 0;
	printf("请输入数据:");
	scanf("%c",&data);
	//while(getchar()!=10);
	if(data>='A'&&data<='Z'){
		printf("%c\n",data+32);
	}else if(data>='a'&&data<='z'){
		printf("%c\n",data-32);
	}else if(data>='1'&&data<='9'){
		printf("-%c\n",data);
	}else if(data=='-'){
		scanf("%c",&data);
		if(data==10){
			data = '0';
		}
		printf("%c\n",data);
	}else{
		printf("0\n");
	}
	//while(getchar()!=10);
	return 0;
}

//-----------------------------------
/*
	编写一个开奖系统，中奖号码由4个两位数组成，现在要求，中奖号码随机生成，然后由用户输入购买号码。
	4个号码全中，1等奖
	中3个号码，2等奖
	中2个号码，3等奖
	剩余，谢谢参与
	C语言中随机数如何产生，使用函数rand(),调用了rand()函数之后，rand()整体表达式的值就对应一个随机数,注意，rand()函数产生的随机数是一个天文数，我们需要将他的控制在10~99的范围内,查看rand()函数的头文件 使用 shell 指令 man+3+函数名
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(0));
	int _a = rand()%90+10;
	int _b = rand()%90+10;
	int _c = rand()%90+10;
	int _d = rand()%90+10;
	printf("中奖号码为:%d-%d-%d-%d\n",_a,_b,_c,_d);
	printf("请下注:");
	int a = 0,b = 0,c = 0,d = 0;
	int count = 0;
	scanf("%d-%d-%d-%d",&a,&b,&c,&d);
	while(getchar()!=10);
	count = (a==_a) + (b==_b) + (c==_c) + (d==_d);
	if(count>=2){
		printf("%d等奖\n",
