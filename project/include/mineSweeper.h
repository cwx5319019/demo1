#ifndef mineSweeper_h_
#define mineSweeper_h_

void setGame(int(* a)[30],int,int,int,int,int);//初始化雷区

int printB(int(* a)[30],char(* b)[30],int,int);//显示雷区的画面

void printA(int(* a)[30],int,int);//显示真实的雷区

void runGame(int(* a)[30],char(* b)[30],int,int,int,int);//扫雷的结果判断及逻辑递归

void mineSweeper();//扫雷的主界面

#endif
