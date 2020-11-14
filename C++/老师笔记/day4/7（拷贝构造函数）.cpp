#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class mystring{
public:
    mystring(const char* data ):p(NULL)
    {
        if(data == NULL){
            p = new char[1];
        }else{
            p = new char[strlen(data)+1];
            strcpy(p,data);
        }
        cout << "mystring(构造了)...." << endl;
    }
    char* data()
    {
        return p;
    }
    
    //拷贝构造函数
    mystring( const mystring &other){
        this -> p = new char[strlen(other.p)+1];
        strcpy(this -> p ,other.p);
        cout << "mystring(拷贝构造了)....." << endl;
    }
    
    ~mystring()
    {
        delete []p;
        //delete []p;   //这样写是不对的，这是一次析构调用两次，它只能触动一次拷贝会出现错误
        cout << "mystring(析构了)...." << endl;
    }
private:
    char* p;
};


int main(void){
    mystring str("hello");
    cout << str.data() << endl;
    mystring str1 = str;
    cout << str1.data() << endl;
    mystring str3 = str;
    cout << str3.data() << endl;
    
    return 0;
}
