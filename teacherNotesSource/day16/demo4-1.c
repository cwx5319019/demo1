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
