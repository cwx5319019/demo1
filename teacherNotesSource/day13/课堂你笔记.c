/*
	动态内存分配：
		当一个数组空间使用完毕之后(数据已满)，这个时候，如果再次存放数据的话，就会造成数据越界存放。所以，我们应该控制数组的容量与长度的关系，保证数据不能越界存放。
		如果，新的数据一定是要存入一个已经存满的数组中的话，那么就应该对该数组进行扩容操作。
		扩容操作：
			① 申请更大容量的数组
			② 将原数组中的数据，完全拷贝给新的数组
			③ 使用各种手段，将代码中的原数组的地址，更改成新数组的地址
	想要保证形参和实参的同步性，必须有以下两个操作
		① 传参时候传指针
		② 操作时候取值
*/
/*
	由于以上操作，全都建立在栈空间上完成的，所以函数内部产生的更大的数组，在函数结束的同时，就会被释放，导致使用更大的数组的时候，其实是一个非法操作。要解决这个问题其实很简单，那就是让更大的数组，在堆空间上申请。
	堆空间的特点：
		手动申请：使用函数malloc或者calloc就可以申请指定大小的堆空间内存，并且申请出来的堆空间内存的首地址，就是malloc/calloc函数的返回值
		手动释放：使用函数free就可以释放一段堆空间的内存
*/
/*
	函数名：malloc
	函数参数：int size
	函数返回值：void* ptr
	函数分析：malloc函数会在堆空间上开辟size个字节大小的内存，并且将ptr指向这段堆空间内存的首地址，最终将ptr返回给外部，让外部同样能够拥有这段堆空间内存的首地址
	malloc申请堆空间内存，都不会做初始化的操作。在这个指针指向的内存空间未初始化的情况下，直接进行访问的话，就会出现内存错误
	所以，我们在使用malloc的时候，必须配套初始化函数
	函数名：memset
	函数参数：void* ptr,int value,int size
	函数分析：将以ptr为首地址的，大小为size个字节的内存空间上的每一个字节全都初始化成value
	所以，使用memset最佳初始化的value应该就是0
*/
/*
	函数名：calloc
	函数参数：int num,int size
	函数返回值:void* ptr
	函数分析：开辟 num 个模块的堆空间大小，每个模块size个字节，所以总共开辟了 num * size 个字节的堆空间内存,并将ptr指向这段堆空间的首地址，最终返回
	注意：calloc出来的堆空间内存，默认初始化为0
*/
/*
	注意：虽然calloc非常好用(因为无需配合memset使用)，但是我们人为的规定，开辟单一模块堆空间内存的时候，必须使用malloc，开辟数组的时候，必须使用calloc
*/
/*
	函数名：realloc
	函数参数：void* ptr,int size
	函数返回值：void* ptr
	函数分析：将ptr所指向的堆空间内存重新分配size个字节大小，并且向外返回
	注意：这个函数如果不放在等号的右侧的话，编译的时候会发生警告
	并且：realloc并不是通过调用malloc以及free来实现的内存扩容，而是直接针对内存本身进行操作的。这样一来的话，会产生大量的内存碎片，内存碎片一旦过多，直接段错误
	所以结论：当想要实现扩容功能的时候，还是自己使用malloc+memcpy+free去实现，realloc尽量不要使用
*/

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert_data(int** arr,int* vol,int* len){
	int data = 0;
	if(*len >= *vol){
		printf("开始扩容\n");
		*vol *= 2;
		int* brr = malloc(4 * *vol);
		memset(brr,0,4 * *vol);
		//int* brr = calloc(*vol,4);
		//*arr = realloc(*arr,*vol);
		memcpy(brr,*arr,*len*4);
		free(*arr);
		*arr = brr;
		printf("brr = %p\n",brr);
	}
//	printf("请输入数据:");
//	scanf("%d",&data);
	data = *len+1;
//	while(getchar()!=10);
	(*arr)[*len] = data;
	(*len)++;
}

int main(){
	int vol = 5;
	int len = 0;
	int ch = 0;
	int* arr = malloc(sizeof(int)*vol);
	memset(arr,0,sizeof(int)*vol);
	printf("arr = %p\n",arr);
	while(1){
		printf("1:添加数据\n");
		printf("2:打印数据\n");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				insert_data(&arr,&vol,&len);
				break;
			case 2:
				printf("prr = %p\n",arr);
				break;
			default:
				break;
		}
	}
	return 0;
}

#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	//想要在对空间上申请一段内存空间，这段内存空间能够存储整型数据
//	int* pa = malloc(4*10);
//	memset(pa,0,40);
	int* pa = calloc(10,4);
/*
	int i = 0;
	for(i=0;i<10;i++){
		pa[i] = i*10;
	}

	for(i=0;i<10;i++){
		printf("pa[%d] = %d\n",i,pa[i]);
	}
*/
	printf("%d\n",pa[0]);
	free(pa);
	return 0;
}

#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int* pa = malloc(4);
	memset(pa,0,4);
	pa = realloc(pa,40);
	free(pa);
	return 0;
}

#include<stdio.h>

void func(int* a,int* b){
	//*a = *b;
	a = b;
}

int main(){
	int a = 5;
	int b = 10;
	func(&a,&b);
	printf("a = %d\n",a);
	return 0;
}
#endif
























