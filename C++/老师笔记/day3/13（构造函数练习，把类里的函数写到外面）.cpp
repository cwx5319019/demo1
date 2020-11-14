
//构造函数练习   
//定义女孩类  输出信息，得到电话，修改电话

#include<iostream>
using namespace std;

class GIRL{
public:
    //成员函数是提供给用户的接口
    //构造函数，没有返回值，函数名与类名相同
    GIRL(string Name ,int Age ,string Phone);
    /*
        :m_strName(Name),m_iAge(Age),m_strPhone(Phone)
    { 
         
    }
    */
    void getPhone();
    /*
    {
        cout << "电话："<< m_strPhone << endl;  
    }
    */
    void updatePhone(string Phone);
    /*
    {
        m_strPhone  = Phone;   
    }
    */
    //如果函数仅仅是访问类成员，一般设置为常量成员函数
    //它的函数体拿到外面的话，需要再这里声明
    void showInfo() const;
    
    /*
    {
        cout << "name = "  << m_strName  << endl
             << "age = "   << m_iAge     << endl
             << "phone = " << m_strPhone << endl;
    }
    */
    
private:
    string m_strName;
    int m_iAge;
    string m_strPhone;

};

//------------因为类里函数太多，不容易看明白，所以用以下方法写到外面------------
GIRL::GIRL(string Name ,int Age ,string Phone)
    :m_strName(Name),m_iAge(Age),m_strPhone(Phone)
{ 
     
}
void GIRL::showInfo() const
{
    cout << "name = "  << m_strName  << endl
         << "age = "   << m_iAge     << endl
         << "phone = " << m_strPhone << endl;
}
void GIRL::getPhone()
{
    cout << "电话："<< m_strPhone << endl;  
}
void GIRL::updatePhone(string Phone)
{
    m_strPhone  = Phone;   
}


int main(void){
    GIRL girl("rose", 20,"111111111111");//它会自动调用构造函数，赋值
    girl.showInfo();
    girl.updatePhone("22222222222");
    girl.getPhone();
                
    return 0;
}
