#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
typedef struct my_string{
    char *p ;
    
    int length(){
        return strlen(p);
    }
}my_str_t;

int main(int argc,char** argv){
    my_str_t str;   
    
    //**************************注意*****************************
    //这时候的str.p是没有空间存放字符串的，只是一个指针，所以申请一个堆空间。
    
    str.p = (char*)calloc(100,1); 
    
    //如果打印地址，按照下面的方法 (void*)p1
    cout << "str.p的地址：" << (void*)str.p << endl;
    
    strcpy(str.p,"hello");
    cout << str.length() <<endl;
    
    //得到某个字母 
    cout << "get'l':" << *(str.p + 2) << endl;
    
    free(str.p);

    
    return 0;    
}
