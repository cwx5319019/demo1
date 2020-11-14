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
    
    int geta()
    {
        return a ;
    }
private:
    //int a = 100;
    int a;
    
};

int main(void){
    //A a;
    A a= 100;
    A b = a;
    
    return 0;
}
