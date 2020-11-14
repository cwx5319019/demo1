//ps elf   查看 PID 和 PPID

#include<stdio.h>
#include<unistd.h>
int main(void){
/*
	函数名：fork函数
	//pid_t fork(void);
	功能：创建一个子进程
	特性: 调用一次返回两次
		    向父进程返回大于 0 的值（等于子进程的pid）
			向子进程返回等于 0 的值 （表示自己生成）
			当fork函数执行成功后，子进程会拷贝父进程所有资源
*/			
	pid_t pid = fork();
	printf("pid = %d\n",pid);
	switch(pid){
		case -1:
			perror("error");
			break;
		case 0:
			printf("我是子进程：%d\n",pid);
			break;
		default:
			printf("我是父进程：%d\n",pid);
			break;
	}
	sleep(1);  
	//如果不放睡眠，父进程运行完事程序就会退出，也就是爷爷进程不会等待孙子进程运行完事。
	//所以睡眠一秒等待 孙子进程完事，就不会出现下面运行的情况
	return 0;
}
/*
iotek@iotekclass:~/XH1908/C高级/day2$ ./a.out
pid = 5596
我是父进程：5596
iotek@iotekclass:~/XH1908/C高级/day2$ pid = 0
我是子进程：0
*/

/*
iotek@iotekclass:~/XH1908/C高级/day2$ ./a.out
pid = 5612
我是父进程：5612
pid = 0
我是子进程：0
iotek@iotekclass:~/XH1908/C高级/day2$ 
*/






