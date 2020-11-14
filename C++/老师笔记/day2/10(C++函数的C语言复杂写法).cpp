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
}stu_t;

//C++ 的默认初始化 
stu_t* creatStu(string name = "hello" ,char gender = 'f' ,float score = 100){
    
    stu_t* stu = new stu_t;
    if(stu == NULL){
        cerr << "calloc 失败..." << endl;
        return NULL;
    }
    static int no = 1000;
    stu->no = no;
    //strcpy(stu->name , name);
    stu->name = name;
    stu->gender = gender;
    stu->score = score;
    no++;
    return stu;
}


int main(){
    /*
    //第一种初始化
    stu_t stu = {10000,"jack",'M',90.9};
    stu.show();
    //第二种初始化
    stu.no = 20000;
    stu.name = "rose";
    stu.gender = 'F';
    stu.score = 80.9;
    stu.show();
    */
    //第三种初始化
    stu_t* stu1 = NULL ;
    stu1 = creatStu("tom");
    if(stu1 == NULL)return 0;
    stu1->show();
    
    return 0;
}
