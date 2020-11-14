/*
	"" 和 <>的区别
	
	总结函数的文件写法
		1.入口函数写在main.c中
			#include"head.h"
			int main(){
				func1();
			}
		2.其他功能函数写在其他.c文件中
			#include"head.h"

			void func1(){
				printf("1号函数");
				printf("%d\n",a);
			}
			void func2(){
				printf("2号函数\n");
			}
		3.该头文件全部保存到一个自定义头文件中head.h中
				注意头文件要包括下面三个语句（防止自锁）
					#ifndef head_h_
					#define head_h_
			#ifndef head_h_  
			#define head_h_

			#include<stdio.h>
			extern int a ;
			void func1();

			#endif


				#endif
	extern 类型名 变量名		
		extern int a ;   强制外部引用 没有就失效
		int a ;          先外部引用，没有就声明变量
		
		
	普通函数，静态函数，内联函数和带参宏的区别：
		内联函数直接将调用函数赋值到调用处，主要依靠主函数的栈空间
		
	gdb调试
		1.r 直接运行程序
		2.b 断点  b .c文件：行
		3.n 断点行开始执行
		4.s 进入函数
		5.l 查看周围代码
		6.c 断点行开始全部执行
		7.q 退出
		
	递归函数
		1.自己调用自己
		2.明确退出条件
		3.每一次递归逐渐区近退出点
		
		int func(int num){
			if (num ==1){return 1}
			return func(num -1) +num;
		}
		int main(){
			func(5);
			printf("%d\n",func(5));
			return 0;
		}
		
		
	数组
		**数组和指针的区别**
		
		1.数组名单独出现是指向首元素的指针 arry   //数组名不能相互赋  例如 brr = arr 因为他在内存中是连续的不能中间插入； 
		2.当数组名配套sizeof或者&出现，它代表整个数组  &arry
		3.指针指向数组名之后，就可以代表该数组。
		
	
	访问数组
		
	所有数据结构中总是存在以下几种操作
		增
			void insert_data(int* arr, int* len){
				int data = 0;
				printf("请输入要添加的数据：");
				scanf("%d",&data);
				while(getchar() != 10);
				
				arr[*len] = data;
				(*len)++;
			}
		删
			
		
		
		改
			void update_data(int* arr ,int len){
				int data = 0;
				printf("请输入要修改的数据：");
				scanf("%d",&data);
				while(getchar() != 10);
				
				int res = find_data(arr,data,len);
				if(res==-1){
					printf("查无此数\n");   //先查在改
					return ;
				}
				printf("请输入修改后的数据:");
				scanf("%d",&data);
				while(getchar()!=10);
				arr[res] = data;

			}
		查
			int find_data(int* arr ,int data ,int len){
				int i = 0;
				for(i = 0; i<len ; i++){
					if(arr[i]==data )
						return i;      //这里返回下标有助于修改数组元素    
				}
				return -1;
			}
		排
		遍历
			void print_data(int* arr, int len){
				int i = 0;
				for (i = 0 ; i< len ; i++){
					printf("%d“，arr[i]);
				} 
				printf("\n");
			}
		调用函数
			int main(){
				int arr[5] = {0};
				int len = 0;
				insert_data(arr,&len);  //两个实参都要变化，用指针
				print_data(arr,len);
				
			}
	
	
	
	
	
	
*/





/*
#include"head.h"
a = 5;
int main(){
	func1();
	printf("%p\n",&a);
}
*/





//------------------练习递归--------
/*
1/2 +1/3+....1/n
*/
/*	
#include<stdio.h>

float func(int num){
	if (num ==1.0){return 1;}
	return func(num - 1) + 1.0/num;
}

int main(){
	func(2);
	printf("%lf\n",func(2));
	return 0;
}
*/



//-----------------练习递归------------------
/*
x (n+1)*2 猴子吃桃
	
*/
/*
int func(int n){
	if (n == 1){
		return 4;	
	}
	return (func(n - 1) +1)*2;

}

int main()
{
	func(5);
	printf("%d\n",func(5));
	return 0 ;
}
*/

//------------------------

/*
1-1/3+1/5.....1/101
*/
/*

double func(int n){
	if ( n == 1){return 1.0;}
	if(n % 2 == 0){
		return func(n-1) - 1.0/(2*n-1);     //n是项数
	}else{
		return func(n-1) + 1.0/(2*n-1);	
	}
	//return func(n-2) + 1.0/n*((n/2%2==0)?1:-1);  //n是分母 n/2 除以每个数的间隙 就成了012345
}

int main()
{
	double x = 0;
	func(5);
	printf("%lf\n",func(5));
	return 0 ;
}
*/
//--------------------斐波那契-----

/*
	1:使用递归解决猴子吃桃的问题
	2:使用递归解决 1/1-1/3+1/5-1/7+...-1/99+1/101
	3:使用递归解决斐波那契数列第n项值的问题

// 1 1 2 3 4 7 
*/   
      
/*
#include<stdio.h>
int func(int n )
	if (n == 1 || n==2)return 1;
	return func(n-1)+ func(n-2);   			
}
int main()
{
	func(3);
	printf("%d\n",func(3)); // func(2) + func(1) 
	return 0 ;
}

*/
/*
#include<stdio.h>

int find_data(int* array,int data, int len){

	int i = 0;
	for (i = 0; i< len ; i++){
		if (data == array[i]){
			return i;
		}
	}
	return -1;

}

void insert_data(int* array,int* len){
	int num = 0;
	printf("请添加一个数：");
	scanf("%d",&num);
	while(getchar() != 10);
	
	array[*len] = num;
	(*len) ++;
}

void print_data(int* array,int len){
	int i = 0;
	for (i = 0; i<len ; i++ ){
		printf("%d\n",array[i]);
	}

}


void update_data(int* array,int len){
	int data = 0;
	printf("要修改的数：");
	scanf("%d",&data);
	while(getchar() != 10);
	
	int res = find_data(array,num, len);
	if (res == -1){
		printf("该数不存再！");
	}
	int data1 = 0;
	printf("修改的数：");
	scanf("%d",&data1);
	while(getchar() != 10);
	array[i] = data1;
}

int main()
{
	
	int len = 0;
	int array[5]= {0};	
	insert_data(array,&len);


}

*/
/*
	1:使用递归解决猴子吃桃的问题
	2:使用递归解决 1/3-1/5+1/7-1/9+...-1/99+1/101
	3:使用递归解决斐波那契数列第n项值的问题
*/
//f(n) =  (f(n-1)+1)*2   
//func(n) =fun(n-2) + 1/n*((n/2%2 == 0)？1：-1);							
// func(n) = fun(n-1)+fun(n-2)
//func(n) = func(n-1)+1/(2*n+1)*((n%2 == 0)？-1：1);
//

#include<stdio.h>

int func(int n){
	if(n == 1 || n ==2)return 1;
	return func(n-1) + func(n-2);
}

int main(){
	
	printf("%d\n",func(10));
	return 0 ;
}

















