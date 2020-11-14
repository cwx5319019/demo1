#include<stdio.h>
int main(void)
{
/*
	预处理阶段
		gcc -E demo.c -o demo.i
		1.展开头文件
		2.简单宏替换
		3.去注释
		4.上标记，标记代码在源文件的行号
	编译阶段（核心阶段）
		gcc -S demo.i -o demo.s
		将语法正确的代码编成汇编语言
	汇编阶段
		gcc -O demo.s -o demo.o           大小： 约1.2kb
		将汇编编译成二进制过程
	链接阶段
		gcc demo.o -o demo                大小：约8.6kb
		将.o二进制文件，链接上动态库与静态库（包含绝大部分的库文件.o文件）
		
	某些库函数不会默认链接，需要手动链接 
		格式   -l文件名
	自己封装库文件ar crv lib库名 -o 等待封装.o文件 
		库名为a时   ar crv liba.a -o demo.o

	运算符（）
	
		算术运算符：+ - * / %
			 注意：1.操作 / 和 % 分母为0   会出现 浮点数列外（核心以转储）
				  2.取余运算中，参与运算的数据必须是整型，需要浮点型参与运算只能强转（暂时转化），int（3.14）和getchar()都是表达式
				  3.不同类型数据运算取精度高的
				  
		赋值运算符：= += -= *= /=
			 含义：读取左侧运算右侧的运算结果，写入左侧
			 
		比较运算符：< > <= >= == !=
			 注意：1.返回值只有1和0
			 	  		int a = 5,b = 4,c = 6;
				  		printf("%d\n",a>b>c);  // 0
			 	  2.判断成立 0不成立 非0成立
			 	  	表述成立 0不成立  1成立
			 	  3.浮点型比较必须确定精度
			 	  		double a = 3.123457;
			 	  		double b = 3.123766;
			 	  		printf("%d\n",a-b > 0.0001 );	 //	比较的时候需要确定精度
			 	  		
		逻辑运算符: && || ! 
			 注意：1. 1>0 && !2 > 1	//！优先级大于 > <
		
		三目运算符：
			 公式：表达式1 ？ 表达式2 ：表达式3
			 
		自增运算符： ++和--
			 分类：前++ 和 后++
			 		int a = 1 ,b= 1;
					printf("%d", a++); //先把值赋值给a++本身
					printf("%d", ++b);
					printf("%d",a);
					printf("%d",b);	
		位运算符：按位与& 按位与| 按位取反～  按位异或^  左移<< (2进制左移动1位乘以2右除以2 )  demo8.c
					int a = 8, b = 10;
					printf("%d",a&b); // 1010 1000 // 1000
					printf("%d",a|b); // 
					printf("%d",~a);  // 8取反-9   //符合先加1 再取相反数
					printf("%d",a^b); // 1010 1000 // 0010  相等为0
					
		c语言的代码共有三种结构形式：
					数序结构：if 
					
						if (1){
							int a = 5;
						}
						printf("%d\n",a); //这样会报错
						------------------------------------
						int a = 5；
						if (1){
							int a = 15;
						}
						printf("%d\n",a);  //输出5	
											
							   注意：1.大作用域不可用小作用域的声明变量
									2.不同作用域里可以重复定义，就近原则
						if (判断条件1){
							语句1；
						}else if (判断条件2){
							语句2；
						}else {
							语句3；
						}
							   注意：1.多个语句成立，执行第一个	
							   	
					分支结构：
					循环结构：
					 								
							
*/


	int a = 0 ,b = 0;
	printf("please input a year :");
	scanf ("%d",&a );
	while(getchar() != 10);
	if (a % 4 == 0 && a %4!= 100 || a % 400 == 0){
		printf("该年为闰年\n");
		printf("please input month:");		
		scanf("%d",&b);
		if (b ==1 || b == 3 || b== 5 || b == 7 || b == 8 || b==10 || b==12){
			printf("该月有31天\n");
			if( 3 <= b <= 5 ){
				printf("spring\n");
			}else if (6 <= b <= 8){
				printf("summer\n");		
			}else if (9 <= b <= 11){
				printf("autumn\n");		
			}else {
				printf("winter\n");		
			}  
		}else{
			printf("该月有30天\n");
			if( 3 <= b <= 5 ){
				printf("spring\n");
			}else if (6 <= b <= 8){
				printf("summer\n");		
			}else if (9 <= b <= 11){
				printf("autumn\n");		
			}else {
				printf("winter\n");		
			} 
		} 
	}else {
		int year = a % 4;
		int year1 = a - year ;
		int year2 = a + (4 - year );
		
		if(year1 % 4 == 100 && year1 % 400 != 0 ){
			year1 -= 4;
			}
		if(year2 % 4 == 100 && year2 % 400 != 0 ){
			year2 += 4;			
		}
		printf("%d不是闰年，它的前一个闰年是%d,后一个闰年是%d\n",a,year1,year2);		
	}
	
	






/*
	int a = 0 , b = 0 ,c = 0;
	printf("please input :");
	scanf ("%d %d %d",&a ,&b ,&c);

	int bigger = a>b ? a : b;
	int max = bigger > c ? bigger : c;
	
	int smaller = a>b ? b : a ;
	int min = smaller > c ? c : smaller ;
	
	int mid = a + b + c - max - min ;

	if ( (a+b > c) && (a+c>b) && (b+c >a)){
		if ( (a==b || a==c || b==c)  ){
			if (a==b && b==c){
				printf("三角形为等边三角形\n");
			}else {
				printf("三角形为等腰三角形\n");
			}
		}else if( a != b && a!= c && b != c){
			printf("三角形为普通三角形\n");
		}
	}
	
	if (min*min + mid*mid < max*max){
		printf("该三角形为钝角三角形\n");
	}else if (min*min + mid*mid == max*max){
		printf("该三角形为直角三角形\n");
	}else if(min*min + mid*mid > max*max){
		printf("该三角形为锐角三角形\n");
	}

*/

	
	

/*
//******************位运算符**********************************
	int a = 5, b = 10 ;
	
	int c = a;
	b = a;
	a = c;
	printf("%d %d\n",a,b);
	
	a = a+b;
	b = a-b;
	a = a-b;
	printf("%d %d\n",a,b);

// 0101  5
// 1010  10
// 1111 a
// 1010  10

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d\n",a,b);

*/




/*
//左移<< (2进制左移动1位乘以2右除以2 )
	int a = 8,b = 15;
	printf("%d\n", a|= (1<<2));  1<<2 
	printf("%d\n", a&= ~(1<<2));	

*/
//	int a = 5;
//0101

//0000 0101
//0000 0010 
//0000 0111  

//	int c = a |= (1<<1);
//	//c = c |= ();
//	printf("%d\n",c);
	






/*
//*******************位运算符*************************
// 计算机底层权限运用按位& |
 	int u= 0;
 	u = u|4;
 	printf("%d\n",u);
 	u = u|2;
 	printf("%d\n",u);	
 	u = u|1;
 	printf("%d\n",u);
 	u = u|4;
 	printf("%d\n",u); 
 	
 	u = u&(~4);
 	printf("%d\n",u); 		
 	u = u&(~2);
 	printf("%d\n",u); 	
 	u = u&(~1);
 	printf("%d\n",u); 	
 	
*/ 	


/*
//**********************自增运算符**********************
	int a = 2 , b = 3;
	a*= a+++b+++a++;	//a*= a++ +b++ + a++;  4* 2 3 3  a=32
	b+= a+++b+b++ ;	//b += a + ++b + b++ ; 5+ 32 4 4
	printf("a:%d b:%d\n",a,b);

*/


/*
//****************三目运算符排序三个数****************
	int a =0 ,b = 0, c = 0;
	printf("please input three number:\n");
	scanf("%d%d%d",&a ,&b ,&c);
	int bigger = a>b ? a : b;
	int max = bigger > c ? bigger : c;
	
	int smaller = a>b ? b : a ;
	int min = smaller > c ? c : smaller ;
	
	int mid = a + b + c - max - min ;
	
	printf("%d %d %d\n",max , mid , min); 

*/


/*
//********************第几象限**********************
while(1){
	int x = 0, y =0 ;
	printf("please input x y:");
	scanf("%d%d",&x,&y);
	while(getchar() != 10);
	int pos = (x<0) + (y<0) + 1 + (x>0 && y<0)*2; 
	printf("该坐标位于第%d象限\n",pos);
	
}	
	
*/	

/*
//******************精度****************************
	double a = 3.123457;
	double b = 3.123766;
	printf("%d\n",a-b > 0.01 );	 //	比较的时候需要确定精度
*/

/*
//****************比较运算符*************************
	int a = 5,b = 4,c = 6;
	printf("%d\n",a>b>c);  // 0
*/
	
/*
//******************倒序****************************
	int a = 12345,b = 0,c = 0;
	
	while (c < 5){
		b = a % 10;   
		printf("%d",b);
		a = a/10;    
		c++;
	}
	printf("\n");


	for (c = 0 ; c < 5 ; c++){
		b = a % 10;
		printf("%d",b);
		a = a/10;
	}
	printf("\n");

	do{
		b = a % 10;   
		printf("%d",b);
		a = a/10;    
		c++;
	}while(c < 5);
	printf("\n");
*/
	return 0 ;
}











 
