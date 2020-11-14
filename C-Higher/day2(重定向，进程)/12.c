//实现自己的一个myshell,同时把执行的命令结果重定向输出到文件.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char** argv){
	int fd_1 = 0,fd_2 = 0;
	if(strcmp(argv[1],"+")==0){
		fd_1 = open(argv[3],O_WRONLY|O_CREAT,0666);
		int res_1 = 0;
		res_1 = dup2(fd_1,1);
		FILE* fp = fdopen(res_1,"w");
		fprintf(fp,"%s\n",argv[2]);
		fclose(fp);
		close(fd_1);
	}else if(strcmp(argv[1] , "++")==0){
		fd_2 = open(argv[3],O_WRONLY|O_CREAT,0666);
		int res_2 = 0;
		res_2 = dup2(fd_2,1);
		lseek(res_2,0,SEEK_END);
		FILE* fp1 = fdopen(res_2,"w");
		fprintf(fp1,"%s\n",argv[2]);
		fclose(fp1);
		close(fd_2);
	}
	
	return 0;
}


















