#if 0
1. (本题3分)
定一个正方形square，边长为私有，有构造函数，有个成员函数double area();还有个void copy(square s)；
要求：
1:在main函数中，定义两个对象，s1(3),s2(5)
2:通过copy函数，把s2拷贝给s1，并打印s1前后的面积
3:在copy函数中使用this指针实现，并能判断是否是拷贝对象本身，如果是本身则直接返回，不进行拷贝动作。
4:area函数负责计算并输出面积  
#endif
#include<iostream>
using namespace std;
class square{
public:
    square(int a = 0):a(a){}
    ~square(){}
    double area()
    {
        return a*a;
    }
    void copy(square s)
    {
        if(this->a == s.a){
            cout << "拷贝本身无效！" << endl;
        }else{ 
           this -> a = s.a; 
        }
    }
private:
    int a;
};
int main(void){
    square s1(3),s2(5);
    cout << "copy 前：" <<s1.area() << endl;
    s1.copy(s2);
    cout << "copy 后：" <<s1.area() << endl;
    return 0;
}
    










