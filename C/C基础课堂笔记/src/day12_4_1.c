#if 0
	通用化设计：
	函数指针
		封装函数原则，相同部分写入函数，代码不同封装成多个函数
	带参宏
		优势能传类型
		
	函数指针数组
		
	选择几种方法：
		if...else
		switch 
		三目运算符
		函数指针数组
		
	段错误原因
		1.访问空指针
		2.修改野指针
		3.修改常量指针地址
		
		







#endif
#if 1

#include<stdio.h>
#include<string.h>

int find(char** nameDB,char* str,int len){
	int i = 0;
	for (i = 0;i<len;i++){
		if (strcmp (nameDB[i],str) == 0 ){
			return 1;
			
		}	
	}
	return -1;
}

void insert(char* str, char** nameDB,char** pswdDB,int* len){
	printf("请输入帐号:");
	int i = 0;
	for(i = 0 ;i<6;i++){
		scanf("%c",&str[i]);
	}
	while(getchar() != 10);
	strcpy(nameDB[*len],str); //指针数组里的值是空指针，所以段错误
	//printf("%s \n",str);
	int res =find(nameDB,str,*len);
	if(res >=0){
		printf("帐号重复！\n");
		return ;
	}
	printf("请输入密码：");
	for(i = 0 ;i<6;i++){
		scanf("%c",&str[i]);
	}
	while(getchar() != 10);
	strcpy(pswdDB[*len],str);
	//printf("%s \n",str);
	(*len)++;	

}
void print(char** nameDB,int len){
	int i = 0;
	for(i = 0;i<len;i++){
		printf("%s  ",nameDB[i]);
	}
	printf("\n");
}


int main(){
	char str[20] = {0};
	char* nameDB[20] = {0};  //char* 四个字节
	char* pswdDB[20] = {0};
	int len = 0;
	int i = 0;
	for(i = 0;i<6;i++){
		char str[20] = {0};
		nameDB[i] = str;
		pswdDB[i] = str;
	}
	
	while(1){
	insert(str,nameDB,pswdDB,&len);
	print(nameDB,len);
	}
	
	


	return 0;
}		
	
	
	








#endif
#if 0
#include<stdio.h>

double l(double num){
	return num*num*num;

}

double p(double num){
	return num*num;

}

double print(double num1, double num2,double (*print)(double))
{

	return l(num)+p(num)
}


int main()
{
	double num = 0.0;
	//printf("请输入：");
	//scanf("%g",&num);
	//while(getchar()!= 10);
	
	print(10,l);
	return 0;
}



#endif



#if 0
#include<stdio.h>
typedef int (*stdio)(const char* ,...) ;

int main()
{

	int data = 0;
	//int (*s) (const char* ,...) = scanf;
	//int (*p) (const char*, ...) = printf;
	//s("%d",&data);
	//while(getchar() != 10);
	//p("%d\n",data);
	
	stdio s = scanf;
	stdio p = printf;
	s("%d",&data);
	while(getchar() != 10);
	p("%d\n",data);

	return 0;
}

#endif

#if 0

#include<stdio.h>


void arr1(void* arr,int n){
	int i = 0;
	for(i = 0;i<n;i++){
		printf("%d ",*((int*)arr+i));
	}
}
void str1(void* str,int n){
	int i = 0;
	for(i = 0;i<n-1;i++){
		printf("%c",*((char*)str+i));
	}
}
void drr1(void* drr,int n){
	int i = 0;
	for(i = 0;i<n;i++){
		printf("%g ",*((double*)drr+i));
	}
}
void ptr1(void* ptr,int n){
	int i = 0;
	for(i = 0;i<n;i++){
		printf("%s ",*((char**)ptr+i));
	}	
}


void print(void* str ,int n,void (*print)(void*,int ))
{
	print(str,n);
	printf("\n");
}

