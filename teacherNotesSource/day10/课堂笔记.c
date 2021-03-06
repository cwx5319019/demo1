/*
	字符串 和 字符数组
	字符数组：和普通拥有相同的特性和操作方式。并且字符数组自身还有特有的操作方式
	字符串同样的拥有自身的表达方式，使用一个指针指向一个字符串
	字符串和字符数组最本质的区别就是:字符数组是变量，字符串是常量。在运用方面，如果没有改变该字符串的可能型的话，使用字符数组和字符串没有任何区别。如果需要改变，则只能使用字符数组。
*/
/*
	字符数组的访问方式：
		① 与普通数组一样，直接遍历整个数组然后逐一访问
		② 字符数组特有的访问方式：使用格式占位符%s来打印或者接受整个字符串
	注意：字符数组声明的时候，一定要预留一个容量的空间，让系统存放结束符
*/
/*
	字符数组的输入方式：字符数组的输入方式有3种
		① scanf中使用%s进行格式占位
		② 使用函数gets
		③ 使用函数fgets
*/
/*
	字符串的合法性输入：在很多输入的场合，我们只希望输入特定的字符。也就是，当输入特定字符的时候，终端上才会显示这些字符，当输入非法字符的时候，终端上则不会显示这些字符
	要实现以上目标，总共需要做到如下几个步骤
		 输入数据后，判断输入的数据是否符合要求，复合要求则在终端上输出
			① 为了做到输入数据后，立刻进入内存进行判断，所以，我们需要首先关闭标准输入流的缓存
			② 为了保证判断成功后输出，不成功的话则不输出，则还需要关闭标准输入流的输入显示，这个时候，无论输入任何数据，都不会在终端上显示，然后开始判断，输入的数据时候合法，如果合法，则使用printf等函数输出到终端上
			③ 当每一个合法数据出现时，记得在输出到终端上的同时，将他保存到字符数组中。
		比如说，输入的内容为123abc+-*，合法的只有123abc，那么此时，在终端上只能显示123abc，字符数组内也只能存放123abc
*/
/*
	
*/

#if 0
#include<stdio.h>

