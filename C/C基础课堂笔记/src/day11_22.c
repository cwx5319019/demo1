
#include<stdio.h>
#include<stdarg.h>
/*
	内存的概念：
		内存：速度快，但断电数据丢失
		硬盘：相反
		
	linux内存大致分为以下几类：
		栈内存
			1.先进后出
			2.自动申请自动释放  
				pa 在运行时候如果有值，编译器不会报错，认为它是也指针，如果没有则会报出段错误
			 	&a 在编译的时候已经贴上野指针，所以编译器会报段错误
			 	
		静态存储取（static）
			1.程序开始之前静态存储区就已经存在，程序结束才会消失
			2.只是生命周期变大了，作用域还是被限定在声明的作用域中，访问它只能用指针。
			3.如果非的用变量名访问，就必须定义全局变量。
			
			static:延长声明周期，限制作用域
			       //可以做简单计数
			
			int* func(){
				static int a = 0;
				return &a;
			}
			int main(){
			
			}
			
		堆存储区
		常量存储区

*/










/*
void func(int num,...){
	int i = 0,res =0;
	va_list p;
	va_start(p,num);
	for(i=0;i<num;i++){
	//printf("%d\n",va_arg(p,int));
	res += va_arg(p,int);
	}
	va_end(p);
	return res;	
}

int main()
{
	func(2,21,21);
	printf("%d\n",res);
	return 0;
}

*/
