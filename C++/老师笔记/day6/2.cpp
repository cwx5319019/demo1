#if 0
设计一个员工类，拥有属性：姓名、职位，重载运算符“!=”，比较两个员工的岗位及姓名是否一致，
测试输出。【3分：类的设计1分，运算符重载1分，整体+规范1分】
#endif

#include<iostream>
using namespace std;

class Employee{
public:
    Employee(const string n = "xxx",const string pos = "xxx");
    Employee(const Employee& other);
    bool operator!=(const Employee& other);
    void print();
    ~Employee();
private:
    string name;
    string position;
};
Employee::Employee(const string n,const string pos)
    :name(n),position(pos)
{
    //cout << "员工被构造" << endl;
}
Employee::Employee(const Employee& other)
{
    if((name == other.name)&& (position == other.position))return;
    name = other.name;
    position = other.position;
    cout << "拷贝成功" << endl;
}
bool Employee::operator!=(const Employee& other){
    if((name == other.name)&&(position == other.position)){
         return true;
    }else{
        return false;
    }

}
void Employee::print(){
    cout << "name:" <<name << endl
         << "position:" << position << endl;
}
Employee::~Employee(){
    //out << "员工被析构" << endl;
}           
int main(void){
    Employee E1("张三","teacher"),E2("李四","docter");
    E1.print();
    E2.print();
    int a = E1.operator !=(E2);
    if(a == true){
        cout << "姓名和岗位匹配" << endl;
    }else{
        cout << "姓名和岗位不匹配" << endl;
    }
    return 0;
}

