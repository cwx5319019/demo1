//对于传值  正常就是把实参拷贝给形参
//指针传值  实参放&地址，形参指针*接收，这个改变是彻底的
//引用&    实参传递正常值  形参引用&  编译器编译的时候会把实参翻译成&取地址 


#include<iostream>
using namespace std;
class Complex{
public:
    Complex(const int r = 0 , const int i = 0)
        :real(r),img(i)
    {
        cout << "构造了 (" << real << "," << img << "i)" << endl;
        
    }
    Complex(const Complex& other){
        if((other.real == real)&&(other.img == img ))return ;
        real = other.real;
        img = other.img;
        cout << "拷贝构造了 (" << real << ',' << img << "i)" << endl;
        
    }
    //重载+号运算符
    Complex operator+(const Complex& other){      //必须明确this指针指向对象   显示调用c1.operator+(c2)
        Complex tmp ;
        tmp.real = this ->real + other.real;
        tmp.img = this -> img + other.img;
        return tmp;
    }
    //重载-号运算符
    Complex operator-(const Complex& other){
        Complex tmp ;
        tmp.real = this ->real - other.real;
        tmp.img = this -> img - other.img;
        return tmp;
    
    }
    //前++ operator++()
    Complex &operator++()
    {
        this ->real ++;     
        this ->img ++ ;
        return *this;
    }
    //后++ operator++(int)
    Complex operator++(int)
    {
        Complex tmp = *this; 
        this ->real ++;
        this ->img ++ ;
        return tmp;
    }
    // 重载运算符 == 
    bool operator==(const Complex& other)
    {
        
        if((this ->real == other.real) && (this ->img == other.img)){
            return 1;
        }else{
            return 0;
        } 
    }
    
    void print() const
    {
        cout << "(" << real << "," << img << "i)" <<endl;
    }
private:
    int real,img;
};
int main(void){
    Complex c1(1,1),c2(2,2);
    Complex c3,c4;
    cout << "-------重载+号运算符----------" << endl;
    c3 = c1 + c2;
    c3.print();
    cout << "-------重载-号运算符----------" << endl;
    c4 = c1 - c2;
    c4.print();
    cout << "-------前++ operator++()------" << endl;
    ++c3;
    c3.print();
    cout << "-------前++ operator++()-------" << endl;
    c3.operator ++();
    c3.print();
    cout << "--------后++ operator++(int)---------" << endl;
    c3++;
    c3.print();
    
    cout << "-------重载运算符 == -------" << endl;
    int x = c1 == c2;                   //c1.operator ==(c2) 显示调用
    cout << "bool:" <<x <<endl;
    
    return 0;
}
