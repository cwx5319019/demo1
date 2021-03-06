/*
	加载保存的概念：
		为了让程序内存中的所有数据，在程序结束之后，依旧存在，我们就需要将这些内存中的数据，保存进入硬盘，那么无论是断电还是程序结束，这些数据都不会消失。
	等待程序下一次运行的时候，再从硬盘中，将这些数据加载带程序的内存中，这样一来，这些数据就一直存在于内存中了

	简单来说：就是在断电之前将内存中数据保存进去硬盘。在通电之后，将硬盘中的数据写入内存

	由于内存运行效率高，硬盘运行效率低，所以，我们尽量操作硬盘的次数越少越好。通常情况下，我们选择程序开始没多久就加载数据，在程序结束之前的最后一刻才一次性的保存所有数据。千万不要一有数据改动，就写入硬盘，这样一来程序对于硬件的依赖程度太高
*/
/*
	如何实现加载保存，通过文件io系统
		文件io的操作需要用到以下3组函数
			1:fprintf,fscanf
				类比于scan			sscanf
			sprintf和printf是从终端读取数据以及将数据写入中，fscanf和fprintf就是从文件读取数据以及将数据写入文件
			用法类似于printf和scanf

				函数名：fprintf
				函数参数：FILE* fp，const char* format，...
				函数分析：将字符串format写入到fp这个文件指针(文件描述符)所指向的文件中去
				所以，这里的关键就变成了，如何让fp来指向一个指定的文件。使用函数fopen
				
				函数名：fopen
				函数参数：const char* pathname,const char* mode
				函数返回值：FILE* fp
				函数分析：使用 mode 方式，打开pathname文件(pathname可以包含具体路径，也可以是单独的文件名，如果是单独的文件名则默认当前路径),并且使用fp指向该打开的文件。最后将fp返回给外部，让外部也可以使用一个指针指向打开的文件
				其中，mode有以下几种情况
					r :以只读的方式打开文件，如果文件不存在，则打开失败，文件成功打开后，光标位置位于文件的最末尾
					r+:以只读写的方式打开文件，如果文件不存在，则打开失败，文件成功打开后，光标位置位于文件的最末尾

					w :以只写的方式打开文件，如果文件不存在，则创建文件后打开，如果文件存在，则删除源文件重新创建后打开。成功打开后，光标位置位于文件的最开头
					w+:以只读写的方式打开文件，如果文件不存在，则创建文件后打开，如果文件存在，则删除源文件重新创建后打开。成功打开后，光标位置位于文件的最开头
					a :以添加的方式打开文件，如果文件不存在，则创建文件后打开，如果文件存在，则直接打开，并且打开后光标位置处于文件的最末尾
			注意：只要调用过fopen打开文件的话，当不再使用文件的事情，注意使用fclose将文件关闭
			2:fputs,fgets
				不同于fscanf，他是格式化的输入(遇到空格和回车就停止输入)
				fgets属于行输入(只有遇到回车才会停止输入)
			3:fwrite,fread
				fread属于格式化读取函数，他会根据给定的模块大小严格读取数据	
				函数名：fwrite
				函数参数：void* ptr,int size,int num,FILE* fp
				函数分析：将以ptr为首地址的，总共num个模块的内存上的数据，写入到fp所指向的文件中，每个模块size个字节
				注意：fwrite 输出的数据，如果是字符串的话，则会原样输出，如果是其他类型的数据的话，则会以二进制的形式输出
				所以，fwrite输出的数据，只能用fread来读取。反过来说，fread只能读取fwrite所写的文件
*/
#if 0
#include<stdio.h>

int main(){
	char str[20] = "123hello";
	char ptr[20] = {0};
	int data = 0;
	//sscanf(str,"%d",&data);
	sprintf(ptr,"%s",str);
	printf("ptr = %s\n",ptr);
	return 0;
}
#endif
#if 0
#include<stdio.h>

int main(){
	FILE* fp = fopen("./test1.txt","w");
	fprintf(fp,"hello world %d\n",123);
	fclose(fp);
	return 0;
}
#endif
#if 0
#include<stdio.h>

int main(){
	char temp[50] = {0};
	FILE* fp = fopen("./test1.txt","r");
	int res = 0;
	while(1){
		//feof函数会判断传入的文件描述符的当前光标位置是否已经到达了文件末尾。如果到达了，则返回1，每到达则返回0
		res = fscanf(fp,"%s",temp);
		if(res==-1){break;}
		//if(feof(fp)==1){break;}
		printf("temp = %s\n",temp);
	}
	fclose(fp);
	return 0;
}
/*
	使用fprintf以及fscanf为学生管理系统添加加载和保存功能
	也就是说，无论添加多少个学生，要求关闭打开程序后，之前添加的学生都要存在
*/
#endif
#if 0
#include<stdio.h>

