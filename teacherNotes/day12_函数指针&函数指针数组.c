/*
	函数指针：
		当一个函数名单独出现的时候(也就是没有跟括号发生调用)，那么此时，函数名其实就是一个指针
	所以说，我们可以申请一个指针，去指向该函数名。一旦指向成功之后，使用函数调用的形式调用该指针，就等于在调用该指针指向的函数
	函数指针的申明方式:
		指向的函数的返回值类型 + (*指针名)(指向的函数的形参列表)
*/
/*
	封装函数的时候，有一个非常重要的原则，相同的部分，直接写入函数，不同的部分使用传参来解决。
	注意：这里使用传参解决的不同的部分，不仅仅可以解决数据不同的问题，同时还可以解决代码不同的问题
*/
/*
	函数指针，作为一个指针，自然可以将他存放入一个数组中，那么这样的一个数组就是 函数指针数组
	函数指针数组该如何申明:
		指向的函数的返回值类型 + (*数组名[最大容量])(函数形参类型)
*/
/*
	段错误发生的原因：
	① 试图访问空指针上的值
	② 试图修改野指针地址上的值
	③ 试图修改常量指针地址上的值
*/


#if 1
#include<stdio.h>

typedef int (*stdio)(const char*,...);

int main(){
	//int printf(const char *format, ...);
	int data = 0;
	//int (*s)(const char*,...) = scanf;
	//int (*p)(const char*,...) = printf;
	stdio s = scanf;
	stdio p = printf;
	s("%d",&data);
	while(getchar()!=10);
	p("data = %d\n",data);
	return 0;
}
#endif
#if 1
#include<stdio.h>

void print_int(void* data){
	printf("%d\n",*(int*)data);
}

void print_char(void* data){
	printf("%c\n",*(char*)data);
}

void print_double(void* data){
	printf("%g\n",*(double*)data);
}

void print_str(void* data){
	printf("%s\n",(char*)data);
}

void func(void* data,void (*print)(void*)){
	print(data);
}

/*
	封装一个函数：技能计算两个数的平方和，又能计算两个数的立方和
*/

int main(){
	int a = 5;
	char b = 'x';
	double c = 3.14;
	char* str = "你好上海";
	func(str,print_str);
	func(&a,print_int);
	return 0;
}
#endif
#if 1
#include<stdio.h>

int f2(int data){
	return data*data;
}

int f3(int data){
	return data*data*data
}

int func(int a,int b,int (*f)(int)){
	//return a*a+b*b;
	//return a*a*a+b*b*b;
	return f(a) + f(b);
}

int main(){
	
	return 0;
}
#endif
#if 1
#include<stdio.h>

void print_int(void* data){
	printf("%d ",*(int*)data);
}

void print_char(void* data){
	printf("%c ",*(char*)data);
}

void print_double(void* data){
	printf("%g ",*(double*)data);
}

void print_str(void* data){
	printf("%s ",*(char**)data);
}

void print_data(void* arr,int len,int size,void (*print)(void*)){
	int i = 0;
	for(i=0;i<len;i++){
		print(arr+i*size);
	}
	printf("\n");
}

int main(){
	int arr[5] = {1,3,5,7,9};
	char str[6] = "world";
	double drr[5] = {1.6,2.1,3.5,4.3,5.7};
	char* ptr[5] = {"你好","中国","1908","上海","海同"};
/*
	封装一个函数，要求能够遍历输出以上4种类型的数组
*/
	func(arr,5,4,print_int);
	func(str,5,1,print_char);
	func(drr,5,8,print_double);
	func(ptr,5,8,print_str);
}

#endif
#if 1
/*
	编写一个通用冒泡排序，选择排序
*/

#include<stdio.h>
#include<string.h>

#define BSORT(arr,len,type) {int i = 0,j =0;type temp;for(i=0;i<len-1;i++){for(j=0;j<len-1;j++){if(arr[j]<arr[j+1]){temp = arr[j];arr[j] = arr[j+1];arr[j+1] = temp;}}}}

