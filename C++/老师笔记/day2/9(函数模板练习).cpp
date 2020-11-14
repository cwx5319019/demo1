
//--------函数模板-----
#include<iostream>
using namespace std;
template <typename U> //template <class T>

U _max(U a,U b){
    return (a>b) ? a:b;
}
int main(){
    string a = "hello";
    string b = "world";
    cout << "max(3,4) = "  << _max(3,4) << endl; 
    cout << "max(3.3f,4.4f) = "  << _max(3.3f,4.4f) << endl;
    cout << "max(3.3,4.4) = "  << _max(3.3,4.4) << endl;
    //cout << "max(\"hello\",\"hi\") = "  << _max("hello","hella") << endl;
    //注意：上面字符串直接比较不行，字符串比较要申请一个变量 
    cout << "max(a,b) = "  << _max(a,b) << endl;
    
    return 0;
}
