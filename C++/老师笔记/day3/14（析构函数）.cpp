
//构造函数练习   
//定义女孩类  输出信息，得到电话，修改电话

#include<iostream>
using namespace std;
class GIRL{
public:

    GIRL(string Name ,int Age ,string Phone);
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
GIRL::GIRL(string Name ,int Age ,string Phone)
    :m_strName(Name),m_iAge(Age),m_strPhone(Phone)
{ 
     cout << Name<<"被构造了！" << endl;
}
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
    //cout << "修改成功！" << endl;
}

int main(void){
    GIRL girl("rose", 20,"111111111111");
    girl.showInfo();
    girl.updatePhone("22222222222");
    girl.getPhone();
    //创建new  类似 int* p = new int（100）
    GIRL* pGirl = new GIRL("jack", 20,"111111111111"); 
    pGirl->showInfo();
    delete pGirl; //可以注释掉本行找规律，注意这个按照栈原理，先构造后析构
    //new创建必须的手动删除，删除会去调用析构函数
    //类调用构造函数，结束会自动在调用析构函数
    
    return 0;
}
