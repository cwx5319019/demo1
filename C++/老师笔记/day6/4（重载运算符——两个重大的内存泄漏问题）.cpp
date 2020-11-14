#if 0
在MyString类的基础上完成一下功能:
重载运算符：+、+=、=、[]、>、<、>=、<=、==
class MyString{
private:
char *m_data;
public:
MyString(const char *str = 0);
MyString(const MyString& rhs);
~MyString();
};
#endif 
#include<iostream>
#include<string.h>
using namespace std;

class myString{
public:
    myString(const char *str );
    myString(const myString& rhs);
    myString operator+(const myString& other);
    //myString operator+=(const myString& other);
    //myString operator=(const myString& other);
    
    //bool operator==(const myString& other);
    char* getp(){
        return m_data;
    }
    void print();
    ~myString();
private:
    char* m_data;
};
myString::myString(const char*str = 0  )
    //:m_data(NULL)
{
    if(str == NULL){
        m_data = new char[1];
    }else{
        m_data = new char[strlen(str)+1];
        strcpy(m_data,str);
    }
    cout << "被构建了" << endl;
}
myString::myString(const myString& rhs){
    //if(m_data == rhs.m_data )return; 
    //Conditional jump or move depends on uninitialised value(s)这个问题的源头
    
    m_data = new char[strlen(rhs.m_data)+1];
    strcpy(m_data,rhs.m_data);
    cout << "拷贝成功" << endl;
    
}
myString myString::operator+(const myString& other){
    
    int len = strlen(m_data) + strlen(other.m_data)+1;  //str1 str2 
    char* p = new char[len];
    strcpy(p,m_data);
    strcat(p,other.m_data);  
    delete []m_data;
    this ->m_data = p;
    cout << "重载成功" << endl;
    return *this; 
}
/*
myString myString::operator+=(const myString& other){
    char* p = new char[strlen(m_data) + strlen(other.m_data)+1];
    strcpy(p,m_data);
    strcat(p,other.m_data);
    delete []m_data;
    this -> m_data = p ;
    return *this; 
}
myString myString::operator=(const myString& other){
    delete []m_data;
    this->m_data = new char[strlen(other.m_data)+1];
    strcpy(m_data,other.m_data);
    return *this;
}

bool myString::operator==(const myString& other){
    if( strcmp(m_data,other.m_data)==0){
        return true;
    }else{
        return false;
    }
}
*/
void myString::print(){
    cout << m_data << endl;
}
myString::~myString(){
    cout << "被析构" << endl;
    delete []m_data;   
}
int main(void){
    myString str1("hello,"),str2("iotek");
    myString str3;
    str1+str2;
    //str3 = str1+str2;     //Invalid free() / delete / delete[] / realloc() 这个问题的源头
    //赋值之后 str3的指针指向str1+str2的和的temp的m_data的指针的指向，也就是说两个指针指向了一个地方，
        //按道理str3的指针应该指向自己申请的空间，赋值之后就变了，所以不能赋值只能 str1+str2
    
    //(str1+str2).print();
    //str1 += str2;
    //cout << "----------" << endl;
    //str1.print();
    
    return 0;
}

