/*
定义一个无符号短整数变量shortsmall，
并赋值为shortsmall = 65535，++两次，每次++输出结果，并观察现象 
  
*/
#if 0
#include<iostream>
using namespace std;

int main(int argc,char** argv){
    unsigned short num = 65535;
    num++;
    cout << num << endl;
    num++;
    cout << num << endl;
    
    return 0;
}
#endif
/*
定义一个有符号短整数变量shortsmall，
并赋值为shortsmall = 32767，++两次，每次++输出结果，并观察现象。
*/

#include<iostream>
using namespace std;

int main(int argc,char** argv){
    short num = 32767;
    num++;
    cout << num << endl;
    num++;
    cout << num << endl;
    
    return 0;
}























