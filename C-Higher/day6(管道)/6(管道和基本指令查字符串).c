
//-----------------管道---------------------
//--------进程和进程之间传数据要用管道-----------
#if 0

cat mqtt-example.c | grep -r HAL_Free -n
//查找进程的东西要建立管道去查 (查字符串)
// -r递归一直找到最后一个文件  -n 行号

uname -m   uname -a  查看机器信息

#endif
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void){
	FILE* fp = NULL;
	//使用管道执行命令 只读方式打开 存到指针fp
	fp = popen("uname -a","r");
	char buf[100] = "";
	//使用 fgets() 写到 buf[] 里
	fgets(buf,100,fp);
	//puts(buf); 
	printf("uname:%s\n",buf);
	pclose(fp);

	return 0;
}
















