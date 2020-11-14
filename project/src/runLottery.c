#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<termios.h>
#include"runLottery.h"

//系统开奖
void runLottery(int* number){
	int data=0;
	printf("__-__-__-__-__");
	printf("\033[14D");
	struct termios oldOpts;
	struct termios newOpts;
	int res=0;
	res=tcgetattr(STDIN_FILENO,&oldOpts);
	assert(res==0);
	newOpts=oldOpts;
	newOpts.c_lflag &=~ (ICANON | ECHO);
	res=tcsetattr(STDIN_FILENO,TCSANOW,&newOpts);
	assert(res==0);

	for(int i=0;i<5;i++){
		for(int j=0;j<1000;j++){
			srand(time(0));
			data=rand()%99+1;
			printf("%2d",data);
			printf("\b\b");
			fflush(stdout);
			usleep(3000);
		}
		number[i]=data;
		printf("\033[2C-");
	}

	printf("\b ");
	printf("\033[u");
	printf("\n\n\n\n\n\n\n");
	res=tcsetattr(STDIN_FILENO,TCSANOW,&oldOpts);
	assert(res==0);
}
