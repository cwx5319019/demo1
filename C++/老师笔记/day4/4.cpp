#if 0
自定义类表示线（Line）
要求：
1、有成员属性startPoint（起始点，Point），成员属性endPoint（终点，Point）。
2、将成员属性startPoint，endPoint设为私有属性，并提供公开的get，set函数。
3、有成员函数len用于计算线的长度 。
len的函数原型：
double Line：：len();
4、有合理的构造函数，必须在构造函数中初始化startPoint和endPoint。
#endif

#include<iostream>
using namespace std;
class Line{
public:
    Line(double startPoint ,double m_endPoint);
    ~Line();
    void get();
    void set();
    double len();
private:
    double m_startPoint;
    double m_endPoint;
};
Line::Line(double startPoint,double endPoint)
    :m_startPoint(startPoint),m_endPoint(endPoint)
{
    cout << "两点构成！" << endl;
}
Line::~Line()
{
    cout << "两点被销毁！" << endl;
}
void Line::set()
{
    cout << "请输入起点和终点：" ;
    cin >> m_startPoint >> m_endPoint ;
}
void Line::get()
{
    cout << "起点: " << m_startPoint << endl
         << "终点: " << m_endPoint << endl;         
}
double Line::len(){ 
    return m_endPoint - m_startPoint;
}
int main(void){
    double len ;
    Line* pLine = new Line(10.0,100.0);
    pLine -> get();
    cout << "线长: " <<  pLine -> len()  << endl;
    pLine -> set();
    pLine -> get() ;
    cout << "线长: " <<  pLine -> len()  << endl;
    delete pLine;  
    return 0;
}
