#include<iostream>
using namespace std;

int main(void){
    //进制转化
    int a = 100;
    cout << "a的10进制 =" << a << endl;   //系统默认10进制
    cout << "a的10进制 =" << dec << a << endl;
    cout << "a的16进制 = 0x" << hex << a << endl;
    cout << "a的8进制 = 0"  << oct << a << endl;
    //注意：在这里改成8进制表达后，下面的整数表达方式都将会是8进制

    //ascii码转化
    //(char) 97 和 (int)'a' 是C语言的强转方式一样使用
    cout << "97打印成字符是 = " << char(97) << endl;  
    cout << "字符a的ascii码 = " << int('a') << endl; 
    
    //在这里又将8进制改回10进制表达
    cout << "a的10进制 =" << dec << a << endl;
    cout << "字符a的ascii码 = " << int('a') << endl;

    return 0;
}
