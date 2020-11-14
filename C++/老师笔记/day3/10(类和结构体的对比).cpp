#include<iostream>
using namespace std;

struct  sSTU{
//结构体是公开的，随时可以访问
    string chName;
    char cGender;
    int age;
};


class STU{
//在类里面成员函数默认是private私有的，不加public是不能访问的
public:
    string chName;
    char cGender;
    int age;
    void print(){
        cout << "name = " << chName << endl
             << "gender =" << cGender << endl
             << "age = "   << age <<endl;
    }
    
};

int main(void){
    
    STU stu;
    stu.chName = "jack";
    stu.cGender = 'M';
    stu.age = 23;
    stu.print();
 
    
#if 0
    cout << "空类的大小：" << sizeof(class STU) << endl;
    cout << "空结构体的大小：" << sizeof(struct sSTU) << endl;
    cout << "空结构体的大小：" << sizeof(sSTU) << endl;
    //注意：C语言中类的大小为 0 ，而且sizeof()里必须加 struct
    // C++里面的类和结构体大小都是 1 
#endif
    
    return 0;
}
