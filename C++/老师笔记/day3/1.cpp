//编写一个函数有三个整形参数，其中带有两个默认参数值的参数，计算三个参数的和并输出。
//在主函数中多次调用函数，分别传递一个参数，两个参数，三个参数。

#include<iostream>
using namespace std;
int add(int a,int b = 2,int c = 3){
    return a +b +c;
}

int main(int argc, char** argv){
    cout << add(1) << endl;  //6
    cout << add(1,10) << endl; //14
    cout << add(1,10,100) << endl; //111
    return 0;
}
