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
