//利用c++中的格式输出setw，setfill函数实现（同时实现右对齐）

//setw(int n )

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc,char** argv){
    int a = 1,i = 0;
    for(i= 1;i<6;i++){
        cout //<< setiosflags(ios::left)  //默认右边对齐 此函数设置左对齐
             << left                      //此函数设置左对齐，简单
             << setw(i)                   //设置宽度
             << a
             << setfill('0')              //空的用字符填充
             << endl;
    } 
    return 0;
}











