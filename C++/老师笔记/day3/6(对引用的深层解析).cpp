#include<iostream>
using namespace std;
int main(){
    int idata = 100;
    int *p = &idata; //p的地址 = idata的地址
    
    cout << "idata = " << idata << "," << "&idata = " << &idata << endl;
    cout << "*p= " << *p << "," << "p = " << p << endl;
    cout << "\n\n\n";
    
    //引用整型数据类型int&
    int& ref = idata;
    cout << "ref= " << ref << "," << "&ref = " << &ref << endl;
    //对引用的引用，只是有两个引用指向了idata，这个和二级指针要区别开
    int& ref2 = ref;
    cout << "ref2= " << ref2 << "," << "&ref2 = " << &ref2 << endl;
    cout << "\n\n\n";
    
    idata++;
    cout << "idata = " << idata << ",*p="  << *p << ",ref=" << ref  <<",ref2 " << ref2 << endl;
    (*p)++;
    cout << "idata = " << idata << ",*p="  << *p << ",ref=" << ref  <<",ref2 " << ref2 << endl;
    ref++;
    cout << "idata = " << idata << ",*p="  << *p << ",ref=" << ref  <<",ref2 " << ref2 << endl;
    ref2++;
    cout << "idata = " << idata << ",*p="  << *p << ",ref=" << ref  <<",ref2 " << ref2 << endl;
    
    
    return 0;
}
