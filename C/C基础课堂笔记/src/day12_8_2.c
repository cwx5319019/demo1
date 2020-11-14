#if 0
	加载保存概念
		断电之前把数据保存到硬盘，千万不要一有数据改动就保存硬盘。

	加载保存的实现
		通过文件io
		//sscanf (str,"%s\n",ptr)读取str里的东西存到ptr
		//sprintf(str,"%s\n","123hello")ptr输出到str数组中
		
		
		1.fprintf,fscanf
			他俩是格式化输入输出，遇到空格就停止


		2.fputs, fgets
			fgets是行输入
			fputs并不是行输出 
			
		
		3.fwrite, fread
			通用指针一般配合 size使用






#endif
#if 0
#include<stdio.h>

int main(){
	char str[20] = "123hello";
	char ptr[20] = {0};
	sscanf(str,"%s\n",ptr); 
	//sprintf(ptr,"%s\n"str);
	printf("%s\n",ptr);

	return 0;
	
}
#endif
#if 0
#include<stdio.h>

int main(){
	FILE* fp = fopen("./test.txt","w");
// 指向建立的文件//只写的方式，“w”如果打开的文件已经存在，则会清空，没有则会创建 //实质调用 malloc函数
	fprintf(fp,"hello world %d \n ",123); //把123输入到指向的文件
	fclose(fp); //关闭堆空间 //实质是调用 free()函数
	return 0;
}

#endif
#if 0
#include<stdio.h>

int main(){
	char temp[50] = {0};
	int res = 0;
	FILE* fp = fopen("./test1.txt","r");//./test1.txt如果不存在，fp 就是空指针，后序操作会出现段错误
		while(1){
		res = fscanf(fp,"%s",temp); //读取不到数据返回-1
		if(res == -1)break;    
		//if(feof(fp) == 1)break; //寻找结束符，找到返回1
		printf("%s\n",temp);
	}
	fclose(fp);
	return 0;
}


#endif
#if 0
#include<stdio.h>
int main()
{
	char data[20] = {0};
	FILE* fp = fopen("./test1.txt","r");
	char* res = 0;
	while(1){
		res = fgets(data,2,fp);     //fgtes(data,2,stdin)
 //fgets 返回的是指针，无数据返回的是空
		if(res == NULL)break;
		//if(feof(fp) ==1 ){break;}
		printf("%s",data);
	}
	fclose(fp);

	return 0;
}

#endif
#if 0
// -----------使用fgets 和 fputs  实现cp功能-----------cp 源文件 目标文件
#include<stdio.h>


int main(int argc ,char** argv){
	if(argc != 3)printf("error\n");
	char temp[50] = {0};
	FILE* fp1 = fopen(argv[1],"r");
	FILE* fp2 = fopen(argv[2],"w");
	char* res = 0;
	while(1){
		res = fgets(temp,2,fp1);
		if (res== NULL)break;
		fputs(temp,fp2);
	}
	fclose(fp2);
	fclose(fp1);

	return 0;
}

#endif
#if 1
#include<stdio.h>
// -----------  ./wq/qw/qw/  -----------

int main(int argc ,char** argv){
	if(argc != 3)printf("error\n");
	char temp[2] = {0};
	FILE* fp1 = fopen(argv[1],"r");
	FILE* fp2 = fopen(argv[2],"w");
	char* res = 0;
	int i = 0;
	while(1){
		res = fgets(temp,2,fp1);
		if (res== NULL)break;
		for(i= 0;i<argc;i++){   
			if(argv[2][i] == '.'){
				printf("error\n");
				return 0;
			}
		}       
		fputs(temp,fp2);
	}
	fclose(fp2);
	fclose(fp1);

	return 0;
}

#endif
#if 0



#endif
