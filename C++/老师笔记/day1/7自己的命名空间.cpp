#include<iostream>
#include<string.h>
using namespace std;

//定义自己的命名空间

/*
思考:
如何修改命名空间里面的变量
把"namespace A"改为"good morning"，
把"namespace B"改为"good night"
*/

namespace A{
    char cName[] = "namespace A";
    void fun(){
        cout << cName << endl;  //不需要A::cName 因为他们都在A空间里
    }
}
namespace B{
    char cName[] = "namespace B";
    void fun(){
        cout << cName << endl;
    }
}

int main(int argc,char* argv[]){

    A::fun();
    B::fun();
    strcpy(A::cName,"good moring");   
    strcpy(B::cName,"good night");
    cout << A::cName << endl;
    cout << B::cName << endl;
    A::fun();
    B::fun();
    return 0;
}
