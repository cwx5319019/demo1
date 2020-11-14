
//--------函数模板-----
#include<iostream>
using namespace std;
template <typename U>
U add(U a,U b){
    return a+b;
}

int main(int argc,char** argv){
    
    cout << "add(3,4) = "  << add(3,4) << endl;
    cout << "add(3.3f,4.4f)= " << add(3.3f,4.4f) << endl; 
    cout << "add(3.3,4.4)= "  << add(3.3,4.4)   << endl; 
    
    //cout << "add("hello,","world") = " << add("hello,","world") << endl;
    //注意函数模板不能用于string
    
    return 0;
}
