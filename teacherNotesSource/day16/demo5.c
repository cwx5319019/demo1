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
