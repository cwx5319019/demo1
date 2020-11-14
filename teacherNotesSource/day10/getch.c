#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<assert.h>
#include<string.h>
char getch(){  
		char c = 0; 
		struct termios org_opts;
		struct termios new_opts;
		int res=0;  
		res=tcgetattr(STDIN_FILENO,&org_opts);//获取终端标准输入流所有属性，并将它存入org_opts所在地址上
		assert(res==0);
		//memcpy(&new_opts, &org_opts, sizeof(org_opts));
		new_opts = org_opts;
		new_opts.c_lflag &=~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL); 
		tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
		c=getchar();  
		res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
		assert(res==0);  
		return c;  
}
