
//字符串赋值

#include<iostream>
using namespace std;

typedef struct STU{
    //char chName[20];  //这样直接赋值是有问题的
    string chName;      //string 是C++的新的类型，不用strcpy，可以直接赋值
    float fScore;
    void showInfo(/*struct STU*  this*/){ 
        cout << this-> chName << "  " << this-> fScore <<endl; 
    }
}STU;

int main(int argv ,char* argc[]){
    STU jack = {"jack",99.9};
    jack.showInfo();
    STU rose = {"rose",88.8};
    rose.chName = "hello";
    rose.showInfo();
    
    return 0;
}
