#if 0
设计一个学生类，要求该类有姓名、成绩、性别三个属性以及自我介绍的成员函数。
（要求必须要有构造函数、析构函数、成员姓名是char*类型存储在堆空间）

#endif 
                                       
#include<iostream>
#include<string.h>
using namespace std;

class STU{
public:
    STU(const char* Name,int Score,char Gender); 
    ~STU();
    void introduce();
private:
    char* m_chName;   
    int m_iScore;
    char m_chGender;

};
STU::STU(const char* Name,int Score,char Gender) 
    :m_iScore(Score),m_chGender(Gender)
    
{
    if(Name == NULL ){          //注意：Name不能写成 m_chName
        m_chName = new char[1];
    }else{
        m_chName = new char[100];
    }
    strcpy(m_chName,Name);
    cout << m_chName << " 被构造了！" <<  endl;
    
}

STU::~STU()
{
    cout << m_chName << " 被析构了！" <<  endl;
    delete []m_chName;
}

void STU::introduce()
{
    cout << "name :" << m_chName << endl
         << "score :" << m_iScore << endl
         << "gender :" << m_chGender << endl;
}

int main(void){
 // STU stu("jack",100,'M');
    STU *stu=new STU("rose",19,'F');
    stu->introduce();
    delete stu;
    return 0;
}
                                       
                                       
                                       

