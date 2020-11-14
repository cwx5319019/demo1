//写一个swap交换函数，交换两个数的值（要求使用引用知识点）。

#include<iostream>
#include <utility>
using namespace std;

template <class U>
void _swap(U &a , U &b){    
    U c(a);                   
    a = b;
    b = c;
} 

int main(int argc,char** argv){
    int a = 10,b = 5;
    float c = 10.5 , d = 5.5;
    string str = "hello",ptr = "world";
    
    cout << "交换前" << endl;
    cout << "a = " << a << "   " << "b = " << b << endl; 
    cout << "c = " << c << "   " << "d = " << d << endl;
    cout << "str = " << str << "   " << "ptr = " << ptr << endl;
    _swap(a,b);
    _swap(c,d);
    _swap(str,ptr);
    cout << "交换后" << endl;
    cout << "a = " << a << "   " << "b = " << b << endl;
    cout << "c = " << c << "   " << "d = " << d << endl;
    cout << "str = " << str << "   " << "ptr = " << ptr << endl;
    return 0;
}

