/*
	从键盘输入一个年份，判断是否为闰年(4年一闰，100年不闰，400年又一闰)，如果是如年，则继续输出月份，判断有几天，属于哪个季节(3,4,5为春季)
	如果不是闰年，则提示该年的前一个闰年和后一个闰年是哪两年
*/

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
