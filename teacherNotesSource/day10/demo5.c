#include<stdio.h>
#include<string.h>

void _strtok(char* str,char* ptr){
	int i = 0,j = 0;
	for(i=0;ptr[i]!=0;i++){
		for(j=0;str[j]!=0;j++){
			if(str[j] == ptr[i]){
				str[j] = 0;
			}
		}
	}
}

int main(){
	char str[20] = "hello world";
	_strtok(str," ");
	printf("str = %s\n",str);
	return 0;
}