int main(){
	FILE* fp = fopen("./test2.txt","w");
	fputs("hello world",fp);
	fclose(fp);
	return 0;
}
#endif
#if 0
#include<stdio.h>

int main(){
	char data[50] = {0};
	FILE* fp = fopen("./test2.txt","r");
	char* res = 0;
	while(1){
		res = fgets(data,2,fp);
		//if(feof(fp)==1){break;}
		if(res==NULL){break;}
		printf("%s",data);
	}
	fclose(fp);
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<string.h>

int main(){
	char data[20] = "你好中国";
	int num = 5;
	FILE* fp = fopen("./test3.txt","w");
	//fwrite(data,1,strlen(data),fp);
	fwrite(&num,4,1,fp);
	fclose(fp);
	return 0;
}
#endif
#if 0
#include<stdio.h>

int main(){
	char data[20] = {0};
	FILE* fp = fopen("./test3.txt","r");
	int res = 0;
	while(1){
		res = fread(data,1,1,fp);
		//if(feof(fp)==1){break;}
		if(res == 0){break;}
		printf("%s",data);
	}
	fclose(fp);

	return 0;
}
#endif
#if 1
//---------------保存数据----------------------

void save_stu(stu_t* DB,int len){
	FILE* fp = fopen("./DB.txt","w");
	int i = 0;
	for(i=0;i<len;i++){
		//fprintf(fp,"%s %s %d %d %d %d\n",DB[i].name,DB[i].pswd,DB[i].id,DB[i].score.chinese,DB[i].score.math,DB[i].score.english);
		fwrite(&DB[i],sizeof(stu_t),1,fp);
	}
	fclose(fp);
}

void load_stu(stu_t* DB,int* len){
	FILE* fp = fopen("./DB.txt","r");
	if(fp == NULL){return;}
	int res = 0;
	stu_t temp = {0};
	while(1){
		//res = fscanf(fp,"%s %s %d %d %d %d",temp.name,temp.pswd,&temp.id,&temp.score.chinese,&temp.score.math,&temp.score.english);
		res = fread(&temp,sizeof(stu_t),1,fp);		
		if(res == 0){break;}
		DB[*len] = temp;
		(*len)++;
	}
	fclose(fp);
}
#endif
#if 0
/*
	使用fgets和fputs实现shell指令cp功能
	cp 源文件名 目标文件名，这两个文件名都是在终端上输入的
*/
#include<stdio.h>

int main(int argc,char** argv){
	if(argc!=3){
		fprintf(stderr,"cp: 缺少了文件操作数\nTry 'cp --help' for more information.\n");
	}
	FILE* rfp = fopen(argv[1],"r");
	FILE* wfp = fopen(argv[2],"w");
	char* res = 0;
	char buf[2] = {0};
	while(1){
		res = fgets(buf,2,rfp);
		if(res==0){break;}
		fputs(buf,wfp);
	}
	fclose(rfp);
	fclose(wfp);
	return 0;
}
#endif
#if 0
/*
	使用fgets和fputs实现shell指令cp功能
	cp 源文件名 目标文件名，这两个文件名都是在终端上输入的

	实现cp的文件复制到文件夹的功能,所以先要判断目标文件名是否为目录文件
	1:在文件名中寻找.,没有.代表该文件是目录文件
*/
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int ifdir(char* tar){
	int i = 0;
	for(i=0;tar[i]!=0;i++){
		if(tar[i]=='.'){
			return 1;
		}
	}
	return 0;
}

int main(int argc,char** argv){//假设argv[2] = 111
	if(argc!=3){
		fprintf(stderr,"cp: 缺少了文件操作数\nTry 'cp --help' for more information.\n");
	}
	char argv2[20] = "./";
	//int ret = ifdir(argv[2]);
	struct stat temp = {0};
	lstat(argv[2],&temp);

	if(S_ISDIR(temp.st_mode)==1){
		strcat(argv2,argv[2]);// ./111
		strcat(argv2,"/");// ./111/
		strcat(argv2,argv[1]);// ./111/3.c
	}
	FILE* rfp = fopen(argv[1],"r");
	FILE* wfp = fopen(argv2,"w");//./111/argv[1]
	char* res = 0;
	char buf[2] = {0};
	while(1){
		res = fgets(buf,2,rfp);
		if(res==0){break;}
		fputs(buf,wfp);
	}
	fclose(rfp);
	fclose(wfp);
	return 0;
}
#endif























































