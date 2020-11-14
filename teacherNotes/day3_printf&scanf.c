/*
	printf的使用方式:
		printf会输出双引号号中所有的由字符组成的字符串，但是，现实中总是存在一些不可见字符，例如换行，退格，空字符等，这时候我们使用转义符来代表这些不可见字符
		换行：\n表示
		退格：\b表示，终端上的光标位置向前移动一位，但是注意，并不会删除最后一位的数据
		空字符:\0
		tab:\t,tab是缩进所有，在之后编程过程中，所有的被嵌套代码，都需要比嵌套他的代码多一个tab，在vim中，tab的空格数量可以通过设置文件设置
		使用 vim ~/.vimrc打开vim的配置文件
*/
/*
	printf的缓存问题：
		printf在运行的时候，他并不是直接将“”中的内容输出到终端上，而是先将内容全部输出到缓存区，然后等待缓存刷新后，缓存区的内容，才会出现在终端上。
		printf的缓存何时刷新：
			① 当碰到\n的时候，缓存刷新
			② 使用函数(功能模块)fflush(stdout)刷新
			③ 缓存区满后，自动刷新
			④ 程序结束后，缓存自动刷新
		总结，如果一个printf写在一个不会及时结束的程序中时，为了让他及时显示，只能使用\n或者fflush(stdout)来刷新printf的缓存
//--------------------------		
#include<stdio.h>
#include<unistd.h>

int main(){
	printf("hello world");
	sleep(5);
	//while(1);
	return 0;
}
//--------------------------
*/
/*
	printf中的光标位置的移动我们可以使用以下4个转义符来表示上下左右的移动
		\033[nA,光标向上移动n个位置
		\033[nB,光标向下移动n个位置
		\033[nD,光标向左移动n个位置
		\033[nC,光标向右移动n个位置

//-----------------------------
#include<stdio.h>

int main(){
	printf("hello world\b\b\033[1B");
	fflush(stdout);
	while(1);
	return 0;
}

//-----------------------------------
*/
/*
	变量的概念：无论任何数据，都需要确实存在的载体去承载该数据。计算机中的数据，他的载体就是内存
	内存以什么方式来承载数据：
		内存的工作原理：他是以高速闪存的方式，来表示各种各样的数据，内存通电之后，每一个点位都2种电平模式，高电平和低电平，高电平就代表1，低电平就代表0，由高低电平就能构成一个明确的二进制数，二进制数转换出来的10进制数，就是内存存储的数据。
		每一个电平，我们称为 1 位，每8位构成1个字节，每1024字节构成1kb。
		计算机中，每一个字节都拥有一个明确的编号，我们把这个编号称为内存地址。
		既然现在已经知道了，内存上已经存有数据，那么我们就希望将内存上的数据读取出来并使用，有以下两种方式，可以实现该目的：
		① 直接获取到内存地址，然后再获取到该数据占据n个字节，直接对该字节往后n个字节的二进制数，进行读取
		② 直接为这个数据占据的整段内存，起一个别名，直接使用/访问该别名，就等于访问到了内存上的这个数据，我们把这段内存的别名，就称为变量
		变量的使用步骤：
			1：先要明确该变量所代表的内存空间到底有多大，同时也能够明确，该段内存空间到底存放的是什么类型的数据
				数据类型 + 变量名(在一定规则下随意选取)
				举例:int a;声明变量a，为变量a开辟4个字节的内存空间，并且表示变量a所代表的内存空间，能够存储整型数据
*/
/*
	如何在printf中输出一个变量的值：
		我们必须使用双引号中的变量来代表一个变量，我们把双引号中的变量称为格式占位符。不同数据类型的格式占位符也是不同的，整型的格式占位符为%d

//--------------------------------
#include<stdio.h>

int main(){
	int a = 5;//这里的等号是一个赋值运算符，他的含义为：读取数据5，然后将他写入到a所代表的内存空间上
	a = 20;
	//如何在printf中输出一个变量的值
	//printf("a的值为:%d\n",a);
	
	scanf("%d",&a);
	printf("a = %d\n",a);
	return 0;
}
//-------------------------------------		
*/
/*
	scanf的使用:
		scanf和printf的相反，他是将终端上的数据，读取到内存中，所以，必须有一个变量来保存读取到的数据。
		scanf和printf的使用方式大致相同，但是有2点需要注意
		scanf中必须有格式占位符，并且，尽量只有格式占位符,因为scanf是格式化的输入，在scanf中写入任何的内容，在真正输入的时候，都要求输入同样的内容
		scanf中格式占位符对应的数据必须有&取地址符

	scanf和printf一样，同样拥有缓存区：
	scanf的缓存区工作原理:先读取终端上输入的数据，然后将所有的数据写入到缓存区，缓存区再根据scanf的格式占位符，将第一个能够写入到格式占位符的数据写入，如果不能写入则直接结束，数据依旧存在与缓存区
	为了缓存对于逻辑代码的不干扰，我们每一次使用scanf之后，都需要清理scanf的缓存区
	
//-------------------------------
#include<stdio.h>

int main(){
	int a = 0;
	char b = 0;
	char c = 0;
	//scanf("%d",&a);
	//printf("a = %d\n",a);

	scanf("%c",&b);
	while(getchar()!='\n');
	printf("b = %c\n",b);

	scanf("%c",&c);
	printf("c = %c\n",c);
	return 0;
}
//--------------------------------
*/

