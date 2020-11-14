//设计一个学生类，要求该类有姓名、成绩、性别三个属性以及自我介绍的成员函数

#include<iostream>
using namespace std;
typedef struct student 
{
    string name ;
    double score;
    char gender;
    void print(){
        cout << "name = " << name << endl
             << "score = " << score << endl
             << "gender = " << gender << endl;
    }
    void introduce(string name ,double score,char gender){
        this -> name = name;
        this -> score = score;
        this -> gender = gender;
    }
}stu_t;

int main(int argc, char** argv){
    stu_t* stu = new stu_t;
    stu -> introduce("Eilleen",100,'F') ;
    stu -> print();

    return 0;
}





