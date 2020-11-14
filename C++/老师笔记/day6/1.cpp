#include<iostream>
using namespace std;

class date{
public:
    date(int year = 2019,int month = 1,int day = 30);
    date(const date& other);
    date operator-(const date& other);
    date& operator++();
    date operator++(int);
    date& operator--();
    void print();
    ~date();
    
private:
    int year,month,day;
};

date::date(int year,int month,int day)
    :year(year),month(month),day(day)
{
    //cout << "日期生成" << endl;
}
date::date(const date& other){
    if((year == other.year)&& (month == 
        other.month)&&(day == other.day ))return;
    year = other.year;
    month = other.month;
    day = other.day;
    //cout << "拷贝成功" << endl;
}
date date::operator-(const date& other){
    date temp ;
    temp.year = year - other.year;
    temp.month = month - other.month;
    temp.day = day - other.day;
    //cout << "运算成功"  << endl;
    return temp;
}
date& date::operator ++(){
    this ->day++;
    return *this;
}
date& date::operator --(){
    this ->day--;
    return *this;
}
void date::print(){
    cout << "日期：" << year 
         << "-" << month 
         << "-"  <<  day << endl;        
}
date::~date(){
    //cout << "日期被析构" << endl;
}
int main(void){
    date d1(2019,12,20),d2(2018,7,12),d3;
    d1.print();
    d2.print();
    cout << "日期相减结果" << endl;
    d3 = d1-d2;
    //d3 = d1.operator-(d2);
    d3.print();
    cout << "------自增------" << endl;
    ++d1;
    d1.print();
     cout << "------自减------" << endl;
    d2.operator --();
    d2.print();
    return 0;
}
