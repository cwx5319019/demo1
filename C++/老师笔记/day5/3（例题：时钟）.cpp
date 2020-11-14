#if 0
3. (本题4分)
设计一个时钟类，实现时钟的运行。
数据包含：时，分，秒；
成员函数：
（1）      构造函数：初始化起始时间；
（2）      显示函数：显示时间，并实现刷新；
（3）      计时函数：实现计时功能；
（4）      时钟运行函数：循环调用显示和计时函数，实现时钟运行。
#endif
#include<iostream>
#include<unistd.h>
#include<signal.h>
using namespace std;
class Time{
public:
    Time(int h = 0 ,int min = 0,int sec = 0)
        :hour(h),minute(min),second(sec)
    {
        
    }
    void showTime()
    {
        
        cout << "当前时间：" ;
        if(hour < 10){ cout<< '0' << hour << ":"<< flush;}
        else{ cout << hour << ":";}
        if(minute < 10){ cout<< '0' << minute << ":"<< flush;}
        else{ cout << minute << ":";}
        if(second < 10){ cout<< '0' << second << ":" << endl;}
        else{ cout << second << ":" << endl;}
             
    }
    void timer(){
        if(++second < 60){
        }else{
            minute++;
            second = 0;
            if(minute >= 60 ){
                hour++;
                minute = 0;
                if(hour >= 24){
                    hour = 0;
                }
            }
        }
    }
    void running(){
        while(1){
            timer();
            showTime();
            sleep(1);
        }
    }
private:
    int hour,minute,second;
};
int main(void){
    Time time(10,59,57);
    time.running();
    return 0;
}










