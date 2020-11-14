#if 0
自定义类表示汽车（Car）。
要求：
1、有成员属性brand（品牌，string），weight（重量，整型）。
2、将brand，weight设为私有属性，并提供公开的get，set函数。
3、有合理的构造函数。
#endif

#include <iostream>
using namespace std;

class Car{
public:
    Car(string brand,int weight);
    ~Car();
    void set();
    void get();
private:
    string m_strBrand;
    int m_iWeight;
};
Car::Car(string brand,int weight)
    :m_strBrand(brand),m_iWeight(weight)
{
    cout << m_strBrand <<" 被生成！" << endl;
}
Car::~Car()
{  
    cout << m_strBrand <<" 被销毁！" << endl;
}
void Car::set(){
    cout << "请设置车属性：";
    cin >> m_strBrand >> m_iWeight;
}
void Car::get(){  
    cout << "车属性: "  << endl 
         <<"brand:  "  << m_strBrand << endl
         << "weight: " << m_iWeight  << endl;
}

int main(void){
    Car car("BMW",100);
    car.get();
    car.set();
    car.get();
    
    return 0;
}










