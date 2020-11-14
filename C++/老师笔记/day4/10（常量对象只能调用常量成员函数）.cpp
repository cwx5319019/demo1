#include<iostream>
using namespace std;

class A{
public:
    
    A(int a):a(a)
    {
        cout << "构造..." << endl;
    }
    
    A(const A&other):a(other.a)
    {
        cout << "拷贝构造..." << endl;
    }
    //小知识点   //注意常量对象只能调用常量成员函数
    int geta()const
    {
        return a ;
    }
    int geta()
    {
        return a ;
    }
private:
    int a;
    
};

int main(void){
    const A a(100);  //注意常量对象只能调用常量成员函数
    cout << a.geta() <<endl;
    A b(100);  
    cout << b.geta() <<endl;
    
    return 0;
}
