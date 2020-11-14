#if 1
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<user.h>
#include<termios.h>

int main(){
	srand(time(0));
	int i = 0,j=0;
	char ch = 0;
	int data = 0;
	struct termios org_opts;
	struct termios new_opts;
	tcgetattr(STDIN_FILENO,&org_opts);
	new_opts = org_opts;
	new_opts.c_lflag &=~(ICANON |ECHO| ECHOE | ECHOK | ECHOPRT |ECHOKE | ICRNL);
	tcsetattr(0,TCSANOW,&new_opts);
	printf("按回车开始开始\n");
	printf("__-__-__-__");
	while(1){
		ch = getch();
		if(ch == 10){break;}
	}
	printf("\033[9D");
	fflush(stdout);
	//sleep(5);
	for(j = 0;j<4;j++){	
		for(i= 0; i<100;i++){
			data = rand()%100;
			fflush(stdout);
			usleep(10000);
			if(data<10){
				printf("\033[2D");
				printf("0");
			}else{
				printf("\033[2D");
			}
			printf("%d",data);
			fflush(stdout);
		}
		printf("\033[3C");
	}	
	printf("\n");
	tcsetattr(STDIN_FILENO,TCSANOW,&org_opts);
	

	
	
	//while(1);



	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<assert.h>
#include<string.h>

char getch(){
	char c = 0;
	struct termios org_opts;
	struct termios new_opts;
	int res = 0;
	res = tcgetattr(STDIN_FILENO,&org_opts);
	assert(res == 0);//调试检测用
	new_opts = org_opts;
	new_opts.c_lflag &=~(ICANON |ECHO| ECHOE | ECHOK | ECHOPRT |ECHOKE | ICRNL);
	
	tcsetattr(STDIN_FILENO,TCSANOW,&new_opts);
	c = getchar();
	res = tcsetattr(STDIN_FILENO,TCSANOW,&org_opts);
	assert(res ==0);
	return c;	

}
int main(){
	printf("%c \n",getch());
	
	

	return 0;
}





#endif
