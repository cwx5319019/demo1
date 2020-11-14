#include<iostream>
#include<string.h>

void fun_arr(char buf[1024]){ 
    
    //buf[1024] 会退化为指针  结果是 5 4
    cout << buf <<"  " << strlen(buf) << "  " << sizeof(buf) << endl;
}

int main(){
    char arr1[] = "hello";
    //char arr2[5] = "hello";    //这个在C++里直接报错
    char arr3[5] = {'h','e','l','l','o'};
    char arr4[6] = "hello";
    char arr5[7] = "\0hello";
    char *p = "hello";
    
    cout << arr1 << "  " << strlen(arr1) << "  " << sizeof(arr1) << endl;
    //cout << arr2 << "  " << strlen(arr2) << "  " << sizeof(arr2) << endl;
    cout << arr3 << "  " << strlen(arr3) << "  " << sizeof(arr3) << endl;
    cout << arr4 << "  " << strlen(arr4) << "  " << sizeof(arr4) << endl;
    cout << arr5 << "  " << strlen(arr5) << "  " << sizeof(arr5) << endl;
    cout << p << "  " << strlen(p) << "  " << sizeof(p) << endl;
    char chbuf[1024] = "iotek";
    fun_arr(chbuf);
    return 0;
    
    //注意：'\0'是系统给数组的，所以strlen不能算上它，
    //     sizeof 计算的是数组开辟的大小，注意buf[]括号里有无数。
}