void print_int(void* data){
	printf("%d ",*(int*)data);
}

void print_char(void* data){
	printf("%c ",*(char*)data);
}

void print_double(void* data){
	printf("%g ",*(double*)data);
}

void print_str(void* data){
	printf("%s ",*(char**)data);
}

void print_data(void* arr,int len,int size,void (*print)(void*)){
	int i = 0;
	for(i=0;i<len;i++){
		print(arr+i*size);
	}
	printf("\n");
}

int comp_int(void* a, void* b){
	return *(int*)a - *(int*)b;
}

int comp_char(void* a, void* b){
	return *(char*)a - *(char*)b;
}

int comp_double(void* a, void* b){
	if(*(double*)a - *(double*)b < 0){
		return -1;
	}else{
		return 1;
	}
}

int comp_str(void* a, void* b){
	return strcmp(*(char**)a,*(char**)b);
}

void bubblesort(void* arr,int len,int size,int (*compare)(void*,void*)){
	char temp[size];
	int i = 0,j = 0;
	for(i=0;i<len-1;i++){
		for(j=0;j<len-1;j++){
			if(compare((char*)arr+j*size,(char*)arr+(j+1)*size)<0){//arr[i]<arr[i+1] -> arr[i] - arr[i+1] < 0
				// -> *((int*)arr + i) - *((int*)arr + i+1) < 0
				/*temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;*/
				memcpy(temp,arr+j*size,size);
				memcpy(arr+j*size,arr+(j+1)*size,size);
				memcpy(arr+(j+1)*size,temp,size);
			}
		}
	}
}

void selectsort(void* arr,int len,int size,int (*compare)(void*,void*)){
	int i = 0,j = 0;
	int max = 0;
	char temp[size];
	for(i=0;i<len-1;i++){
		max = i;
		for(j=i;j<len;j++){
			if(compare(arr+j*size,arr+max*size)>0){//arr[j] > arr[max]
				max = j;
			}
		}
		/*temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;*/
		memcpy(temp,arr+max*size,size);
		memcpy(arr+max*size,arr+i*size,size);
		memcpy(arr+i*size,temp,size);
	}
}

void quicksort(void* arr,int len,int size,int (*compare)(void*,void*)){
	char* left = (char*)arr;
	char* right = (char*)arr + (len-1)*size;
	if(left>=right){return;}
	char* l = left;
	char* r = right;
	char* key = l;
	char temp[size];
	while(l<r){
		while(l<r){
			if(compare(r,key)>0){
				break;
			}
			r = r - size;
		}
		while(l<r){
			if(compare(l,key)<0){
				break;
			}
			l = l + size;
		}
		memcpy(temp,l,size);
		memcpy(l,r,size);
		memcpy(r,temp,size);
	}
	memcpy(temp,l,size);
	memcpy(l,key,size);
	memcpy(key,temp,size);
	quicksort(arr,(l-left)/size,size,compare);
	quicksort(l+size,(right-l)/size,size,compare);
}

int main(){
	int arr[5] = {1,3,5,7,9};
	char str[6] = "world";
	double drr[5] = {1.6,2.1,3.5,4.3,5.7};
	char* ptr[5] = {"hello","china","1908","shanghai","iotek"};
/*
	降序排序:
		思路：
			1 先将冒泡排序写出来
			2 然后将数组访问方式，改写成通用指针的偏移访问方式
			3 最后确定哪一部分的代码相同，哪一部分不同，不同部分封装函数传入
*/
	//bubblesort(arr,5,4,comp_int);
	//selectsort(arr,5,4,comp_int);
	//quicksort(arr,5,4,comp_int);
	BSORT(arr,5,int);
	print_data(arr,5,4,print_int);

	//bubblesort(str,5,1,comp_char);
	//selectsort(str,5,1,comp_char);
	//quicksort(str,5,1,comp_char);
	BSORT(str,5,char);
	print_data(str,5,1,print_char);

	//bubblesort(drr,5,8,comp_double);
	//selectsort(drr,5,8,comp_double);
	//quicksort(drr,5,8,comp_double);
	BSORT(drr,5,double);
	print_data(drr,5,8,print_double);

	//bubblesort(ptr,5,8,comp_str);
	//selectsort(ptr,5,8,comp_str);
	//quicksort(ptr,5,8,comp_str);
	//print_data(ptr,5,8,print_str);
	return 0;
}
#endif
#if 1
#include<stdio.h>

