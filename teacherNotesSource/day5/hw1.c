#include<stdio.h>


int main(){
	char data = 0;
	printf("请输入数据:");
	scanf("%c",&data);
	//while(getchar()!=10);
	if(data>='A'&&data<='Z'){
		printf("%c\n",data+32);
	}else if(data>='a'&&data<='z'){
		printf("%c\n",data-32);
	}else if(data>='1'&&data<='9'){
		printf("-%c\n",data);
	}else if(data=='-'){
		scanf("%c",&data);
		if(data==10){
			data = '0';
		}
		printf("%c\n",data);
	}else{
		printf("0\n");
	}
	//while(getchar()!=10);
	return 0;
}
