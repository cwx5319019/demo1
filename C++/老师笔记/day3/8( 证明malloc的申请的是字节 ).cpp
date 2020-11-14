#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main(){
    //用malloc申请100个字节，25个整型数
    int* p = (int*)malloc(100);//100是字节
    memset(p,0x12,100);//100是字节
    
    int i = 0;
    for(;i<100;i++){ 
        //打印100个int  即400字节  会发现前100个字节是被初始化了
        //前一百个字节被转化为25个整型数，打印出来应该是25个16进制整型数
        cout << "0x" << hex << *(p+i) << ",";
    }
    free(p);
    return 0;
}





