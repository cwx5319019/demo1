#include<stdio.h>

int main(){
	char temp[50] = {0};
	FILE* fp = fopen("./test1.txt","r");
	int res = 0;
	while(1){
		//feof函数会判断传入的文件描述符的当前光标位置是否已经到达了文件末尾。如果到达了，则返回1，每到达则返回0
		res = fscanf(fp,"%s",temp);
		if(res==-1){break;}
		//if(feof(fp)==1){break;}
		printf("temp = %s\n",temp);
	}
	fclose(fp);
	return 0;
}
/*
	使用fprintf以及fscanf为学生管理系统添加加载和保存功能
	也就是说，无论添加多少个学生，要求关闭打开程序后，之前添加的学生都要存在
*/
