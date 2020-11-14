#include<iostream>
using namespace std;
int fun1(int& x)      //这样是错的没有const
{
    return x;
}
int fun2(const int& x) //对常量的引用
{
    return x;
}

int main(void){ 
#if 0
       const int a = 100;
       // int& ref = a;//这是不行的
       const int& ref = a;//这是可以
#endif  
#if 0
    //cout << fun1(100) << endl;  //注意：传的参数是常量，函数形参必须写const保护
    cout << fun2(100) << endl;
#endif 
#if 0 
    int  iData = 100;
    int* p = &iData;
    //对指针的引用
    int* (&ref) = p;
    cout << iData << "," << &iData <<endl;
    cout << *p << "," << p <<endl;
    cout << *ref << "," << ref <<endl;
#endif 
#if 0
    int arr[5] = {1,2,3,4,5};
    //对数组的引用
    int (&ref)[5] = arr;
    int i = 0;
    for(;i<sizeof(ref)/sizeof(int);i++){
        cout << ref[i] << ' ';
    }
    cout << endl;
#endif
    return 0;
}
