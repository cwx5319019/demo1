#include<iostream>
using namespace std;

class date{
public:
    date(int year = 2019,int month = 1,int day = 30);
    date& operator++();
    date operator++(int);
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

date& date::operator ++(){
    this ->day++;
    cout << "前++ day:"<<this->day <<endl;
    return *this;
}
date date::operator ++(int){
    date temp = *this;
    cout << "后++ day:" << temp.day <<endl;
    this ->day++;
    return temp;
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
    cout << "------前++------" << endl;
    ++d1;
    d1.print();
    cout << "------后++------" << endl;
    d2++;
    d2.print();
    return 0;
}
