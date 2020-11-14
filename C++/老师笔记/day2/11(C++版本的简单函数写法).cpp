
//把10.cpp代码进行改造

#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct STU{
    int no;  
    string name;
    char gender;
    float score;
    void show(){
        cout << no << "," << name << "," << gender << "," << score <<endl;
    }
    
    //C++ 函数自定义初始值  注意这里如果gender定义了初始值 score必须也得定义初始值
    void creatStu(string name = "xxx" ,char gender = 'x' ,float score = 100)
    {
        static int stu_no = 1000;
        no = stu_no;
        this->name = name;
        this->gender = gender;
        this->score  = score;
        stu_no++;
    } 
}stu_t;

int main(){
    
    stu_t* stu = new stu_t;
    if(stu == NULL){
        cerr << "calloc 失败..." << endl;
        return 0;
    }
    
    stu->creatStu();
    stu->show();
    
    return 0;
}
