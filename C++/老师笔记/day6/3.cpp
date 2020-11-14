#if 0
设置立方体的类，拥有属性长、宽、高；重载运算符“<”符号，比较两个立方体的体积大小。
【3分:类的设计1分，运算符的重载1分，整体测试+规范1分】
#endif 


#include<iostream>
using namespace std;

class cube{
public:
    cube(const int a = 0,const int b = 0  ,const int c = 0);
    int volume();
    bool operator < (const cube& other);
    void print()const;
    ~cube();
    
private:
    int a,b,c;

};
cube::cube(const int a,const int b ,const int c)
    :a(a),b(b),c(c)
{
    cout << "立方体被构造" << endl;
}
int cube::volume(){
    return a*b*c;
}
bool cube::operator < (const cube& other){
    if(a*b*c < other.a*other.b*other.c){
        return true;
    }else{
        return false;
    }
}
void cube::print() const
{
    cout  << a << "," << b << ","  << c << endl;
}
cube::~cube(){
    cout << "立方体被析构" << endl;
}
int main(void){
    cube c1(1,1,1),c2(2,2,2);
    cout << "C1的长宽高分别为：" ;
    c1.print();
    cout << "C2的长宽高分别为：" ;
    c2.print();
    int a = c1.operator <(c2);
    if(a == true){
        cout << "c2体积大" << endl;
    }else{
        cout << "c1体积大" << endl;
    }
    return 0;
}
          
