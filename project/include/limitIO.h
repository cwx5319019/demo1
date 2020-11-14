#ifndef limitIO_h
#define limitIO_h

char getch();//获取单个字符已备用

void limitNamePwd(char*,int);//限制输入，只能输入字母和数字，并通过第二个参数设置是否可见

void limitDigit(int*);//限制输入0～99的数字

void limitCash(int*);//限制输入不为负的整数

void limitNum(int*);//限制输入1～5的数字

#endif
