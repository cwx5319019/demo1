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
		printf("%d等奖\n",5-count);
	}else{
		printf("谢谢参与\n");
	}
	return 0;
}
