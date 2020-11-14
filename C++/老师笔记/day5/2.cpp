#if 0
2. (本题3分)
自定义一个string类型，要求有合理的构造函数，拷贝构造方法、析构函数，输出方法；
class String{
private:
    char *_data;
public:
    String(const char *str  = 0);
    String(const String& rhs);
    ~String();
    const char* data() const;

};
#endif
#include<iostream>
#include<string.h>
using namespace std;
class String{
private:
    char *_data;
public:
    String(const char *str  = NULL)
        :_data(NULL)
    {
        if(str == NULL){
            _data = new char[1];
        }else{
            _data = new char[strlen(str)+1];
            strcpy(_data,str);
        }
        cout << "构造成功！！" << endl;
    }
    String(const String& rhs)
    {
        this->_data = new char[strlen(rhs._data)+1];
        strcpy(this ->_data,rhs._data);
        cout << "拷贝成功！！" << endl;
    }
    const char* getData() const
    {
        return _data;    
    }
    ~String(){
        cout << "释放成功！" << endl;
        delete []_data;      
    }
};

int main(void){
    String s1("hello,iotek!");
    cout << "_data = " << s1.getData() << endl;
    String s2 = s1;
    return 0;
}











