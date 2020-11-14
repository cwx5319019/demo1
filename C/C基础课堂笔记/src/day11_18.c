#include<stdio.h>
#include<unistd.h>
int main(void)
{
#if 1
	 变量命名规则
	 	daota 09
	 	下划线和驼峰命名法 
	 		（张三身高，李四体重）
	 		int zhangsan_height_cm = 180;
	 		int lisiWeight = 50;
	 		
	 gcc编译
	 #typedef int i              //int起个别名
	 #define FUNC()  ((x)*(x))   //定义成宏 再编译的时候将宏替换成具体定义的数  不加（）就成了3+3*3+3  加括号为(3+3)*(3+3)
	 int a = 5;
	 printf("%d\n",FUNC(3+3)); 

#endif
#if 1


	c语言数据类型
		char a = 400;
		printf("%d\n",a);
		unsigned char b = 500;
		printf("%d\n",b);

	字符型 
		char 占1字节
		ASCII ：大小写转化 
		char x = '9';
		printf("%d",x -48);//输出为数字9
	地址类型

		int a = 5;
		int* pa = &a;  //pa指向变量a的地址，a是int型，所以pa是int*类型 
		int** ppa = &pa; //ppa指向变量pa的地址，pa是int*型，所以ppa是int**类型 
	
		printf("%p\n",pa);
	指针
		int a = 5;
		int b = a;
		b = 10;
		printf("%d\n",a);  //这样a和b互不相关
	
		int a = 5;
		int* b = &a;
		*b = 10;
		printf("%d\n",a);//这样更改了a的值   //b前加了一个*符号 抵消了&符号 减少了int前面的1个 * 
	
		int a = 5;
		int c = 10；
		int* b = &a;
		b = &c;        
		printf("%d\n",a);//这样a的值不会变 指针由指向a变为指向b   //b前面没有* 号 所以还是指针 指向了c的地址


#endif
#if 1
		
		
		
		


	printf取读
		直接获取到内存地址，然后再获取到该数据占据n个字节，直接对该字节往后n个字节的二进制数，进行读取
		直接为这个数据占据的数据的整段内存，起一个别名，直接使用/访问该别名就等于访问到了内存上的这个数据，这个内存别名就称为变量
		使用步骤：
			1：明确内存多大和类型： （数据类型 变量名） 如：int a为a开辟四个字节空间

	int a = 5;//=号是赋值运算符，读取数据5 写入a代表的内存空间
	printf("a:%d",a); //%d的位置可写，a的位置可读就行（常量）

	
	scanf读取
		scanf("%d",&a);// “”里尽量只有格式占位符
		scanf是从缓存区读取 缓存区无数据提示输入 缓存区有数据无匹配项直接返回；
		输入时候按的回车\n也在缓存，所以每次使用要清理缓存区，清理公式while(getchar() != '\n');

	char a = 0 ;
	char b = 0;
	scanf("%c",&a);   // 读取缓存的第一个值
	while(getchar() != '\n'); //把剩下的值都贴到getchar身上，即缓存清空
	printf("a:%c\n",a);

	scanf("%c",&b);//由于缓存内无元素，所以提示输入
	printf("b:%c\n",a);

#endif
#if 1



//\b 的应用
	//printf("hello world\b\b\b\033[1B");//向下移动1个 
	//printf("hello world\b\b\b\033[1A");// A向上移动1
	//fflush(stdout);
	//while(1);


	printf("__/__/__/__");
	printf("\033[11D");  //向左移动11光标
	fflush(stdout);
	sleep(2);
	printf("10\033[1C"); //向右移动1个光标
	fflush(stdout);
	sleep(2);
	printf("20\033[1C");
	fflush(stdout);
	sleep(2);
	printf("30/");    //自带“/”
	fflush(stdout);
	sleep(2);
	printf("40");
	fflush(stdout);
	while(1);
#endif
#if 1

	return 0;
}
