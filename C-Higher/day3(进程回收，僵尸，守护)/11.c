
//-----守护进程----------很重要
//-----只能靠sudo killall a.out 或者 kill -9 进程号 杀掉  //ps -elf 去查找那个孤儿进程

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(){
	pid_t pid;
	pid = fork();
	if(pid < 0){
		perror("fork fail...");
		exit(-1);
	}
	//正常情况
	if(pid > 0){
		printf("我是父进程，我将退出...");
		exit(1);
	}
	//孤儿进程
	int fd;
	char* str = "我是守护进程...\n";
	//实现守护进程
	setsid();
	//重新定义会话进程  (终端就是会话目录，使用setsid()创建自己会话目录，所以关闭终端也不会收到影响)
	chdir("/");//脱离当前目录限制，切换到根目录
	umask(0);  //打开文件rwx系统访问权限
	int i = 0;
	for(;i<65536;i++){ //关闭当前进程已经打开的所有FD
		close(i);
	}
	while(1){
		fd = open("/tmp/daemon.txt",O_CREAT | O_RDWR | O_APPEND,0666);
		write(fd,str,strlen(str));
		close(fd);
		sleep(5);
	}
	return 0;
}







