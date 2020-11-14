   
命令：
file a.out             //查看属性 
whereis gcc            //在哪个位置 
ls -al /usr/bin/gcc*   //查看版本gcc指向的地方 //gcc类似一个快捷方式
gcc-4.6 day4.c         //也可以编译

执行结果：

iotek@iotekclass:~/XH1908/作业$ file a.out
a.out: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0xbedc672cff25bdf48d91a10ab642affa7b7d15b4, not stripped
iotek@iotekclass:~/XH1908/作业$ whereis gcc
gcc: /usr/bin/gcc /usr/lib/gcc /usr/bin/X11/gcc /usr/share/man/man1/gcc.1.gz
iotek@iotekclass:~/XH1908/作业$ ls -al /usr/bin/gcc*
lrwxrwxrwx 1 root root      7 12月 18  2014 /usr/bin/gcc -> gcc-4.6
-rwxr-xr-x 1 root root 306200  4月 16  2012 /usr/bin/gcc-4.6
iotek@iotekclass:~/XH1908/作业$ gcc-4.6 day4.c
iotek@iotekclass:~/XH1908/作业$ 



	
	-----习题1--------
	char a = 130;
	printf("%d\n",(int)a);
	
	-----习题2--------
	-5 的16进制数
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<unistd.h>
	int main(int argc,char** argv){
		char a = -5;
		printf("%x\n",a);
		return 0;	
	}
	
	-----习题3--------
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<unistd.h>
	int main(int argc,char** argv){
		int i = 0 ,j = 0;
		for(j = 0;j<argc;j++){
			for(i = 0;i<strlen(argv[0]);i++){
				printf("%c",argv[0][i]);
				fflush(stdout);
				sleep(1);
			}
			printf("\n");
		}
		//printf("argc= %d\n",argc);
	 return 0;
	}
	-----习题4--------
	ffffffff查找 grep stdin /usr/include/stdio.h -n
	
	---------运行结果------------------------
	iotek@iotekclass:~/XH1908$ grep stdin /usr/include/stdio.h -n
	169:extern struct _IO_FILE *stdin;		Standard input stream.  
	173:#define stdin stdin
	433: Read formatted input from stdin.
	481: Read formatted input from stdin into argument list ARG.
	540: Read a character from stdin.
	631: Get a newline-terminated string from stdin, removing the newline.
	-----习题5--------
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<unistd.h>
	int main(int argc,char** argv){
		printf("hello iotek");      //默认输入到屏幕 ->stdout 带缓存
		fprintf(stdout,"hello iotek"); //stdout 带缓存
		fprintf(stderr, "error");  //stderr 不带缓存，优先级高
		return 0;	
	}
	







