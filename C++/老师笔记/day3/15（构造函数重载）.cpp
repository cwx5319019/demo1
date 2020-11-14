
//构造函数练习   
//定义女孩类  输出信息，得到电话，修改电话

#include<iostream>
using namespace std;
class GIRL{
public:
    
    
//---------------------构造函数重载声明-------------------------------
    
    
    GIRL(const string Name ,int Age ,const string Phone);
    GIRL(const string Name ,const string Phone);
    
//-----------------------------------------------------------------
    
    
    void getPhone();
    void updatePhone(string Phone);
    void showInfo() const;
    ~GIRL() //析构函数
    {
        cout << m_strName <<"被析构了！" << endl;
    }   
private:
    string m_strName;
    int m_iAge;
    string m_strPhone;
};


//---------------------构造函数重载-------------------------------


GIRL::GIRL(const string Name ,int Age ,const string Phone)
    :m_strName(Name),m_iAge(Age),m_strPhone(Phone)
{ 
     cout << Name<<"被构造了！" << endl;
}
GIRL::GIRL(const string Name ,const string Phone)
    :m_strName(Name),m_strPhone(Phone)
{ 
    cout << Name<<"被构造了!!！" << endl;
}

//---------------------------------------------------------------


void GIRL::showInfo() const
{
    cout << "name = "  << m_strName  << endl
         << "age = "   << m_iAge     << endl
         << "phone = " << m_strPhone << endl;
}
void GIRL::getPhone()
{
    cout << "phone："<< m_strPhone << endl;  
}
void GIRL::updatePhone(string Phone)
{
    m_strPhone  = Phone;
}
int main(void){
    GIRL girl("rose", 20,"111111111111");
    girl.showInfo();
    girl.updatePhone("22222222222");
    girl.getPhone();
    GIRL* pGirl = new GIRL("jack", 20,"111111111111"); 
    pGirl->showInfo();
    delete pGirl; 

    return 0;
}
