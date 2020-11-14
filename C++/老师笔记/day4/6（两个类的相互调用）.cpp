#include <iostream>
#include <math.h>
using namespace std;
class Point
{   
    public:
        //这里不加&也可以，系统会调用拷贝构造函数，把实参拷贝给形参，影响效率，加上&就是引用了，形参和实参进行绑定，不会去调用拷贝构造函数
        Point(int x = 0,int y = 0) 
        //Point startPoint; 这个情况不会调用析构函数，走默认的值，不会进入析构函数 
        //Point p1(0,0)     带值的话，它会覆盖掉原有的自己初始化的值，只有覆盖值，才会进入构造函数
            :x(x),y(y)
        {
            cout << "构造点(" << x << "," << y << ')' << endl;
        }
        void setxy(int x = 0,int y = 0)
        {
            this->x = x;
            this->y = y;
        }
        int getx()const
        {
            return x;
        }
        int gety()const
        {
            return y;
        }
    private:
        int x,y;

};


class Line
{
    public:
        Line(Point& start,Point& end):startPoint(start),endPoint(end)
        {
            //startPoint.setxy(start.getx(),start.gety());//构造线的开始坐标
            //endPoint.setxy(end.getx(),end.gety());//终止坐标
            cout << "构造线开始坐标(" << startPoint.getx() << ',' << startPoint.gety() << ")-----"
                 << "构造线终止坐标(" << endPoint.getx() << ',' << endPoint.gety() << ')' << endl; 
        }
        void setPoint(Point& start,Point& end)
        {
            startPoint.setxy(start.getx(),start.gety());
            endPoint.setxy(end.getx(),end.gety());
        }
        
        Point getPoint(string pos)const
        {
            if(pos == "start"){return startPoint;}
            if(pos == "end"){return endPoint;}
            cout << "start(" << startPoint.getx() << ',' << startPoint.gety() << ")-----"
                 << "end(" << endPoint.getx() << ',' << endPoint.gety() << ')' << endl;
        }
        
        double len()
        {
            int datax = pow(endPoint.getx()-startPoint.getx(),2);
            int datay = pow(endPoint.gety()-startPoint.gety(),2);
            return sqrt(datax+datay);
        }
        
    private:
        Point startPoint;  //这个情况不会调用析构函数，走默认的析构函数 如果带值的话，它会覆盖掉原有的自己初始化的值，然后进入构造函数
        Point endPoint;
};

//这里不加&也可以，系统会调用拷贝构造函数，把实参拷贝给形参，影响效率，加上&就是引用了，形参和实参进行绑定，不会去调用拷贝构造函数
void fun(Line& l1){
    cout << "l1的长度 = " << l1.len() << endl;
}

int main()
{
    Point p1(0,0),p2(3,4);
    Line l1(p1,p2);
    //cout << "l1的长度 = " << l1.len() << endl;
    fun(l1);
    
    return 0;
}




