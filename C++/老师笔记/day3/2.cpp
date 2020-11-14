//使用函数重载，用于计算不同类型的两个数的平方和。
//可以参考函数声明： func(int,int); func(double,double)

#include<iostream>
using namespace std;

int fun(int a ,int b){
    return a*a + b*b;
}
double fun(double a,double b){
    return a*a + b*b; 
}

int main(int argc,char** argv){
    cout << "fun(3,3) = " << fun(3,3) << endl;
    cout << "fun(3.3,3.3) = " << fun(3.3,3.3) << endl;
    
    return 0;
}
