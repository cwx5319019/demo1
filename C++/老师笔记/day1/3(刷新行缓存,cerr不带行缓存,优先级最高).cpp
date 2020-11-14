#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    while(1){
        cerr << '*';          //不带行缓存
        cout << '.' << flush; //这是C++刷新行缓存的方式
        //fflush(stdout) ;    //这是C刷新行缓存的方式
        sleep(3);
    }
    return 0;   
}
