#if 0
 
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


*/

/*
	
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
	169:extern struct _IO_FILE *stdin;		/* Standard input stream.  */
	173:#define stdin stdin
	433:/* Read formatted input from stdin.
	481:/* Read formatted input from stdin into argument list ARG.
	540:/* Read a character from stdin.
	631:/* Get a newline-terminated string from stdin, removing the newline.
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
	
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void)
{
	//open函数
	int fd;
	fd = open("./1.txt",O_RDONLY);
	//只读方式打开1.txt
	printf("fd=%d\n",fd);
	if(fd == -1){
		perror("open打开文件失败...");
		exit(1);
	}
	//close函数
	int res;
	res = close(fd);
	printf("res1 = %d\n",res);
	res = close(fd);
	//关闭一个已经关闭的文件，会错误,返回 -1
	printf("res2= %d\n",res);
	if(res ==-1){
		perror("close关闭文件失败...");
		exit(1);
	}
	
	return 0;	
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void)
{
	//open函数
	int fd;
	fd = open("./1.txt",O_RDONLY);
	//只读方式打开1.txt
	printf("fd=%d\n",fd);
	if(fd == -1){
		perror("open打开文件失败...");
		exit(1);
	}
	//read函数
	//1.要得数据小于文件中的数据0123456789\n 写的文件后面有个\n
	//2.要得数据大于文件中的数据，返回所有数据
	//3.buff长度小于第三个参数count，会出错误,数组越界
	int size;
	char buf[5] ="";
	size = read(fd,buf,10);
	//从fd里读取10个字节放到buf里
	printf("read读取到了%d字节：%s\n",size,buf);
	
	close(fd);
	
	return 0;	
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(void)
{
	//open函数
	int fd;
	fd = open("./2.txt",O_RDWR);//注意：我如果对文件进行又读又写必须这样写，如果分开写 O_RDONLY | O_WRONLY 它只认 O_WRONLY 这个会把O_RDONLY 覆盖掉
	printf("fd=%d\n",fd);
	
	//write函数  //注意：写完之后指针已经偏移到最后了
	int retval;
	char *buf ="hello world\n";
	retval = write(fd,buf,strlen(buf));
	if(retval == -1){
		perror("写入失败");
		exit(1);
	}else{
		printf("成功写入了%d字节\n",retval);
	}
	//lseek函数
	//把文件指针置于开始，偏移0个字节
	lseek(fd,0,SEEK_SET);

	//read函数
	int size;
	char buf2[20] = "";
	size = read(fd,buf2,strlen(buf2));
	if(size == -1){
		perror("读取失败");
		exit(1);
	}else{
		printf("读取到%d字节：%s\n",size,buf2);
	}
	
	
	//close函数
	int res;
	res = close(fd);
	if(res ==-1){
		perror("close关闭文件失败...");
		exit(1);
	}	
	
	return 0;	
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
	//open函数
	int fd;
	//O_CREAT这个功能被使用时候必须给定文件属性 0222
	//如果打开的文件已经存在，创建就不生效了
	fd = open("./3.txt",O_RDWR|O_CREAT,0222);
	printf("fd=%d\n",fd);   

	return 0;
}

#endif
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
/*
	//open 和 fopen 区别
	//open  行缓存  一行读到\n  直接写入文件 
	//fopen 全缓存  一行读到\n  不理会 等缓存满了在写入文件
	int fd;
	//O_CREAT这个功能被使用时候必须给定文件属性 0222
	fd = open("./4.txt",O_RDWR);
	printf("fd=%d\n",fd); 
	int retval;
	int i = 10;
	while(i--){
		retval = write(fd ,"hello world\n",5);
		printf("写入了%d个字节\n",retval);
		sleep(1);
	}
*/	
	FILE* fp = NULL;
	fp = fopen("./5.txt","w");
	printf("fp=%p\n",fp); 
	int retval;
	char* buf = "hello\n";
	int i = 10;
	while(i--){
		retval = fwrite(buf,strlen(buf),1，fp); 
		//返回值是第三个参数
		printf("写入了%d个字节\n",strlen(buf));
		sleep(1);
	}

	return 0;
}

#endif
#if 0

//练习1：write(1)---写屏幕(printf)，,read(0)--读键盘(scanf)

#endif


