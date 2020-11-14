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
