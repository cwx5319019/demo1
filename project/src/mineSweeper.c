#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"mineSweeper.h"
#include"menu.h"

//初始化雷区
void setGame(int(* a)[30],int r,int l,int n,int x,int y){
	srand(time(0));
	int count=0;
	//随机布置n个雷区，但是以用户首次输入的坐标为中心的9个格子不能布置雷
	while(count<n){
		int i=rand()%r;
		int j=rand()%l;
		if(i>=x-1 && i<=x+1 && j>=y-1 && j<=y+1){
			continue;
		}else if(a[i][j]==0){
			a[i][j]=9;
			count++;
		}
	}
	//除了雷，每个格子的数字表示它周围的雷的颗数
	//四个角
	if(a[0][0]!=9)
		a[0][0]=(a[0][1]==9)+(a[1][0]==9)+(a[1][1]==9);
	if(a[0][l-1]!=9)
		a[0][l-1]=(a[0][l-2]==9)+(a[1][l-2]==9)+(a[1][l-1]==9);
	if(a[l-1][0]!=9)
		a[l-1][0]=(a[l-2][0]==9)+(a[l-2][1]==9)+(a[l-1][1]==9);
	if(a[l-1][l-1]!=9)
		a[l-1][l-1]=(a[l-2][l-2]==9)+(a[l-2][l-1]==9)+(a[l-1][l-2]==9);
	//除四个角的四条边
	for(int k=1;k<l-1;k++){
		if(a[0][k]!=9)
			a[0][k]=(a[0][k-1]==9)+(a[1][k-1]==9)+(a[1][k]==9)+(a[1][k+1]==9)+(a[0][k+1]==9);
		if(a[l-1][k]!=9)
			a[l-1][k]=(a[l-1][k-1]==9)+(a[l-2][k-1]==9)+(a[l-2][k]==9)+(a[l-2][k+1]==9)+(a[l-1][k+1]==9);
		if(a[k][0]!=9)
			a[k][0]=(a[k-1][0]==9)+(a[k-1][1]==9)+(a[k][1]==9)+(a[k+1][1]==9)+(a[k+1][0]==9);
		if(a[k][l-1]!=9)
			a[k][l-1]=(a[k-1][l-1]==9)+(a[k-1][l-2]==9)+(a[k][l-2]==9)+(a[k+1][l-2]==9)+(a[k+1][l-1]==9);
	}
	//四条边以内
	for(int m=1;m<r-1;m++){
		for(int n=1;n<l-1;n++){
			if(a[m][n]!=9){
				a[m][n]=(a[m-1][n-1]==9)+(a[m-1][n]==9)+(a[m-1][n+1]==9)+(a[m][n-1]==9)+(a[m][n+1]==9)+(a[m+1][n-1]==9)+(a[m+1][n]==9)+(a[m+1][n+1]==9);
			}
		}
	}
}


//显示用户可以看见的界面
int printB(int(* a)[30],char(* b)[30],int r,int l){
	int count=0;
	printf("  ");
	for(int i=0;i<l;i++){
		printf("%2d ",i);
	}
	printf("\n");
	for(int i=0;i<r;i++){
		printf("%2d ",i);
		for(int j=0;j<16;j++){
			printf("%c  ",b[i][j]);
			if(b[i][j]=='p' && a[i][j]==9)
				count++;
		}
		printf("\n");
	}
	return count;
}


