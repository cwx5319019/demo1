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
