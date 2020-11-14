#include<iostream>
int main(int argc,char* argv[]){
    //命名空间
    {  
        using namespace std;
        //cerr << "hello" << endl;
        cout << "hello, world" << endl;
    }
    
    //都在std里面
    //std::cerr << "hello" << std::endl;
    std::cout << "hello ,iotek"<< std::endl;
    
    return 0;
}
