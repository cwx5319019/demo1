
//-------作业第三题------------
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int fd;
	fd = open("./2.txt",O_RDONLY);
	printf("fd= %d\n",fd);
	//FILE* fdopen(int fd , const char* mode);
	//把文件描述符转化为指针
	FILE* fp = NULL;
	fp = fdopen(fd,"r");
	printf("fp = %p\n",fp);
	char buf[10] = "";
	//char* fget(char* s ,int size,FILE* stream);
	//碰到\n 则返回（结束），返回的是文件中的指针位置
	//如果读到文件尾则返回NULL
	char* retval = NULL;
	int intarr[20];
	char i= 0;
	while(1){
		retval = fgets(buf,10,fp);
		if(retval == NULL){
			break;
		}
		puts(buf);
		intarr[i++] = atoi(buf);
		memset(buf,0,10);		
	}
	char j = 0;
	for(j= 0;j<i;j++){
		printf("%d,",intarr[j]);
	}
	printf("\n");
	
	
	
	//----------------
	FILE* fp1 = NULL;
	fp1 = fopen("3.txt","w");
	//int fprintf(FILE* stream ,const char* format,...);
	int size1 = sizeof(intarr)/4;
	char x = 0;
	while(size1--){
		fprintf(fp1,"%d\n",intarr[x++]);
	}
		
	
	return 0;
}


/*
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(void){
	int fd = open("./10.txt",O_RDONLY);
	if(fd == -1){
		perror("open error");
		exit(1);
	}
	int i = 0;
	int intarr[14] = {0};
	char buf[20] = "";
	FILE* fp = fdopen(fd,"r");
	while(fgets(buf,20,fp) != NULL){
		intarr[i++] = atoi(buf);
		memset(buf,0,sizeof(buf));  
	}
	int x = 0,j= 0,temp = 0;
	for(x = 0;x<sizeof(intarr)/4-1;x++){
		for(j = 0;j<sizeof(intarr)/4-1;j++){
			if(intarr[j] > intarr[j+1]){
				temp = intarr[j];
				intarr[j] = intarr[j+1];
				intarr[j+1] = temp;
			}
		}
	}
	FILE* newfp = fopen("./10_1.txt","w");	
	for(x = 0;x<sizeof(intarr)/4;x++){
		fprintf(newfp,"%d\n",intarr[x]);
	}
	close(fd);
	fclose(fp);
	fclose(newfp);
	return 0;
}








*/




















