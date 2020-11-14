#include<stdio.h>
#include<string.h>

int _strcmp(char* str,char* ptr){
	int i = 0;
	for(i=0;str[i]!=0;i++){
		if(str[i]!=ptr[i]){
			break;
		}
	}
	return str[i] - ptr[i];
}

int _strcat(char* str,char* ptr){
	//int len = strlen(str);
	int i = 0,j = 0;
	for(i=0;str[i]!=0;i++);
	//strcpy(&str[len],ptr);
	for(j=0;ptr[j]!=0;j++){
		str[i++] = ptr[j];
	}
}

int main(){
	char str[10] = "hello";
	char ptr[10] = "world";
	_strcat(str,ptr);
	printf("str = %s\n",str);
	return 0;
}
