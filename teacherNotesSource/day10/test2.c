/*
	使用getch编写一个输入合法性的案例，只允许输入数字字符和字母，其他字符不允许输入
	输入完成后，还需要整体显示刚才输入的合法内容
*/

#include<stdio.h>
#include<user.h>

int main(){
	char str[50] = {0};
	char ch = 0;
	int i = 0;
	while(1){
		ch = getch();
		if(ch == '\n'){
			printf("\n");
			str[i] = 0;
			break;
		}else if((ch>='0' && ch<='9')||(ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){
			printf("*");
			str[i++] = ch;
		}else if(ch == 127){
			printf("\b \b");
			if(i>0){i--;}
		}
	}
	printf("输入的密码为:%s\n",str);
	return 0;
}
