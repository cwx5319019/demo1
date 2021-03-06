/*
	指针偏移：
		之前提到过，所有的指针都只会指向一段内存的首字节地址，所以，为了准确的理解所指向内存的具体大小，我们应该将指针模块化的看待。
		并且，指针本身是一个16进制的数，所以，指针自然可以加减。
		那么对指针进行加减运算是什么东西：对一个指针进行+1或者-1的操作，那么该指针就会向后或者向前移动1个模块大小的距离
		再次强调：指针偏移的时候，偏移大小，完全取决于当前指针的基本数据类型。
*/
/*
	通用指针：void* 为通用指针，他可以指向任意类型的指针。
	在ubuntu系统中，通用指针模块大小只有1个字节，在不同的系统中，通用指针的模块大小都会不一样。所以，通用指针虽然可以指向任意类型的指针，但是通用指针不能直接取值
*/
/*
	数组指针与指针数组
		数组指针：是一个指针，指向了二维数组的指针
			举例：int arr[2][3] = {0};
				int (*parr)[3] = arr;
			注意：数组指针在取值的时候，操作方式和二级指针一样
		指针数组：本质是一个数组，存放的数据都是指针的数组
	常量指针与指针常量
		常量指针：本质是指针，指向常量的指针
			不能通过该指针来修改地址上的值
		指针常量：本质是一个常量，该常量的类型为指针类型。
			所以，该指针一旦初始化完成后，就不能改变指向。
	我们使用const关键字来代表常量，来修饰一个数据，const修饰什么目标，被直接修饰方就是常量
*/


#if 0
#include<stdio.h>

int main(){
	int a = 5;
	int* pa = &a;
	int arr[5] = {1,3,5,7,9};
	printf("%p\n",pa);
	printf("%p\n",pa+1);
	printf("%d\n",*(arr+4));
	printf("%d\n",arr[4]);
	return 0;
}
#endif
#if 1

#include<stdio.h>
int main(){
	int a = 5;
	char b = 'x';
	int* pa = &a;
	char* pb = &b;
	void* vpa = pa;
	void* vpb = pb;

	printf("%d\n",*pa);
	printf("%c\n",*pb);

	printf("%d\n",*(int*)vpa);
	printf("%c\n",*(char*)vpb);

	void* vppa = &pa;

	void** vvpa = &vpa;          
	//void** vvpa    正常针对vvpa二级指针取地址  接收的应该是 void*** 类型，这用void*通用指针接收，所以输出时候要转化为三级指针。
	void* vvvpa = &vvpa;		
/*
	使用vvvpa访问到a的值
*/
	printf("a = %d\n",*(int*)(**(void***)vvvpa));
	return 0;
}


#endif
#if 0

#include<stdio.h>

int main(){
	char* c[4]={"ENTER","NEW","POINT","FIRST"};
	char** cp[4]={c+3,c+2/*c+1*/,c+1,c};
	char*** cpp=cp;

	printf("%s\n",**++cpp);
/*
	cpp -> &(c+3)
	++cpp -> &(c+2)		cpp -> &(c+2)
	*++cpp -> *&(c+2) -> c+2 -> &"POINT"
	**++cpp -> *&"POINT" -> "POINT" -> &'P'
*/

	printf("%s\n",*--*cpp+++1);
/*
	cpp -> &(c+2)
	cpp++ -> &(c+2)		cpp -> &(c+1)
	*cpp++ -> *&(c+2) -> c+2  -> &"POINT"   //c+1   
	--*cpp++ -> c+1 -> &"NEW"
	*--*cpp++ -> *&"NEW" -> "NEW" -> &'N'
	*--*cpp+++1 -> &'N'+1 -> &'E'
*/
	printf("%s\n",*cpp[-2]+3);
/*
	cpp -> &(c+1)
	cpp[-2] -> *(cpp-2) -> *(&(c+1)-2) -> *&(c+3) -> c+3 -> &"FIRST" 
	*cpp[-2] -> *&"FIRST" -> "FIRST" -> &'F'
	*cpp[-2]+3 -> &'F'+3 -> &'S'
*/

	printf("%s\n",cpp[-1][-1]+1);   
/*
	cpp-> &(c+1)
	cpp[-1] -> *(cpp-1) -> *(&(c+1)-1) -> *&(c+1) -> c+1 -> &"NEW"
	cpp[-1][-1] -> *(cpp[-1]-1) -> *(&"NEW"-1) -> *&"ENTER" ->
	&'E'
	cpp[-1][-1]+1 -> &'E'+1 -> &'N'
*/
	return 0;
}
#endif
#if 0
#include<stdio.h>

