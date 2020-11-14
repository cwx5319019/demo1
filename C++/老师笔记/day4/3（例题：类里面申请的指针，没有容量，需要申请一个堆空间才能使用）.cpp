#if 0
设计一个学生类，要求该类有姓名、成绩、性别三个属性以及自我介绍的成员函数。
（要求必须要有构造函数、析构函数、成员姓名是char*类型存储在堆空间）

#endif 
                                       
#include<iostream>
#include<string.h>
using namespace std;

class STU{
public:
    STU(const char* Name,int Score,char Gender); //注意必须加const
    ~STU();
    void introduce();
private:
    char* m_chName;   
    //这里既然是指针就必须的申请一个空间，来存放数据
    int m_iScore;
    char m_chGender;

};
STU::STU(const char* Name,int Score,char Gender) 
    //char* Name 是没有空间的，初始化不能写
    :m_iScore(Score),m_chGender(Gender)
{
    //给指针申请一个空间
    if(m_chName == NULL ){
        m_chName = new char[1];
    }else{
        m_chName = new char[strlen(Name)];
    }
    //申请好空间后，进行赋值
    strcpy(m_chName,Name);
    
    cout << m_chName << " 被构造了！" <<  endl;
}
STU::~STU()
{
    cout << m_chName << " 被析构了！" <<  endl;
    delete m_chName;
}
void STU::introduce()
{
    cout << "name :" << m_chName << endl
         << "score :" << m_iScore << endl
         << "gender :" << m_chGender << endl;
}
int main(void){
    STU* p = new STU("jack",100,'M');
    p->introduce();
    delete p;
   
    return 0;
}
                                       
                                       
                                       
