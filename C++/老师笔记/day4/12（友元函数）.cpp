
//友元函数：当类外函数需要访问该类的私有变量的时候
//可以把此函数作为本类的友元函数，在类中声明
//友元函数不能加类作用域  如：Complex::  注：友元函数只是朋友不是它的成员
#include<iostream>
using namespace std;
class Complex{
public:
    Complex(double x = 0 , double y = 0):real(x),img(y){
        cout << "构造了（" << "," << img << "i)" << endl; 
    }
    void printCom(){
        cout << "real = " << real << "," << "img"  << img << endl;
    }
    ~Complex()
    {
        cout << "析构了（" << real << "," << img << "i)" << endl;
    }
    
    //友元函数
    friend Complex add(Complex &c1,Complex &c2);
    

private:
    double real;
    double img;
      
};


Complex add(Complex &c1,Complex &c2){
    Complex com;            //这里调用了 1 次构造函数
    com.real = c1.real + c2.real;
    com.img = c1.img + c2.img;
    return com;
}

int main(void){
    Complex c1(1,1),c2(2,2); //这里调用了 2 次构造函数
    cout << "--------------" << endl;
    Complex c3;              //这里调用了 1 次 构造函数
    cout << "===============" << endl;
    c3 = add(c1,c2);
    c3.printCom();
    
    
    return 0;
}
