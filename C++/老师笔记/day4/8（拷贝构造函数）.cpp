#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class mystring{
public:
    mystring(const int data ):p(data)
    {
        
        cout << "mystring(构造了)...." << endl;
    }
    int data()
    {
        return p;
    }
#if 0
 注意：在不使用 new （自己申请的栈空间）的情况下，系统会自动调用拷贝函数，
      来中和多次析构的情况

#endif   
    //拷贝构造函数  
    /*
    mystring( const mystring &other){
        strcpy(this -> p ,other.p);
        cout << "mystring(拷贝构造了)....." << endl;
    }
    */
    ~mystring()
    {
        
        cout << "mystring(析构了)...." << endl;
    }
private:
    int p;
};


int main(void){
    mystring str(100); //这是构造函数
    cout << str.data() << endl;
    mystring str1 = str; //这是赋值，类比7.c doouble free
    cout << str1.data() << endl;
    mystring str3 = str;
    cout << str3.data() << endl;
    
    return 0;
}
