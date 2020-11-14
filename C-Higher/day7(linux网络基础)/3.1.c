
//建一个文件a.txt,里面写入自己的电话号码，利用管道通信(pipe)实现，
//父进程从文件里面读入电话号码，通过管道送给子进程，子进程打印出来，并存放到b.txt中。

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include <sys/stat.h>
int main(void){
	int fd ;
	fd = open("./3.txt",O_RDONLY);
	pid_t pid;
	pid = fork();
	if(pid > 0){
		char buf[20] = "";
		int res = read(fd,buf,20);
		if(res == -1){
			perror("read error");
			exit(-1);
		}
		int pfd ;
		pfd = open("./333",O_WRONLY);
		int ret = write(pfd,buf,20);
		if(res == -1){
			perror("write error");
			exit(-1);
		}
		wait(NULL);
	}else if(pid == 0){
		int ppfd ;
		ppfd = open("./333",O_RDONLY);
		char ppbuf[20] = "";
		int retval = read(ppfd,ppbuf,20);
		if(retval == -1){
			perror("read error");
			exit(-1);
		}	
		printf("我的号码：%s",ppbuf);
	}
	
	
	return 0;
}





















