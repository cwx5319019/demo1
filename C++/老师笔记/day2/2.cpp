/*
定义一组枚举类型表示星期一到星期日，然后定义一个枚举数组变量，
成员为7个，初始化成星期一到星期日，然后输出他们的值。  
  
*/


//****************注意******************

//unoinsizeof大小是按照 最大的类型字节数来算
//enum 就是4个字节

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv){
  
    typedef enum Week {
        Mon = 1,
        Tue,
        Wed,
        Thu,
        Fri,
        Sat,
        Sun
    }week;
    
    int i = Mon;
    for(i=Mon;i<=Sun;i++){
        cout  << i << " ";
    }
    cout << endl;
    
    week w[7];
    w[0] = Mon;
    w[1] = Tue;
    w[2] = Wed;
    w[3] = Thu;
    w[4] = Fri;
    w[5] = Sat;
    w[6] = Sun;

    for(i= 0;i<7;i++){
        cout << w[i]<< endl;
    }
    
    return 0;
}