//----------------练习题------------------
/*
	首先在终端上输出__/__/__/__,然后使用while(1)是程序不会结束
	程序休眠2秒之后，将第一组__变成10，再次休眠2秒之后将第二组__变成20，以此类推，最终__/__/__/__变成10/20/30/40
*/
/*
#include<stdio.h>
#include<unistd.h>

int main(){
	printf("__/__/__/__");
	printf("\033[11D");
	fflush(stdout);
	sleep(2);
	printf("10\033[1C");
	fflush(stdout);
	sleep(2);
	printf("20\033[1C");
	fflush(stdout);
	sleep(2);
	printf("30\033[1C");
	fflush(stdout);
	sleep(2);
	printf("40");
	fflush(stdout);
	while(1);
	return 0;
}
*/

//-------------
/*
#include<stdio.h>

int main(){
	printf("getchar = %c\n",getchar());
	return 0;
}

*/



/*
	c语言中的数据类型:不同的数据类型，在内存中占据的内存大小是不同的，就会造成该数据类型的取值范围是不一样的
	通常情况下，有符号的数据类型，最高位为符号位，0代表正，1代表负。剩下的都为数据位。
	那么二进制数如何向十进制数转换:
		① 短除法
		② 数零法
	以 1 个字节为例，1个字节的数据，他的最大值：2^7-1,最小值是-2^7
	
//------------------------
#include<stdio.h>

int main(){
	char a = 400;//127+256=383,400-383 = 17,-128+16
	unsigned char b = 500;//1111 1111 -> 2^8-1 = 256-1 = 255
	//500-255 = 245,0+244
	printf("%d\n",a);
	printf("%d\n",b);
	return 0;
}
//------------------------------------

	那么，为什么1111 1111转换成十进制是-1而不是-128。因为计算机在比较数据大小的时候，永远只能比较他们的绝对值
	为了实现负数大小，与绝对值大小的统一，我们为计算机引入了补码的概念。计算机中所有的数据，都是以二进制补码的形式存在的
	源码：有十进制数通过短除法或者数零法转换出来的二进制数，就是这个数的源码
	反码：在源码的基础上，符号位不变，其他位取反
	补码：在源码的基础上+1
	注意：正数的补码就是源码本身，负数的补码才需要通过反码来计算
	注意：当使用二进制计算，得到的结果是一个负数的时候，这时候肯定是补码，此时不能直接通过数零法转换成十进制，必须先得到源码，才能转换。对补码再求一次补码，就会获得他的源码
	当一个数据的取值，超过了他的最大值后，就会从最小值开始，重新取值。反过来一样，当他的取值超过了他的最小值后，就会从最大值开始重新取值。
	在代码中，我们使用正常的表达方式，来书写一个十进制数，使用0开头的数，来书写一个八进制数，使用0x开头的数，来书写一个十六进制的数
	其中八进制数在系统底层中尤为重要，我们到运算符的时候，再来分析八进制数
	C语言中的数据类型，大致分为以下几类：
		① 整型:所有整数数据，都会存放于整型类型的变量中
			分为：
				长整形:long,占8个字节，使用%ld进行格式占位
				普通整型:int,占4个字节，使用%d进行格式占位
				短整型:short,占2个字节，使用%d进行格式占位
		② 字符型:所有单一的字符数据(包含，但不限于，a~z,A~Z,0~9,!?之类的)，所有单一的字符必须使用''括起来
			使用char表示字符型数据，在内存中占1个字节，使用%c进行格式占位
			为了表示那些不可见字符，我们会使用转义符来表示。
			同样的，我们还可以使用另一种方式来表示不可见字符：
				我们人为的为每一个字符，都编排了一个号码，这个号码就是ASCII码。所以，在printf中，如果使用%d输出一个字符类型的变量，最终输出的是该字符的ASCII码。但是，注意，在scanf中，只能使用%c进行格式占位
			ASCII码使用总结: 大小字母的ASCII码+32，就会变成对应的小写字母，小写字母-32就会变成对应的大写字母。数字字符-48，就会变成对应的整型数
		③ 浮点型:所有带有小数的数据，都存放于浮点型变量中
			浮点型数据分为：
				单精度浮点型:float,占4个字节的内存，使用%f进行格式占位
					最高位为符号位，2~9位为指数位(这里实际上存放的2进制数都是指数，2的指数)，10~32位为尾数位
				双进度浮点型:double,占8个字节，使用%lf进行格式占位
					最高位为符号位，2~12位为指数位，13到64位为尾数位
				在printf的时候，我们可以使用%.nlf,来表示打印小数点后n位，并且在显示上四舍五入
				也可以使用%g来打印所有的有效位
				浮点型数据注意事项:
					1:浮点型数据不参与位运算(针对每一位0或者1进行的基础运算)
					2:浮点型数据由于存在精度偏差，所有，在两个浮点型数据比较大小的时候，一定要明确精度范围
//--------------------
#include<stdio.h>

int main(){
	//char x = '5';
	//printf("%d\n",x-'0');
	//printf("%c\n",x+32);
	double a = 300.126345;
	double b = 300.126445;
	printf("a = %.15lf\n",a);
	printf("a = %.15lf\n",a);
	return 0;
}

//----------------------------
					
		④ 空类型:空类型不能声明变量，但是有其他作用
			void 来表示,ubuntu中默认void类型占据1个字节，但是不同的系统void类型占据内存空间不确定，所以void类型通常不能用来声明变量
		⑤ 自定义类型:他是一种自定义复合数据类型
			举例来说：如果想要形容一个人的身高，使用整型数就能去形容一个人的身高
			如果想要形容一个具体的人：需要性别，年龄，身高，体重
				其中：性别可以使用char类型表示，‘F’女性，‘M’代表男性
					年龄可以使用int类型来表示
					身高和体重可以使用：浮点型数据或者整型数据来表示
				那么，现在就需要将以上4个类型的数据，自定义复合成一种数据类型，该数据类型，就属于自定义类型
			C语言中的自定义类型只有3种：结构体，联合体，枚举
			结构体使用:struct + 结构体类型名 来表示一个自定义类型
			联合体使用:union + 联合体类型名 来表示一个自定义类型
			枚举:enum + 枚举类型名来表示一个自定义类型
		⑥ 地址类型:存放内存地址的变量。内存地址，在计算机中，通常以16进制数出现，无论是什么类型的变量的内存地址，他的大小，总是固定的，32位系统为4个字节，64位系统为8个字节。
			所有的地址类型，都可以使用%p进行格式占位
			所有地址类型的变量，只能存放十六进制的地址数据，这个地址数据的来源：就是对一个变量取地址&
			关键在于，如何确定一个地址类型数据的数据类型
			首先，确定该地址上所存放的数据的类型，然后以该类型为地址变量的基础数据类型,然后在基础数据类型后面加上*号，最终形成一个完整的地址数据类型,我们把这样的一个存放了地址的变量，称为指针变量，简称为指针,我们把一个指针存放一个变量的地址的行为，称为指向某个变量的地址

			总结：对任意类型的变量，加上&操作后，该变量的数据类型就会因为&而多一个*
		在拥有一个数据的地址之后，我们总是希望能够访问到数据本身。
		首先，访问一个地址，然后对该地值使用取值符号(*),就能取出该地址上存放的数据
		一个&符，会让数据类型多一个*，一个取值符号(*),会让数据类型少一个*
		
//--------------------
#include<stdio.h>

int main(){
	int a = 5;
	printf("a的地址为:%p\n",&a);
	int* pa = &a;//pa指向变量a的地址，a是int类型，所以pa是int*类型
	int** ppa = &pa;//ppa指向了变量pa的地址，pa是int*类型，所以ppa是int**类型
	int*** pppa = &ppa;//pppa指向了变量ppa的地址，ppa是int**类型，所以pppa是int***类型
	

	printf("a = %d\n",***pppa);
	return 0;
}

//---------------------------
#include<stdio.h>

int main(){
	int a = 5;
	int c = 15;
	int* b = &a;
	//*b = 10;//*&a = 10 -> a = 10
	b = &c;

	//指针的作用，就是为了保证，在不同的{}之中，进行运行的数据是同一个数据

	//假设，b和a在不同的{}中，使用某些手段，让{1}中的b等于{2}中的a，这个时候更改b的值，a的值不会改变
	//但是反过来，让{1}中的b指向{2}中的a的地址，这个时候更改*b的值，其实就是在更改a的值

	printf("a = %d\n",a);
	return 0;
}


*/
/*
	变量的命名规则：
		① 不能以数字开头作为变量名
		② 不能以关键字作为变量名
		③ 可以使用_开头，为变量命名，_开头的变量，通常与没有_开头的变量有密切联系。例如
			在编写注册功能的时候，就会有两个账号的变量，一个账号为系统中存在的账号，一个账号为用户需要输入的账号，这两个账号我们就可以使用_进行区分
		④ 变量命名的时候，必须要有其特殊含义,其含义与其用法必须对应，必要的时候，可以在变量名后面再追加计量单位的名称。严禁使用拼音命名
		在一个变量拥有多重含义的时候，我们可以使用以下两种命名方式来表示具体含义。例如zhangsan的身高，李四的体重
		 	1：下划线命名法：int zhangsan_height_cm = 180
			2: 驼峰命名法：int lisiWeightKg = 50;
*/
/*
	gcc 整个编译流程:一共分为以下4个步骤 gcc + 带编译文件名
		例如想要编译的是demo.c , gcc demo.c
		① 预处理阶段:gcc -E demo.c -o demo.i,代表，从与处理阶段开始执行，做到预处理阶段
			预处理demo.c,并生成demo.i
			1：头文件展开
				头文件中拥有许多函数的声明，函数的定义不在头文件中，函数的定义全都在库文件中
			2：简单宏替换
				宏：使用语法#define + 宏的名字 + 实际内容,宏简单的理解成实际内容的别名
				将 “宏的名字” 在预处理阶段简单的替换成 “实际内容”
				为什么叫做简单宏替换：因为宏替换的时候，永远不会考虑运算优先级问题
				还有一种宏叫做带参宏：
					#define + 宏的名字(参数) + 与参数挂钩的实际内容
				typedef:他是一个关键字，用来为一个数据类型取别名的操作
				typedef和#define的区别：#define会将宏替换成内容，所以实际参与编译的是内容，而typedef只是将内容取个别名，所以实际参与编译的是别名，只不过编译会将别名当做内容来编译
			
/*				
//----------------------------------
#include<stdio.h>
	
#define PI 3.1415926
#define FUNC(x) ((x)*(x))

#define ooi int

typedef long long int lli;

int main(){	
	long long int a = 5;
	lli b = 10;
	printf("%d\n",FUNC(3+3));
	return 0;
}
//-----------------------------------
				
			3：去注释
			4：上标记
		② 编译阶段:
		③ 汇编阶段:
		④ 链接阶段:
*/

