//友元类

#include<iostream>
using namespace std;
class girl;
class boy{
public:
                                                                      //注意：const 的添加
    //boy(string name = "jack",int age = 20,double salary = 1000.0)
    boy(const string name = "jack",const int age = 20,const double salary = 1000.0)
        :name(name),age(age),salary(salary)
    {
        cout << "boy 被构造了" << endl;
    }
    void myInfo()const
    {
        cout << "name :" << name << endl
             << "age :" << age << endl
             << "salary :" << salary <<endl;   
    }
    void myGirlinfo(girl &g1) ;                                     //注意：这里的把女孩的类传递进来
    //下面的定义放这里就不对了，因为它的本质是定义，定义不可以放在前面，可以提前声明；
    /*{
        cout << "name :" << g1.name << endl                        //不可以 girl::name  girl是所有女孩的一个类不是具体某个人
             << "age :" << g1.age << endl
             << "salary :" << g1.salary <<endl
             << "tel :"  << g1.tel << endl;
     } */
    boy(const boy& other){
        if(name == other.name ){return ;}
        name = other.name;
        age = other.age;
        salary = other.salary;
        cout << "boy 被拷贝了" << endl;
    }
    ~boy(){
        cout << "boy 被析构了" << endl;
    }
private:
    string name;
    int age ;
    double salary;
    
};

/*
//注意：放这里也不对 
void boy::myGirlinfo(girl &g1)                                      //注意：这里的把女孩的类传递进来
{
    cout << "name :" << g1.name << endl                        //不可以 girl::name  girl是所有女孩的一个类不是具体某个人
         << "age :" << g1.age << endl
         << "salary :" << g1.salary <<endl
         << "tel :"  << g1.tel << endl;
}
*/

class girl{
public:
                                                           //也要添加const
    girl(const string name = "rose",const int age = 19,const double salary = 1500.0,const string tel = "0123456890")
        :name(name),age(age),salary(salary),tel(tel)
    {
        cout << "girl 被构造了" << endl;
    }
    girl(const girl& other){
        if(name == other.name ){return ;}                    //注意:做一个判断看看是不是自己
        name = other.name;
        age = other.age;
        salary = other.salary;
        tel = other.tel;
        cout << "girl 被拷贝了" << endl;
    }
    ~girl(){
        cout << "girl 被析构了" << endl;
    }
    friend class boy;                                         //友元类
private:
    string name;
    int age ;
    double salary;
    string tel;
};

//注意：如果这个函数只能放在两个类的最后面  
void boy::myGirlinfo(girl &g1)                                      //注意：这里的把女孩的类传递进来
{
    cout << "name :" << g1.name << endl                        //不可以 girl::name  girl是所有女孩的一个类不是具体某个人
         << "age :" << g1.age << endl
         << "salary :" << g1.salary <<endl
         << "tel :"  << g1.tel << endl;
}


int main(void){
    boy b1("jack",20,1000.0);
    boy b2 = b1;
    girl g1("rose",19,1500,"18234945064");
    b1.myInfo();
    cout << "---------我女朋友的信息----------" << endl;
    b1.myGirlinfo(g1);
    
    return 0;
}
