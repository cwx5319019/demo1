

//先查版本号
//find /usr/include/* -name iostream
//c++ --version
//ls -al /usr/bin/c++

//查看源码
//vim /usr/include/c++/4.6(版本号)/bits/basic_string.h 

//搜索
//最下面  /+length  


#include<iostream>
#include<unistd.h>
using namespace std;

int main(int argc,char** argv){
    // （1）str1.length 与 str1.size() 查字符长度
    string str1 = "hello";
    cout << str1 << "  " << str1.length() << "  " << str1.size() << endl;
    
    // （2）"\0hello" 
    string str2 = "\0hello";
    cout << str2 << "  " 
         << str2.length() << "  " 
         << str2.size()   << "  "
         //注意：'\0'不是有效字符，所以输出的sizeof值是不准的
         << sizeof(str2)      
         << endl;
    
    // （3）str1.at(i) 打印 
    int i = 0;
    for(i = 0;i<str1.size();i++){
        //cout << str[i] <<flush;
        cout << str1.at(i) <<flush;
        //sleep(1);
    }
    cout << endl;
    
    //（4）reserve(size_type __res_arg = 0)
    string str3 = "12345";
    //没扩容之前先输出一下容量
    cout << str3.capacity() << endl; 
    //扩容之后在输出一下容量
    str3.reserve(100);
    cout << str3.capacity() << endl;
    
    
    //(5) empty()
    string str4 = "";
    cout << str4.empty() << endl;
    //空的话返回 1
    
    return 0;
}





