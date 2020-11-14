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
    //前++ operator++()
    Complex &operator++()  
    //operator++() 这样也可以，只不过会调用拷贝构造函数
    //this地址是对象地址，从外面传进来的，所以返回引用
    //
    {
        this ->real ++;       //先赋值  
        this ->img ++ ;
        return *this;   
        //----------------------所谓this 就是Complex* this 指着 c3，c3是Complex他是有空间的，所以对this操作是可以的，返回*this就是Complex类型------------
        
    }
    //后++ operator++(int)
    Complex operator++(int)
    //因为返回值是局部对象，所以返回值不能用引用
    //不能返回引用，因为是局部变量，函数调用，空间释放
    //Complex &operator++() 因为返回的局部变量指针，所以返回值不能引用
    {
        Complex tmp = *this;
        // 备份原值  //先返回结果 //-----------------先把c3保存，每次传值系统都会有一个this指针指向对象-------------------
        this ->real++;
        this ->img ++ ;
        return tmp;
        // 这里不能返回引用，（相当与给强转成指针了，返回一个局部指针是错误的）
    }
    //重载+号运算符
    Complex operator+(const Complex & other){
        Complex tmp ;
        tmp.real = this ->real + other.real;
        tmp.img = this -> img + other.img;
        return tmp;
    
    }
    //重载-号运算符
    Complex operator-(const Complex & other){
        Complex tmp ;
        tmp.real = this ->real - other.real;
        tmp.img = this -> img - other.img;
        return tmp;
    
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
    c3 = c1 + c2;
    c4 = c1 - c2;
    c3.print();
    c4.print();
    ++c3;
    c3.print();
    c3++;
    c3.print();
    return 0;

}
