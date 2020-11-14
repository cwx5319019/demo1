#include<stdio.h>
#include<string.h>

void getstring(char* str,int len){
	fgets(str,len,stdin);
	int pos = strlen(str);
	if(str[pos-1] == '\n'){
		str[pos-1] = 0;
	}
}
