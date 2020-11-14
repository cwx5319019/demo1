#if 0
5. (本题3分)建立一个对象数组，内放n(<10)个学生的数据(学号、成绩)，
设立一个函数max，用指向对象的指针作函数参数，在max函数中找出n个学生中成绩最高者，并输出其学号。
#endif
#include<iostream>
#include<iomanip>
using namespace std;
class STU{
public:
    STU(int xh = 0000,double score = 0.0)
        :xh(xh),score(score)
    {}
    int getxh(){
        return xh;
    }
    double getScore(){
        return score;
    }
private:
    int xh;
    double score;
    
};
/*
void my_max(STU* stu1,int n){                   
    int i = 0 , pos = 0;          
    for(i = 0;i<3;i++){            
        if(stu1[pos].getScore() < stu1[i].getScore()){
            pos = i;
        }
    }
    cout << "最高分数的学生学号："  << stu1[pos].getxh() << endl;
} 
*/

//指针偏移
void my_max(STU* stu1,int n){                   
    int i = 0 ;
    STU* pos = stu1;          
    for(i = 0;i<3;i++){            
        if(stu1->getScore() < pos->getScore()){
            stu1 = pos ;
        }
        pos ++;
    }
    cout << "最高分数的学生学号："  << stu1->getxh() << endl;
} 

int main(void){
    STU stu[3] = {STU(1000,100.0),STU(1200,300.0),STU(1300,200.0)};
    my_max(stu,3);
    
    
    return 0;
}
