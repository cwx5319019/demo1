#include<iostream>
using namespace std;
typedef struct STU
{
    int ild;
    char caName[20];
    int iAge;
    float fScore;
}stu_t;

int main(int argc,char* argv[]){
    //数组输入
    int arr[5] = {0};
    cout << "请入5个数" << endl;
    int i = 0;
    for(i = 0;i<5;i++){
        cin >> arr[i] ;
    }
    for(i=0;i<5;i++){
        cout <<arr[i] << " ";
    }
    cout << endl;
    
    //结构体输入
    stu_t stu;
    cout <<"请输入学号，名字，年龄，分数" << endl;
    cin >> stu.ild >> stu.caName>> stu.iAge>> stu.fScore ;
    cout << "学号：" << stu.ild   << endl
         << "名字：" << stu.caName<< endl
         << "年龄：" << stu.iAge  << endl
         << "分数：" << stu.fScore<< endl;
    
    return 0;   
}
//






