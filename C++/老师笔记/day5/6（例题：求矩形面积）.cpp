#if 0 
6. (本题4分)
自定义类表示矩形（Rectangle）
要求：
1、有成员属性LTpoint（左上角坐标，Point），RBpoint（右下角坐标，Point）
2、将成员属性LTpoint，RBpoint设为私有属性，并提供公开的get，set函数。
3、有成员函数area，能够计算矩形对象的面积（通过LTpoint和RBpoint获取矩形的长和宽）。
area的函数原型：
int Rectangle::area();
4、有合理的构造函数，必须在构造函数中初始化LTpoint和RBpoint。
#endif
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
class Point{
public:
    Point(int x ,int y)
        :x(x),y(y)
    {}
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    void setxy()
    {
        cin >> x >> y;
    }
private:
    int x,y;
};
class Rectangle{  
public:
    Rectangle(Point &LT,Point &RB)
        :LTpoint(LT),RBpoint(RB)
    {}
    void get()
    {
        cout << "左上角坐标：(" << LTpoint.getx() << ',' << LTpoint.gety() << ")" <<endl;
        cout << "右下角坐标：(" << RBpoint.getx() << ',' << RBpoint.gety() << ")" <<endl;
    }
    void setAuto()
    {
        cout << "请输入左上角坐标：";
        LTpoint.setxy();
        cout << "请输入右下角坐标：";
        RBpoint.setxy() ;
    }
    void area()
    {
        double a = abs(LTpoint.getx() - RBpoint.getx());
        double b = abs(LTpoint.gety() - RBpoint.gety());
        cout << "矩形的面积: " << a*b << endl;
    }
private:
    Point LTpoint;
    Point RBpoint;
};
int main(void){
    Point p1(0,0), p2(1,1);
    Rectangle R1(p1,p2);
    R1.setAuto();
    R1.get();
    R1.area();

    return 0;
}










