/*
使用使用cin,cout完成下面对话框内容：

   What’s you name?

   Xiajiashan(需要从键盘输入)

   Your name is xiajiashan. 
  
*/
#include<iostream>
using namespace std;

int main(int argc, char **argv){
    char str[20] = "";
    cout << "what's your name ?" << endl;
    cin >> str ;
    cout << "your name is " << str << endl;

    return 0;
}


