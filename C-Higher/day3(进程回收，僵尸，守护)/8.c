
//------wait()函数接收kill的命令退出-----
//------kill -l 查看所有信号 -----------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	pid_t pid;
	int i = 0;
	for(;i<3;i++){
		pid = fork();
		if(pid ==0)break;
	}
	if(pid == 0){
		printf("i am child,my PID = %d\n",getpid());
		while(1){
			sleep(1);fflush(stdout);
		}
	}
	if(pid > 0){
		sleep(1);
		int wpid = 0,retval;
		printf("请输入等待的子进程pid：");
		scanf("%d",&wpid);
		printf("我正在等待子进程：%d 结束...\n",wpid);
		//等到想等待的子进程结束，这个函数第三个值需要传递一个信号
		//kill -19 和这个宏配对使用 WUNTRACED
		//kill -18 和这个宏配对使用 WCONTINUED   //貌似不能用
		//kill -9 + 进程号   直接杀死进程
		//killall a.out 杀死全部a.out进程 这个的用sudo权限
		retval = waitpid(wpid,NULL,WCONTINUED);
		printf("我等到了子进程：%d\n",retval);
	}
	return 0;
}












