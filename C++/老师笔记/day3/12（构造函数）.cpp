
//构造函数

#include<iostream>
using namespace std;

class STU{
public:
//成员变量
    string m_strName;
    char m_cGender;
    int m_iAge;
    
//成员函数
    //构造函数，用于构造函数对象，函数名与类名相同
    STU(string Name ,char Gender,int Age ,float Score)//构造函数初始化  //初始化列表
        :m_strName(Name),m_cGender(Gender),m_iAge(Age),m_fScore(Score)//这个就是初始化列表作用  类似 int a = 0；
    { 
        /*
        m_strName = Name;     //这个相当与赋值 类似 a = 100；
        m_cGender = Gender;
        m_iAge    = Age;
        m_fScore  = Score;  
        */
    }
    void setStu(string Name = "xxx",char Gender = 'x',int Age = 0,float Score = 100){
        m_strName = Name;
        m_cGender = Gender;
        m_iAge    = Age;
        m_fScore  = Score;      
    }
    void printStu(){
        cout << "name = "  << m_strName  << endl
             << "gender = " << m_cGender << endl
             << "age = "   << m_iAge     << endl
             << "score = " << m_fScore   << endl;
    }
private:
    float m_fScore;
    //注意：私有成员类外不能访问，类里可以访问。
};
int main(void){
    //类
    STU stu("jack",'M', 20,100);
    stu.printStu();
    //stu.setStu("Jack",'M');
    //stu.printStu();  
    return 0;
}
