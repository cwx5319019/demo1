#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
/*
	分支结构：switch 
		注意：case只负责转入，case里面不能声明（可以加{}限制使用）
	循环语句：while ，for
		几个固定思路
			1.选择
			2.遍历
			3.计数
			4.触发
			5.异常中断


*/	

/*
	int i = 0,j = 0,sum = 0;
	
	for (j = 2 ; j <10000; j++){
		sum = 0;
		for (i = 1;i < j ;i++){
			if (j % i == 0){
				sum +=i ; 
				//printf("%d\n",sum);
			}
		}
		if (sum == j) {
			printf("%d\n",j);
		}		
	}

*/	

/*
//-----------------------------------异常中断

	int i = 0,j = 0;
	for (j = 2 ; j <1000; j++){
		for (i = 1;i <=j ;i++){
			if (j % i == 0){
				break; 
			}
		}
		if (j==i){      //自然结束
			count2++;
			printf("%d",j);
		}
	}
	printf("%d\n",count2);
//-----------------------------------触发法

	int i = 0,j = 0,flag = 0;
	for (j = 2 ; j <1000; j++){
		flag = 0;
		for (i = 1;i <=j ;i++){
			if (j % i == 0){
				flag = 1; 
			}
		}
		if (flag == 0){
			count2++;
			printf("%d",j);
		}
	}
	printf("%d\n",count2);





//------------------------------------计数法
	int i = 0,j = 0,count = 0,count2 = 0;
	
	for (j = 2 ; j <1000; j++){
		count = 0;
		for (i = 1;i <=j ;i++){
			if (j % i == 0){
				count ++; 
			}
		}
		if (count == 2){
			count2++;
			printf("%d",j);
		}
	}
	printf("%d\n",count2);
//--------------------------------------

*/






/*
	 char a = 0;
	//char b = a+1;
	while (a < (char)(a+1)){      //不同数据类计算按精度高的，不强加转化就会成为a < a+1 a是字符型（-128—127），a+1是整型（21亿）  
		a++;
		//b++;
	}
	printf("最大值%d,最小值%d\n",a,(char)(a+1));
	return 0;

*/


/*


//*****************三角金字塔********************
	int i = 0;
	int j = 0;
	for (j = 0; j < 5 ; j++){
		for (i=0 ; i < 5-j ; i++){
			printf(" ");
		}
		for (i= 0 ; i < j+1 ; i++){
			printf("* ");
		}
		printf("\n");
	}

*/



	
/*
//-------------------------------------------------	

	int a = 0,b = 0;
	char c = 0;
	while(1){   
		printf("请输入计算表达式:");
		scanf("%d",&a);
		scanf("%c",&c);
		//printf("%c",c);
			if(c == 'q'){
				return 0;
			}
			else if(c == '+'||c=='-'||c=='+'||c=='%'||c=='/'){
				scanf("%d",&b);
			}
		while(getchar() != 10);
		
		switch (c){
			case '+':
			
			
				printf("%d%c%d=%d\n",a,c,b,a+b);
				break;
			case '-':
				printf("%d%c%d=%d\n",a,c,b,a-b);
				break;	
			case '*':
				printf("%d%c%d=%d\n",a,c,b,a*b);
				break;
			case '/':
				if(b == 0){
					printf("b!=0\n");
					break;
				}else{
					printf("%d%c%d=%g\n",a,c,b,(double)a/b);
					break;
				}
			case '%':
				printf("%d%c%d=%d\n",a,c,b,a%b);
				break;			
			default :
				printf("error\n");
			}
	}												
	
	
*/
/*
//--------------------------
	srand(time(0));
	int num1 = rand()%90+10;
	int num2 = rand()%90+10;
	int num3 = rand()%90+10;
	int num4 = rand()%90+10;
	printf("%d %d %d %d\n",num1,num2,num3,num4);
	int a=0,b=0,c=0,d=0;			
	printf("请输入：");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int counter = 0;
	counter = (num1 == a )+( num2 == b)+(num3 == c)+( num4==d);
	if (counter >= 2 ){
		printf("%d等奖",5-counter);
	}else{
		printf("谢谢参与\n");
	}

*/



/*
	srand(time(0));
	int num1 = rand()%90+10;
	int num2 = rand()%90+10;
	int num3 = rand()%90+10;
	int num4 = rand()%90+10;
	printf("%d %d %d %d\n",num1,num2,num3,num4);
	int a=0,b=0,c=0,d=0;			
	printf("请输入：");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (a == num1 ){
		if (b == num2){
			if (c == num3){
				if (d == num4){
					printf("一等奖\n");
				}else{
					printf("二等奖\n");
				}
			}else {
				printf("三等奖\n");
			}
		}else{
			printf("谢谢参与\n");
		}
		
	}else{
		printf("谢谢参与\n");
	}

*/




/*
	printf(" 请输入：");
	char a = 0;
	scanf("%c",&a);
	//while (getchar() != 10);
	if ('a'<= a && a <= 'z'){
		printf("%c\n",a - 32);
	}else if('A'<= a && a <= 'Z'){
		printf("%c\n",a + 32);
	}else if ('0'<= a && a <= '9'){
		printf("-%c\n",a);
	}else if (a == '-'){
			a = getchar();
			if (a == '0'){
				printf("0\n");
			}else{
				printf("%c\n",a);
			}
	}else {
		printf("0\n");
	}

*/	
	return 0;
}
