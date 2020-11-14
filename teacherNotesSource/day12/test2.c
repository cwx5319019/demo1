/*
	编写一个注册系统：
		要求：注册的账号为字符数组，密码也为字符数组
		账号和密码注册成功之后，将账号和密码分别存放进入一个char*类型的nameDB数组中和char*类型的pswdDB数组中
		要求
			①注册的时候，保证防重复注册
			②要求，第一个账号注册完成之后，能够顺利注册第二个账号
			③没有段错误
*/

#include<stdio.h>
#include<string.h>

int find_data(char** nameDB,char* name,int len){
	int i = 0;
	for(i=0;i<len;i++){
		if(strcmp(nameDB[i],name)==0){
			return i;
		}
	}
	return -1;
}

void regist(char** nameDB,char** pswdDB,int* len){
	char name[20] = {0};
	char pswd[20] = {0};
	printf("请输入账号:");
	scanf("%s",name);
	while(getchar()!=10);
	//防重复
	int res = find_data(nameDB,name,*len);
	if(res>=0){
		printf("该账号已存在\n");
		return ;
	}
	printf("请输入密码:");
	scanf("%s",pswd);
	while(getchar()!=10);
	strcpy(nameDB[*len],name);
	strcpy(pswdDB[*len],pswd);
	(*len)++;
}

int main(){
	char* nameDB[10] = {0};
	char* pswdDB[10] = {0};
	int i = 0;
	for(i=0;i<10;i++){
		//char name[20] = {0};
		//char pswd[20] = {0};
		char* name = calloc(1,20);
		char* pswd = calloc(1,20);
		nameDB[i] = name;
		pswdDB[i] = pswd;
	}
	int len = 0;
	int ch = 0;
	while(1){
		printf("1:注册\n");
		printf("2:退出\n");
		printf("请选择:");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch){
			case 1:
				regist(nameDB,pswdDB,&len);
				break;
			case 2:
				return 0;
		}
	}
	return 0;
}
