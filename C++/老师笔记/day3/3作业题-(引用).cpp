//写一个swap交换函数，交换两个整数的值（要求使用引用知识点）。

#include<iostream>
#include <utility>
using namespace std;
//指针实现
void _swap(int* a , int* b){      //C语言写法    传参的时候_swap(&a,&b);
    int c = *a;                   //把a保存
    *a = *b;
    *b = c;
}

//引用实现
void _swap(int& a , int& b){     //传参的时候_swap(a,b);
    int c(a);                    //把a保存
    a = b;
    b = c;
} 

//注意上面的两种函数名可以相同，系统会重载分别

int main(int argc,char** argv){
    
    int a = 10,b = 5;
    cout << "a = " << a << "   " << "b = " << b << endl; 
    _swap(a,b);
    //_swap(&a,&b);
    cout << "a = " << a << "   " << "b = " << b << endl;



    return 0;
}

