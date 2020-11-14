#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<assert.h>
#include<string.h>


int _strlen(char* str){
	int i = 0,count = 0;
	for (i = 0;str[i] != 0;i++ ){
		count++;
	}
	return count;
}

char* _strcpy(char* str,char* ptr){
	int i = 0;
	for(i = 0 ;ptr[i] != 0;i++){
		str[i] = ptr[i];
	}
	return str;
}

int _strcmp(char* str,char* ptr){
	int i = 0;
	for(i = 0;str[i] != 0;i++){
		if(str[i] != ptr[i]){
			break;
		}
	}
	return str[i]-ptr[i];

}
char* _strcat(char* str ,char* ptr){
	int i =0,j = 0;
	for(i =0;str[i] != 0;i++);
	for(j = 0;ptr[j] != 0;j++){
		str[i++] = ptr[j];
	}
	return str;
}

char* _strtok(char* str,char* ptr){
	int i = 0,j = 0;
	for(j = 0;ptr[j] != 0;j++){
		for(i = 0;str[i] != 0;i++){
			if (str[i] == ptr[j]){
				str[i] = 0;
			}
		}
	}
	return str;
}


//----fgets函数会把回车吸收---所以自己改进--getstring

char* getstring(char* str,int len){
	fgets(str,len,stdin);
	int i = 0;
	for(i = 0 ; str[i] != 0; i++){
		if(str[i] == 10){
			str[i] = 0;
		}
	}
	return str;
}

#if 1
//----输入一个数不经过缓存，直接输出--自定义函数getch()

char getch(){
#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<assert.h>
#include<string.h>
char getch(){
	char c = 0;
	struct termios org_opts;
	struct termios new_opts;
	int res = 0;
	res = tcgetattr(STDIN_FILENO,&org_opts);
	assert(res == 0);
	new_opts = org_opts;
	new_opts.c_lflag &=~(ICANON |ECHO| ECHOE | ECHOK | ECHOPRT |ECHOKE | ICRNL);
	tcsetattr(STDIN_FILENO,TCSANOW,&new_opts);
	c = getchar();
	res = tcsetattr(STDIN_FILENO,TCSANOW,&org_opts);
	assert(res ==0);
	return c;	

}
	

}

#endif




int main()
{
	char str[20] = "hello";
	char ptr[20] = "world";
	char ch = 0;

/*
	使用getch编写一个输入合法性的案例，只允许输入数字字符和字母，其他字符不允许输入
	输入完成后，还需要整体显示刚才输入的合法内容
	
*/	
	int i = 0;
	while(1){
		ch = getch();
		if(ch == 10){
			str[i] = 0;
			break;
		}else if((ch >= 'a' && ch<= 'z')||(ch >= 'A' && ch<= 'Z')||(ch >= '0' && ch<= '9')){
			printf("%c",ch);
			str[i++] = ch;
		}else if(ch == 127){
			printf("\b \b");
			if(i>0){i--;}
		}	
	}
	printf("\n");
	printf("%s\n",str);
	
	
	

	return 0 ;
}
























