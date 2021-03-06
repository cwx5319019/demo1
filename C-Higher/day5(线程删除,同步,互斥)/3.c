
//创建1个子进程，在子进程中获取当前工作路径并打印出来，并在当前路径下创建文件1.txt,
//使用信号SIGALRM间隔1秒向其中写入数据“Hello”，按下ctrl+c就结束子进程，父进程打印“Child process end”

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
void signal_fun(int signo){   //子pid
	int fd ;
	fd = open("1.txt",O_CREAT | O_RDWR | O_APPEND,0666);
	write(fd,"Hello\n",6); 
	//新方法也可以
	//system("echo \"hello\" >> 1.txt ");  
	
	alarm(1);
}
void signal_fun2(int signo){  //子pid
	kill(getpid(),SIGKILL);
}
void signal_fun3(int signo){  // 父pid 
	printf("child process end\n");
	signal(SIGINT,SIG_DFL);
}
int main(){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		//system("pwd");
	/*
		知识点：
		
		得到当前工作路径并保存到数组buf
		char *getcwd(char *buf, size_t size);
		char buf[100] = ""; 
		getpwd(buf,100);
	*/

		signal(SIGALRM,signal_fun);
		alarm(1);
		signal(SIGINT,signal_fun2);
		while(1);
	}else if(pid > 0){
		signal(SIGINT,signal_fun3);
		while(1);
	}
	
	return 0;
}

//---------------------------------------------------------


#include<stdio.h>
#include<signal.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

pid_t pid;
void catch_alarm(int signo){
	system("echo \"hello\" >> 1.txt ");
	alarm(1);
}

void catch_sigint(int signo){
	printf("我是父进程，我要终止子进程\n");
	printf("%s,pid == %d\n",__FUNCTION__,pid);
	kill(9,pid);
	puts("child process end...");
}

int main(void){
	pid = fork();
	if(pid == 0){
	/*
		char pwd[100] = "";
		getcwd(pwd,100);
		printf("当前路径是：%s\n",pwd);
	*/
		int fd;
		fd = open("./1.txt",O_RDWR | O_CREAT,0666);
		if(fd == -1){
			perror("open failed...");
			exit(-1);
		}
		signal(SIGALRM,catch_alarm);
		alarm(2);
		while(1);

	}
	if(pid > 0){
		signal(SIGINT,catch_sigint);
		printf("parent,pid == %d\n",pid);
		while(1){
			putchar('.');fflush(stdout);sleep(1);
		}
	}
	return 0;
}


