typedef int (*stdio_t)(const char*,...);

int main(){
	int data = 0;
	//int (*arr[2])(const char*,...) = {printf,scanf};
	stdio_t arr[2] = {printf,scanf};
	arr[0]("请输入数据:");
	arr[1]("%d",&data);
	while(getchar()!=10);
	arr[0]("data = %d\n",data);
	return 0;
}
#endif
#if 1
#include<stdio.h>

int main(){
	//int* pa;
	//*pa = 5;
	char* str = "hello";
	str[0] = 'H';
	return 0;
}
#endif
#if 0
#include<stdio.h>

int main(){
	int arr[6] = {1,3,5,7,9,11};
	printf("%d\n",&arr[3] - &arr[0]);
	return 0;
}
#endif
#if 1
#include<stdio.h>

double add(double a,double b){
	return a + b;
}

double sub(double a,double b){
	return a - b;
}

double mul(double a,double b){
	return a * b;
}

double div(double a,double b){
	return a / b;
}

typedef double (*cal_t)(double,double);

int main(){
	double a = 0,b = 0;
	char ch = 0;
	cal_t cal[4] = {add,sub,mul,div};
	while(1){
		printf("请输入表达式:");
		scanf("%lf %c %lf",&a,&ch,&b);
		while(getchar()!=10);
		int pos = (ch=='+') + (ch=='-')*2 + (ch=='*')*3 + (ch=='/')*4-1;
		printf("%g %c %g = %g\n",a,ch,b,cal[pos](a,b));
	}
	return 0;
}
#endif
#if 0
/*
	编写一个注册系统：
		要求：注册的账号为字符数组，密码也为字符数组
		账号和密码注册成功之后，将账号和密码分别存放进入一个char*类型的nameDB数组中和char*类型的pswdDB数组中
		要求
			①注册的时候，保证防重复注册
			②要求，第一个账号注册完成之后，能够顺利注册第二个账号
			③没有段错误
*/

#include<stdio.h>
#include<string.h>

int find_data(char** nameDB,char* name,int len){
	int i = 0;
	for(i=0;i<len;i++){
		if(strcmp(nameDB[i],name)==0){
			return i;
		}
	}
	return -1;
}

void regist(char** nameDB,char** pswdDB,int* len){
	char name[20] = {0};
	char pswd[20] = {0};
	printf("请输入账号:");
	scanf("%s",name);
	while(getchar()!=10);
	//防重复
	int res = find_data(nameDB,name,*len);
	if(res>=0){
		printf("该账号已存在\n");
		return ;
	}
	printf("请输入密码:");
	scanf("%s",pswd);
	while(getchar()!=10);
	strcpy(nameDB[*len],name);
	strcpy(pswdDB[*len],pswd);
	(*len)++;
}

int main(){
	char* nameDB[10] = {0};
	char* pswdDB[10] = {0};
	int i = 0;
	for(i=0;i<10;i++){
		//char name[20] = {0};
		//char pswd[20] = {0};
		char* name = calloc(1,20);
		char* pswd = calloc(1,20);
		nameDB[i] = name;
		pswdDB[i] = pswd;
	}
	int len = 0;
	int ch = 0;
	while(1){
		printf("1:注册\n");
		printf("2:退出\n");
		printf("请选择:");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				regist(nameDB,pswdDB,&len);
				break;
			case 2:
				return 0;
		}
	}
	return 0;
}
#endif



