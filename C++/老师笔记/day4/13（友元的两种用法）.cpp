
#if 0
友元函数的用法，被/**/注释掉的是一种方法，  另外一种是 别的类的成员做 本类的友元函数

#endif



#include<iostream>
using namespace std;
class Time;
class Date{
public:
    Date(int year = 1970 ,int month = 1 , int day = 1)
        :year(year),month(month),day(day)
    {
        cout << "日期被构造了" << endl;
    }
    //******************本类成员****************
    void print(Time t);
    
/*
    //————————————————类外的函数做友元——————————————————————
    friend void print(Date d,Time t);
*/
    
private:
    int year,month,day;
};


class Time{
public:
    Time(int hour = 0,int minute = 0 ,int second = 0)
       :hour(hour),minute(minute),second(second)
    {
        cout << "时间被构造了"  << endl;
    }
    
    //*************别的类的成员做本类的友元函数****************
    friend void Date::print(Time t);
    
/*  
    //——————————————————类外的函数做友元————————————————————
    friend void print(Date d,Time t);
*/  
    
private:
    int hour,minute,second;
};

//*************************属于Date的成员函数*******************************
void Date::print(Time t)
{
    cout << "现在日期：" << year <<"-"<< month <<"-" << day <<endl;
    cout << "现在时间：" << t.hour <<":"<< t.minute <<":"<< t.second <<endl;
}


/*
//——————————————————————把这个函数写到上面的类里面当成友元函数——————————————————————
void print(Date d,Time t)
{
    cout << "现在日期：" << d.year <<"-"<< d.month <<"-" << d.day <<endl;
    cout << "现在时间：" << t.hour <<":"<< t.minute <<":"<< t.second <<endl;
}
*/

int main(void){
    
    /*
    //————————————注意调用——————————————
    Date today(2019,1,10);
    Time time(17,19,19);
    print(today,time);
    */
    
    //********注意成员函数调用***********
    Date today(2019,1,10);
    Time time(17,19,19);
    today.print(time);
    
    return 0;
}
