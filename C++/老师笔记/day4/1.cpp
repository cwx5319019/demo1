
#if 0
自定义类表示点（Point）。

要求：

1、有成员属性x，y分别表示点的二维坐标值（整型即可）。

2、将x，y设为私有属性，并提供公开的get，set函数。

3、有合理的构造函数。

#endif
              

#include<iostream>
using namespace std;

class Point{
public:
    Point(int x ,int y);
    void set();
    void get() const ;
private:
    int m_iX;
    int m_iY;

};
Point::Point(int x ,int y)
    :m_iX(x),m_iY(y)
{
}
void Point::set(){
    int x,y;
    cout << "请输入坐标：" ;
    cin >> x >> y ;
    m_iX = x;
    m_iY = y;
}
void Point::get() const 
{
    cout << "你输入的坐标："<< "(" <<  m_iX << ',' << m_iY << ')' << endl;
}
int main(void){
    Point point(6,9);
    point.set();
    point.get();
    
    return 0;
}
              
              
              
