#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	int i = 0;
	for(i = 0; i < 3; i++) {
		pid = fork();
		if(pid == 0) {
			break;
		}
	}
	if(pid == 0) {
		printf("我是子进程%d\n",getpid());

	}
	if(pid > 0) {
		sleep(1);
		printf("请输入:");
		int wpid = 0, retval;
		scanf("%d",&wpid);
		printf("我正在等待子进程：%d结束\n",wpid);
		retval = waitpid(wpid,NULL,WUNTRACED);
		printf("我等到了子进程%d\n",retval);
	}
	return 0;

}