//--------------第二天补的内容	-------------		
/*
	demo.c
	预处理阶段:gcc -E demo.c -o demo.i
		1:展开头文件
		2:简单宏替换
		3:去注释，注释有两种形式
			1/ 行注释，使用，//代表这一行的代码都属于注释
			2/ 段注释，使用/ * * /，被/ *扩起来的所有代码都属于注释

		4:上标记，为每一行的代码，标记上他在源文件中的行号
	编译阶段: gcc -S demo.c -o demo.s
		从预处理开始，只做到编译阶段
		编译阶段是整个编译过程的核心阶段，他会分析代码的词义，语义及语法结构，如果发现任何错误，都会终止编译，并且抛出错误。所以，整个编译过程中，只有编译阶段，会出现错误
		编译阶段会将语法正确的代码编译成汇编语言。汇编语义是一个指针针对内存操作的语言。系统底层的，几个操控驱动的函数，都是由汇编语言直接写成的。
	汇编阶段:gcc -c demo.s -o demo.o
		从预处理开始执行，只执行到汇编阶段
		所有库函数，我们ubuntu中是找不到源码的，因为所有的库函数都是以.o二进制文件的形式存在于库文件当中
		将汇编语言汇编成计算机能够识别的二进制语言
	链接阶段：gcc demo.o -o demo(可执行文件)
		将.o二进制文件，链接上动态库与静态库(包含了绝大部分的库函数的.o文件)
	举例来说：一个简单的程序的.o文件大小在1.2kb左右，但是生成的可执行文件有8.6kb左右，这多出来的7.4kb就是链接的动态库与静态库
	某一些库函数，他的库在编译阶段并不会默认链接到当前.o文件，此时，在编译的时候必须手动链接，在编译的最后加上 -l库名
	如何自己封装库文件:使用shell指令:ar crv lib库名.a + 等待封装的.o文件，如果有多个.o文件封装在一个库中，使用空格隔开
	库名为a的情况下
	也就是: ar crv liba.a -o demo.o
*/


//-------------------总结-----------------
/*
	上午：
		① printf的缓存问题：缓存何时刷新
		② printf的转义符：\b以及光标上下左右移动
		③ 变量的概念
		④ printf中如何输出一个变量的值
		⑤ scanf的使用注意点：只能有格式占位符，缓存问题以及清理缓存的方法
	下午：
		① 整型数据在内存中的存储形式，以及不同类型的数据的取值范围
		② 为了实现负数大小与绝对值大小的统一，人为引入了源码-反码-补码的概念
		③ 所有数据类型的注意点和占据内存的空间以及格式占位符的形式
		④ 指针变量的基础：
			对一个变量取&之后，该变量的类型就会多一个*
			对一个变量取*之后，该变量的类型就会少一个*(当一个变量类型没有*的时候，依旧取*，语法错误，编译不通过)
		⑤ 变量的命名规则
		⑥ 编译的4个流程，只讲到预处理阶段
*/