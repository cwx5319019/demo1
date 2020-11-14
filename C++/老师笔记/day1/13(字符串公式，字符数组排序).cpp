
//字符串的几个用法
//注意：字符串不能做减法

#include<iostream>
using namespace std;

int main(int argc,char** argv){
    //字符串相加
    string str1 = "hello";
    str1 = str1 + ',' + "world";
    
    //字符串做加法必须建立在变量的基础上,所以下面的是错误的
    //string str2 = "hello" + "world";
    
    string str3 = "";
    str3 = str3 + "hello";
    
    //字符串比较 ==  ！=  >  <
    string str4 = "hello";
    string str5 = "gello";
    if(str4 > str5){
        cout << "****" <<endl;
    }else{
        cout << "####" << endl;
    }
    
    string str6[5] = {"mi","apple","oppo","vivo","huwei"};
    int i = 0,j = 0;
    string temp;
    for(j = 0;j<4;j++){
        for(i=0;i<4-j;i++){
            if(str6[i] < str6[i+1]){
                temp = str6[i];
                str6[i] = str6[i+1];
                str6[i+1] = temp;
            }
        }
    }
    for(i = 0;i< 5;i++){
        cout << str6[i] << "  ";
    }
    
    cout <<  endl;
    return 0;
}


