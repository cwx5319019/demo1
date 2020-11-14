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
