#include <iostream>
#include <math.h>
using namespace std;
class Point
{   
    public:
        Point(int x = 0,int y = 0)
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
        Point startPoint;  //定义了两个Point的类
        Point endPoint;
};

int main()
{
    Point p1(0,0),p2(3,4);
    Line l1(p1,p2);
    Point p3(1,1),p4(3,4);
    l1.setPoint(p3,p4);
    cout << "l1的长度 = " << l1.len() << endl;
    
    return 0;
}