int main(){
	char str[20] = {'h','e','l','l','o'};//字符数组
	char str2[20] = "world";//字符数组
	char str3[20] = "hello world";//字符串
	str2[0] = 'W';
	//str3[0] = 'H';
	char* str4 = str2;
	//str4[0] = 'h';

	//printf("str2 = %s\n",str2);
	int i = 0;
	for(i=0;str2[i]!=0;i++){
		printf("%c",str2[i]);
	}//遍历字符数组的时候只能使用这种方式
	printf("\n");
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<string.h>

int _strcmp(char* str,char* ptr){
	int i = 0;
	for(i=0;str[i]!=0;i++){
		if(str[i]!=ptr[i]){
			break;
		}
	}
	return str[i] - ptr[i];
}

int _strcat(char* str,char* ptr){
	//int len = strlen(str);
	int i = 0,j = 0;
	for(i=0;str[i]!=0;i++);
	//strcpy(&str[len],ptr);
	for(j=0;ptr[j]!=0;j++){
		str[i++] = ptr[j];
	}
}

int main(){
	char str[10] = "hello";
	char ptr[10] = "world";
	_strcat(str,ptr);
	printf("str = %s\n",str);
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<string.h>

void getstring(char* str,int len){
	fgets(str,len,stdin);
	int pos = strlen(str);
	if(str[pos-1] == '\n'){
		str[pos-1] = 0;
	}
}

int main(){
	char str[10] = {0};
	
	//scanf("%s",str);
	//fgets(str,10,stdin);
	getstring(str,10);
	printf("str = %s\n",str);
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<user.h>

int main(){
	printf("请输入字符串:");
	char str[20] = {0};
	getstring(str,20);
	printf("str = %s\n",str);
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<string.h>

void _strtok(char* str,char* ptr){
	int i = 0,j = 0;
	for(i=0;ptr[i]!=0;i++){
		for(j=0;str[j]!=0;j++){
			if(str[j] == ptr[i]){
				str[j] = 0;
			}
		}
	}
}

int main(){
	char str[20] = "hello world";
	_strtok(str," ");
	printf("str = %s\n",str);
	return 0;
}
#endif
#if 0
#include<stdio.h>

int main(){
	char ch = getchar();
	printf("ch = %c\n",ch);
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<user.h>
#include<termios.h>

int main(){	
	srand(time(0));
	int i = 0;
	char ch = 0;
	int data = 0;
	struct termios org_opts;
	struct termios new_opts;
	tcgetattr(STDIN_FILENO,&org_opts);
	new_opts = org_opts;
	new_opts.c_lflag &=~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL); 
	printf("按回车开始开奖\n");
	printf("__-__-__-__");
	while(1){
		ch = getch();
		if(ch==10){break;}
	}
	printf("\033[9D");
	fflush(stdout);
	tcsetattr(0,TCSANOW,&new_opts);
	for(i=0;i<1000;i++){
		data = rand()%100;
		if(data<10){
			printf("\b");
		}else{
			printf("\b\b");
		}
		printf("%d",data);
		fflush(stdout);
		usleep(1000);
	}
	printf("-__");
	fflush(stdout);
	for(i=0;i<1000;i++){
		data = rand()%100;
		if(data<10){
			printf("\b");
		}else{
			printf("\b\b");
		}
		printf("%d",data);
		fflush(stdout);
		usleep(1000);
	}
	printf("-__");
	fflush(stdout);
	for(i=0;i<1000;i++){
		data = rand()%100;
		if(data<10){
			printf("\b");
		}else{
			printf("\b\b");
		}
		printf("%d",data);
		fflush(stdout);
		usleep(1000);
	}
	printf("-__");
	fflush(stdout);
	for(i=0;i<1000;i++){
		data = rand()%100;
		if(data<10){
			printf("\b");
		}else{
			printf("\b\b");
		}
		printf("%d",data);
		fflush(stdout);
		usleep(1000);
	}
	tcsetattr(STDIN_FILENO,TCSANOW,&org_opts);
	while(1);
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<assert.h>
#include<string.h>
char getch(){  
		char c = 0; 
		struct termios org_opts;
		struct termios new_opts;
		int res=0;  
		res=tcgetattr(STDIN_FILENO,&org_opts);//获取终端标准输入流所有属性，并将它存入org_opts所在地址上
		assert(res==0);
		//memcpy(&new_opts, &org_opts, sizeof(org_opts));
		new_opts = org_opts;
		new_opts.c_lflag &=~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL); 
		tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
		c=getchar();  
		res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
		assert(res==0);  
		return c;  
}
#endif
#if 0
#include<stdio.h>
#include<string.h>

void getstring(char* str,int len){
	fgets(str,len,stdin);
	int pos = strlen(str);
	if(str[pos-1] == '\n'){
		str[pos-1] = 0;
	}
}
#endif
#if 0
#include<stdio.h>
#include<assert.h>
#include<string.h>

int main(){
	int res = 0;
	assert(res==0);
	char str[20] = "hello world";
	char ptr[20] = {0};
	int arr[5] = {1,3,5,7,9};
	int brr[5] = {0};
	memcpy(brr,arr,20);
	printf("brr[0] = %d,brr[4] = %d\n",brr[0],brr[4]);
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<user.h>

int main(){
	while(1){
		char ch = getch();
		printf("ch = %d\n",ch);
	}
	/*char ch = 0;
	scanf("%c",&ch);*/
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<assert.h>
#include<string.h>
char getch(){  
		char c = 0; 
		struct termios org_opts;
		struct termios new_opts;
		int res=0;  
		res=tcgetattr(STDIN_FILENO,&org_opts);
		assert(res==0);
		new_opts = org_opts;
		new_opts.c_lflag &=~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL ); 
		tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
		
		
		c = getchar();  
		res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
		assert(res==0);  
		return c;  
}

int main(){
	char ch = 0;
	while(1){
		ch = getch();
		printf("ch = %c\n",ch);
	}
	return 0;
}
#endif
#if 0
/*
	使用getch编写一个输入合法性的案例，只允许输入数字字符和字母，其他字符不允许输入
	输入完成后，还需要整体显示刚才输入的合法内容
*/

#include<stdio.h>
#include<user.h>

int main(){
	char str[50] = {0};
	char ch = 0;
	int i = 0;
	while(1){
		ch = getch();
		if(ch == '\n'){
			printf("\n");
			str[i] = 0;
			break;
		}else if((ch>='0' && ch<='9')||(ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){
			printf("*");
			str[i++] = ch;
		}else if(ch == 127){
			printf("\b \b");
			if(i>0){i--;}
		}
	}
	printf("输入的密码为:%s\n",str);
	return 0;
}
#endif
#if 0
#ifndef user_h_
#define user_h_

void getstring(char*,int);

#endif





