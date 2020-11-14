#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<termios.h>  
#include<assert.h> 
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
int getch()  //他会返回输入字符的ascii码值
{  
		int c=0;  
		struct termios org_opts, new_opts;  
		int res=0;  
		res=tcgetattr(STDIN_FILENO, &org_opts);  
		assert(res==0);  
		memcpy(&new_opts, &org_opts, sizeof(new_opts));  
		new_opts.c_lflag &=~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT     | ECHOKE | ICRNL);  
		tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);//关闭回显  
		c=getchar();  
		res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);//打开回显
		assert(res==0);  
		return c;  
}

int main(int argc,char** argv){

	struct termios org_opts, new_opts; 
	tcgetattr(STDIN_FILENO, &org_opts);//获得当前终端所有的设置信息,然后将所有的设置信息保存到org_opts中去
	memcpy(&new_opts, &org_opts, sizeof(new_opts)); //将获得的终端信息再复制到new_opts中去
	srand(time(0));
	printf("请输入回车开始开奖\n");
	printf("__-__-__-__");
	int res=0;
	int i=0;
	while(1){
		res=getch();
		if(res==10){break;}
	}
	new_opts.c_lflag &=~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT     | ECHOKE | ICRNL); //重新设置终端信息，添加标准输入不回显，无缓存输设置到new_opts中去
	tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);//通过new_opts设置当前终端
//	int mode = fcntl(STDIN_FILENO,F_GETFL);
//	mode |= O_NONBLOCK;
//	fcntl(STDIN_FILENO,F_SETFL,mode);
	for(i=0;i<1000;i++){
		printf("\033[11D  \b\b");
		printf("%2d",rand()%98+1);
		fflush(stdout);
		usleep(1000);
		//char ch = getch();
		//if(ch==10){break;}
		//sleep(1);
	}
	printf(" \b-  ");
	fflush(stdout);
	for(i=0;i<1000;i++){
		printf("\b\b");
		printf("%2d",rand()%98+1);
		fflush(stdout);
		usleep(1000);
		//char ch = getch();
		//if(ch==10){break;}
		//sleep(1);
	}
	printf(" \b-  ");
	fflush(stdout);
	for(i=0;i<1000;i++){
		printf("\b\b");
		printf("%2d",rand()%98+1);
		fflush(stdout);
		usleep(1000);
		//char ch = getch();
		//if(ch==10){break;}
		//sleep(1);
	}
	printf(" \b-  ");
	fflush(stdout);
	for(i=0;i<1000;i++){
		printf("\b\b");
		printf("%2d",rand()%98+1);
		fflush(stdout);
		usleep(1000);
		//char ch = getch();
		//if(ch==10){break;}
		//sleep(1);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);//通过org_opts恢复终端设置
	//while(1);
	//mode &= ~O_NONBLOCK;
	//fcntl(STDIN_FILENO,F_SETFL,mode);
}