//显示真实的雷区
void printA(int(* a)[30],int r,int l){
	printf("  ");
	for(int i=0;i<l;i++){
		printf("%2d ",i);
	}
	printf("\n");
	for(int i=0;i<r;i++){
		printf("%2d ",i);
		for(int j=0;j<16;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
}


//雷区的打开及递归打开
//用户输入的坐标位置若为0则递归打开，否则仅打开这一个格子
void runGame(int(* a)[30],char(* b)[30],int r,int l,int x,int y){
	b[x][y]=a[x][y]+48;
	if(a[x][y]==0){
		if(x>0 && y>0 && (b[x-1][y-1]=='*' || b[x-1][y-1]=='p' || b[x-1][y-1]=='i')){
			runGame(a,b,r,l,x-1,y-1);
		}
		if(x>0 && (b[x-1][y]=='*' || b[x-1][y]=='p' || b[x-1][y]=='i')){
			runGame(a,b,r,l,x-1,y);
		}
		if(x>0 && y<l-1 && (b[x-1][y+1]=='*' || b[x-1][y+1]=='p' || b[x-1][y+1]=='i')){
			runGame(a,b,r,l,x-1,y+1);
		}
		if(y>0 && (b[x][y-1]=='*' || b[x][y-1]=='p' || b[x][y-1]=='i')){
			runGame(a,b,r,l,x,y-1);
		}
		if(y<l-1 && (b[x][y+1]=='*' || b[x][y+1]=='p' || b[x][y+1]=='i')){
			runGame(a,b,r,l,x,y+1);
		}
		if(x<r-1 && y>0 && (b[x+1][y-1]=='*' || b[x+1][y-1]=='p' || b[x+1][y-1]=='i')){
			runGame(a,b,r,l,x+1,y-1);
		}
		if(x<r-1 && (b[x+1][y]=='*' || b[x+1][y]=='p' || b[x+1][y]=='i')){
			runGame(a,b,r,l,x+1,y);
		}
		if(x<r-1 && y<l-1 && (b[x+1][y+1]=='*' || b[x+1][y+1]=='p' || b[x+1][y+1]=='i')){
			runGame(a,b,r,l,x+1,y+1);
		}
	}
}


//扫雷的主要操作函数
void mineSweeper(){
	while(1){
		int r=0,l=0,n=0;
		char op=0;
		while(1){
			system("clear");
			printf("请输入雷区行数（9～24）：");
			scanf("%d",&r);
			while(getchar()!=10);
			printf("请输入雷区列数（9～30）：");
			scanf("%d",&l);
			while(getchar()!=10);
			printf("请输入雷数（1～%d）：",(int)(r*l*0.25));
			scanf("%d",&n);
			while(getchar()!=10);
			if(r<9 || r>24 || l<9 || l>30 || n<1 || n>(int)r*l*0.25){
				printf("\n请输入合格的数字！\n");
			}else{
				break;
			}
		}
		//定义真实雷区数组和显示雷区数组
		int a[24][30]={0};
		char b[24][30]={0};
		int x=0,y=0;
		//初始化显示雷区数组
		for(int i=0;i<r;i++){
			for(int j=0;j<l;j++){
				b[i][j]='*';
			}
		}
		//打印显示雷区数组
		int count=printB(a,b,r,l);
		//用户输入首个坐标，方便系统初始化，避免第一次就踩到雷
		while(1){
			printf("请输入坐标（0,0）～（%d,%d）：",r-1,l-1);
			scanf("%d%d",&x,&y);
			while(getchar()!=10);
			if(x<0 || x>r-1 || y<0 || y>l-1){
				printf("\n请输入合格的数字！\n");
			}else{
				break;
			}
		}
		//初始化真实雷区数组
		setGame(a,r,l,n,x,y);
		runGame(a,b,r,l,x,y);
		//游戏过程
		while(1){
			count=printB(a,b,r,l);
			if(count<n){
				printf("\np 3 12表示标记（3,12）为地雷，o 12 2表示打开（12,2），i 3 3表示不确定(3,3)是否是雷--均为小写\n");
				printf("\nq 0 0回车退出游戏！\n");
				while(1){
					printf("请输入操作编号及坐标（0,0）～（%d,%d）：",r-1,l-1);
					scanf("%c%d%d",&op,&x,&y);
					while(getchar()!=10);
					if(op=='q'){
						return;
					}else if((op=='p' || op=='o' || op=='i') && x>=0 && x<=r-1 && y>=0 && y<=l-1){
						break;
					}else{
						printf("\n请输入正确的字符！\n");
					}
				}

				if(b[x][y]!='*' && b[x][y]!='p' && b[x][y]!='i'){
					printf("请输入未扫描的坐标（即*,p,i号位置）！\n");
				}else if(op=='p' || op=='i'){
					b[x][y]=op;
				}else if(op=='o' && a[x][y]==9){
					printA(a,r,l);
					printf("很遗憾，你踩到雷！\n");
					break;
				}else{
					runGame(a,b,r,l,x,y);
				}
			}else{
				printf("你找出了所有地雷，你赢了！\n");
				while(1){
					printf("\n是否再来一局！（是：Y/y;否：N/n）：");
					scanf("%c",&op);
					while(getchar()!=10);
					if(op=='Y' || op=='y'){
						break;
					}else if(op=='N' || op=='n'){
						return;
					}else{
						printf("\n请输入正确的编号\n");
					}
				}
			}
		}
	}
}
