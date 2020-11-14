#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main(void){
#if 0
    //C操作内存
    int* p = (int*)malloc(100);
    memset(p,0x12,100);
    
    int i = 0;
    for(;i<25;i++){ 
        cout << "0x" << hex << *(p+i) << ",";
    }
    for(i = 0;i<25 ;i++){
         *(p+i) = 0x15;  
         
    }
    for(i = 0;i<25 ;i++){ 
         cout  << "0x" << hex << *(p+i) << "," ;
    }
    cout << endl;
    free(p);
#endif
#if 0
    // C++ 操作内存方式
    //注意申请的空间一定要够，要不段错误
    char* p = new char[100]; 
    char i = 0;
    for(i = 0 ; i< 10;i++){
        *(p+i) = '*';
    }
    for(i = 0 ; i< 100;i++){
        cout << "0x" << hex << *(p+i) << " ";
    }
    cout << endl;
    delete p;
    
#endif
#if 1
    char* chp = new char ;
    char* chp1 = new char[1];
    int* chp2 = new int(100);
    
    cout << "*chp2 = " << *chp2 <<endl
         << " chp2 = " << chp2 << endl;
 
    
    delete chp;    //单个释放
    delete []chp1; //数组释放
    delete chp2;
    

#endif
    
    return 0;
}





















