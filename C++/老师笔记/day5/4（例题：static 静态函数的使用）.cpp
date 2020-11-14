#if 0
4. (本题3分)
练习：定义一个员工类Employee
要求：1，有工行，名字，员工总人数（static）
      2，构造函数
      3，输出函数print，输出工号，姓名
      4，静态成员函数void count();负责输出总人数；
      5，在main函数中定义3个员工，每构造一个对象，打印姓名和工号，总人数。
#endif
#include<iostream>
using namespace std;
class Employee{  
public:
    Employee(int gh = 000000,string name = "xxx")
        :gh(gh),name(name)
    {
          total = total +1;
    }
    void print()const
    {
        cout << "工号：" << gh << endl
             << "姓名：" << name << endl;
    }
    static void count() 
    //加上static后的效果就是 没了this指针  在静态函数里面只能访问static声明的变量 不可以访问别的变量
    //在非静态函数里可以放问静态函数
    {
       cout << "总人数：" << total << endl; 
    }    
private:
    int gh;
    string name;
    static int total; 
};
int Employee::total ;
//static 成员变量必须在类外定义，不能定义在某个域内，它不属于对象，，，什么叫做对象？Employee E1   E1就叫对象
//static 变量可以声明在类内，函数可以在类内定义

int main(void){
    Employee E1(190801,"Jack");
    E1.print();
    E1::count();
    //这样写也可以，因为static它属于类 
    Employee E2(190802,"Teddy");
    E2.print();
    E2.count();
    Employee E3(190803,"Davis");
    E3.print();
    E3.count();
    return 0;
}
                                              

                                              
