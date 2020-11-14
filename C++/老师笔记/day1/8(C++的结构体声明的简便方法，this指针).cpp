#include<iostream>
using namespace std;

//对于传值  正常就是把实参拷贝给形参
//指针传值  实参放&地址，形参指针*接收，这个改变是彻底的
//引用&    实参传递正常值  形参引用&  编译器编译的时候会把实参翻译成&取地址 
//注意：下面这种是C++写法 把函数直接定义到结构体里面，简便，不用上面那种在

typedef struct STU{
    char chName[20];
    float fScore;
    void print(/*struct STU*  this*/){ 
        //this 是C++里面隐藏的一个指针，这个指针指向对象本身
        cout << this-> chName << "  " << this-> fScore <<endl; 
    }
}STU;

int main(int argv ,char* argc[]){
    STU jack = {"jack",99.9};
    jack.print();
    STU rose = {"rose",88.8};
    rose.showInfo();
    
    return 0;
}

//把这个做一下优化，就成了上面那个
#if 0
typedef struct STU{
    char chName[20];
    float fScore;
}STU;

void print(STU* stu){
    if(stu!= NULL){
        cout << stu->chName << "  " << stu->fScore <<endl;
    }
}

int main(int argv ,char* argc[]){
    STU jack = {"jack",99.9};
    print(&jack);
    STU rose = {"rose",88.8};
    print(&rose);
    
    return 0;
}
#endif





