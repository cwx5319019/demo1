//布尔类型

#include<iostream>
using namespace std;

#if 0
int main(int argc,char* argv[]){
    //if('')      //直接报错
    //if('\0')    //假   // '\0' 对应的是 空字符    
    //if("")      //真   // 把它当作字符指针，他不是空
    {
        cout << "******" << endl;
    }else{
        cout << "######" << endl;
    }
    cout << sizeof('\0') <<endl;  
    cout << sizeof("")  << endl;
            
    return 0;
}
#endif

int main(int argc,char* argv[]){
    //bool a = true ;
    //bool a = false;
    //bool a = True;  //这样不行
    //bool a = TRUE;  //这样不行
    bool a = 1;
    //bool a = 0;
    //bool a = 789;   //布尔只有真(1) 假(0) 所以输入789 它也会转化为 1
    cout << "sizeof:" << sizeof(a) <<endl;
    if(a)
    {
        cout << "******" << endl;
    }else{
        cout << "######" << endl;
    }
    cout << "a:" << a << endl;

    return 0;
}















