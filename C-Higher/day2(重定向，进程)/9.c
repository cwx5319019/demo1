#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void){
/*
	实现程序；
	次数用变量n表示
	子进程打印字符串“I am child...”打印5次
	父进程打印字符串“I am parent...”打印3次
*/
	//fork函数
	pid_t pid = fork(); 
	int n = 0;
	char* str = NULL;
	printf("pid = %d\n",pid);
	switch(pid){
		case -1:
			perror("error");
			exit(1);
		case 0:
			n = 5;
			str = "我是子进程";
			break;
		default:
			n = 3;
			str = "我是父进程";
			break;
	}
	for (;n>0;n--){
		puts(str);
		sleep(1);
	} 
	if(pid>0) sleep(1);
	
	return 0;
}
