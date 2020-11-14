#if 0
	动态内存分配
		int arr[] = {1,2,4,5}; 数组指针名是常量指针，不能更改指向
		指针作为形参要改变指向的时候，实参也要放指针地址，做地址修改才能改变，否则不会改变指向
	堆空间(堆空间地址和栈空间地址有区别)
		malloc  此函数不能初始化  配套使用初始化函数 memset(void* ptr,int value,int size)  最佳初始化 0
		calloc  开辟数组用calloc 开辟单一空间malloc 
		free
	查看运行内存插件	
	 sudo apt-get install valgrind
	运行
		valgrind ./a.out



#endif
#if 0
#include<stdio.h>
int main(){
	int arr[] = {1,2,4,5};
	int brr[] = {6,7,9,0};
	int* prr = brr;
	prr = brr;
	
	printf("%p\n",arr);
	printf("%p\n",brr);	
	printf("%p\n",prr);
}	
#endif
#if 0
// -----堆空间申请-------------
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* p = malloc(4);   // 四个字节空间申请  用一个栈空间指针指向申请的堆空间首地址
	*p = 10;
	
	printf("%p\n",p);
	printf("%p\n",&p);

	free(p);   //释放
	return 0 ;
}

#endif
#if 0
// -----数组堆空间申请-------------
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* p = malloc(4 * 10);   //数组是连续的内存空间，所以可以再堆中申请
	memset (p,0,40);

	


	free(p);
	return 0 ;
}


#endif
#if 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insert_data(int** arr,int* vol ,int* len ){
	int data = 0;
	if(*len >= *vol){
		printf("开始扩容\n");
		*vol *= 2;
		int* brr = malloc(4 * *vol);
		memset(brr,0,4 * (*vol));
		memcpy(brr,*arr,*len*4);
		free(*arr);
		*arr = brr;
		printf("brr = %p\n",brr);
	}
	printf("请输入数值：");
	scanf("%d",&data);
	//data = *len+1;
	while(getchar() != 10);
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
				printf("arr = %p\n",arr);
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

