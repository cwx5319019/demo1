#include<iostream>
#include<string.h>
#include<stdlib.h>

//-------------------函数的重载---------------------
//objdump -t a.out  //查看指令   在汇编的时候把函数名已经更换为不同的了

/*
什么情况下函数重载？
    1.函数名相同，
    2.参数类型不同,
    3.参数个数不同，
    4.返回值相同
*/
/*
函数重载注意事项：
    1.函数返回值不同不算重载
    2.函数参数名不同不能重载
    3.参数个数不同可以重载
    4.函数体不同不能重载
  
*/

using namespace std;
int add(int a,int b){
    return a+b;
}
/*
//函数体不同不能重载情况
int add(int a,int b){
    cout << "hello" << endl;
    return a+b;
}
*/
/*
// 返回值不同 不能重载情况
double add(int a,int b){
    return a+b;
}
*/
//参数个数不同情况
int add(int a){
    return a+100;
}
float add(float a,float b){
    return a+b;
}
double add(double a,double b){
    return a+b;
}
string add(string a,string b){
    return a+b;
}

int main(int argc,char** argv){ 
    cout << "add(3,4) = "          << add(3,4)             << endl;
    cout << "add(3.3f,4.4f)= "     << add(3.3f,4.4f)       << endl; //注意：单精度浮点型要加f
    cout << "add(3.3,4.4)= "       << add(3.3,4.4)         << endl; //默认是双精度浮点型
    cout << "add(hello,world) = "  << add("hello","world") << endl;
    return 0;    
}
