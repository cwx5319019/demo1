#include<iostream>
using namespace std;
class STU{
public:
    string m_strName;
    char m_cGender;
    int m_iAge;
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
    
    STU stu;
    stu.setStu("Jack",'M');
    stu.printStu();  
    return 0;
}
