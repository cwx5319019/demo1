#include<stdio.h>

//注意：下面这种是C写法 不简洁，还的传参数
//对比C++ 8.cpp，C很复杂

typedef struct STU{
    char chName[20];
    float fScore;
    void (*showInfo)(struct STU* stu);
}STU;

void print(STU* stu){
    if(stu!= NULL){
        printf("%s      %f\n",stu->chName,stu->fScore);
    }
}

int main(int argv ,char* argc[]){
    STU jack = {"jack",99.9,print};
    jack.showInfo(&jack);
    STU rose = {"rose",88.8,print};
    rose.showInfo(&rose);
    
    return 0;
}