int main()
{
	int arr[5] = {1,3,5,7,9};
	char str[6] = "world";
	double drr[5] = {1.6,2.1,3.5,4.3,5.7};
	char* ptr[5] = {"你好","中国","1908","上海","海同",};
	
	print(arr,5,arr1);
	print(str,6,str1);
	print(drr,5,drr1);
	print(ptr,5,ptr1);

	return 0;
}


#endif

#if 0
#include<stdio.h>
#include<string.h>






void print_char(void* data)
{
	printf("%c ",*(char*)data);
}
void print_int(void* data)
{
	printf("%d ",*(int*)data);
}
void print_double(void* data)
{
	printf("%g ",*(double*)data);
}
void print_str(void* data)
{
	printf("%s ",(char*)data); // char* 特别注意  %s获取第一个地址，然后输出
}

void print_data(void* arr,int len,int size,void (*print)(void*)){
	int i = 0;
	for(i=0;i<len;i++){
		print(arr+i*size);
	}
	printf("\n");
}

int cmp_char(void* a , void* b)
{
	return *(char*)a - *(char*)b;

}
int cmp_int(void* a , void* b)
{
	return *(int*)a - *(int*)b;

}
int cmp_double(void* a , void* b)
{
	if(*(double*)a - *(double*)b <0){
		return -1;
	}else{
		return 1;
	}
}
int cmp_str(void* a , void* b)
{
	return strcmp(*(char**)a ,*(char**)b);

}
void bubblesort(void* arr,int len,int size,int (*compare)(void*,void*  ))
{
//内存拷贝不分数据类型
	char temp[size] ;//char开辟一个字节空间
	int i = 0,j = 0;
	for(j = 0;j<len-1; j++){
		for(i = 0;i<len-1;i++){
			if( compare((char*)(arr+i*size) ,(char *)(arr+i*size+size)) <0){
				memcpy (temp,arr+i*size,size);
				memcpy (arr+i*size,arr+(i+1)*size,size);
				memcpy (arr+(i+1)*size,temp,size);
			}
		}
	}
}

/*
void quicksort(void* arr, int len, int size, int(*compare)(void* , void* ))
{
	char* left = (char* )arr;
	char* right = (char* )arr + (len - 1)*size;
	if(left >= right ){return;}
	char* l = left;
	char* r = right;
	char* key = l;
	char temp[size];
	while(l<r){
		while(l<r){
			if(compare(r,key)>0){
				break;
			}
			r = r-size;
		}
		while(l<r){
			if(compare(r,key)<0){
				break;
			}
			l = l+size;
		}
		memcpy (temp ,l,size);
		memcpy(l,r,size);
		memcpy(r,temp,size);
	}
	memcpy(temp,l,size);
	memcpy(l,key,size);
	memcpy(key,temp,size);
	quicksort(arr,(l-left)/size,size,compare);
	quicksort(l+size,(right-l)/size,size,compare);
}
	}

}
*/

int main()
{
	int arr[5] = {1,3,5,7,9};
	//char str[6] = "world";
	//double drr[5] = {1.6,2.1,3.5,4.3,5.7};
	//char* ptr[5] = {"你好","中国","1908","上海","海同"};
	
	
	bubblesort(arr,5,4,cmp_int);
	print_data(arr,5,4,print_int);

	//bubblesort(str,5,1,cmp_char);
	//print_data(str,5,1,print_char);

	//bubblesort(drr,5,8,cmp_double);
	//print_data(drr,5,8,print_double);

	//bubblesort(ptr,5,4,cmp_str);
	//print_data(ptr,5,4,print_str);


	return 0;
}


#endif

#if 0

#include<stdio.h>

typedef int (*stdio_t)(const char*,...);

int main()
{
	int data = 0;
	stdio_t arr[2]  = {printf,scanf};
	arr[0]("请输入数据：");
	arr[1]("%d",&data);
	while(getchar() != 10);
	arr[0]("data = %d\n",data);
	return 0; 
	
}





















#endif