void func(const int* pa){//const int* pa = &a
	//int* a = pa;
	//*a = 10;	//由于c语言的不完善性，这样操作编译可以通过，就导致了const失去了其意义
}

int main(){
	int arr[2][3] = {0};
	int (*parr)[3] = arr;
	//parr[0][1] = 5;
	//*(*(parr+1)+2) = 6;
	int a = 5;
	int b = 10;
	//常量指针
	const int* pa = &a;
	func(&a);
	//int* ppa = pa;	//c语言会提示警告，c++直接报错
	//*pa = 10; //语法错误
	//指针常量
	int* const pb = &b;
	*pb = 15;
	//pb = &a;	//语法错误
	return 0;
}
#endif

#if 0
#include<stdio.h>

int main(){
	int arr[10] = {1,3,5,7,9,2,4,6,8,99};
/*
	要求，只偏移两次，每次都只能偏移1个模块，访问到数据：
		7,9,3,0
*/
	printf("%d\n",*((int*)((double*)arr+1)+1));
	printf("%d\n",*(int*)((double*)arr+1+1));
	printf("%d\n",*(int*)((short*)arr+1+1));
	printf("%d\n",*((int*)(&arr+1)-1));
	return 0;
}
#endif
#if 0
#include<stdio.h>

int main(){
	int a1[5] = {1,3,5,7,9};
	int a2[5] = {2,4,6,8,10};
	int* ar[2] = {a1,a2};

	int b1[5] = {11,13,15,17,19};
	int b2[5] = {12,14,16,18,20};
	int* br[2] = {b1,b2};

	int** arr[2] = {ar,br};
/*
	要求，使用arr，访问数据，1,3,6,17,20
*/
/*
	arr->&ar
	*arr -> *&ar -> ar -> &a1
	**arr -> *&a1 -> a1 -> &1
	***arr -> *&1 -> 1
*/
	printf("%d\n",***arr);
/*
	arr -> &ar
	*arr -> *&ar -> ar -> &a1
	**arr -> *&a1 -> a1 -> &1
	(**arr+1) -> &1+1 -> &3
	*(**arr+1) -> *&3 -> 3
*/
	printf("%d\n",*(**arr+1));
/*
	arr -> &ar
	*arr -> &a1
	(*arr+1) -> &a1+1 -> &a2
	*(*arr+1) -> *&a2 -> a2 -> &2
	(*(*arr+1)+2) -> &2+2 -> &6
	*(*(*arr+1)+2) -> *&6 -> 6
*/
	printf("%d\n",*(*(*arr+1)+2));
/*
	arr -> &ar
	(arr+1) -> &br
	*(arr+1) -> *&br -> br -> &b1
	**(arr+1) -> *&b1 -> b1 -> &11
	(**(arr+1)+3) -> &11 + 3 -> &17
	*(**(arr+1)+3) -> *&17 -> 17
*/
	printf("%d\n",*(**(arr+1)+3));
/*
	arr -> &ar
	(arr+1) -> &br
	*(arr+1) -> *&br -> br -> &b1
	*(arr+1)+1 -> &b1+1 -> &b2
	*(*(arr+1)+1) -> *&b2 -> b2 -> &12
	*(*(arr+1)+1)+4 -> &12+4 -> &20
	*(*(*(arr+1)+1)+4) ->*&20 -> 20
*/
	printf("%d\n",*(*(*(arr+1)+1)+4));
	return 0;
}
#endif

#if 0
/*
	封装一个函数：要求，它能够传入任意类型的数组。在函数内部，手动输入想要访问的数组的下标，然后返回该下标的地址
	函数外部，根据传入不同的数组返回的地址，打印相应数据类型的数据
	举例：{1,3,5,7,9},内部输入了3，则应该返回&7，外部将数据7打印出来
		"hello",内部输入4，则应该返回&o，外部将数据'o'打印出来
	注意，该函数写好之后不能改变
*/

#include<stdio.h>

void* func(void* arr,int size){
	int pos = 0;
	printf("请输入下标位置:");
	scanf("%d",&pos);
	while(getchar()!=10);
	return (char*)arr+pos*size;//注意这里偏移的并不是char*的类型  而是char类型的1字节，即指针的基础类型
}

/*
	在做通用化设计的时候，通常参数都会选取void*来接受任意类型的指针。
	void*指针在偏移的时候，一定要配合传入一个原本数据的内存大小来使用
*/

int main(){
	int arr[5] = {1,3,5,7,9};
	char str[6] = "world";
	double drr[5] = {1.6,2.1,3.5,4.3,5.7};
	char* ptr[5] = {"你好","中国","1908","上海","海同"};
	void* data = func(ptr,8);
	printf("%s\n",*(char**)data);
	//printf("%g\n",*(double*)data);
	return 0;
}
#endif


