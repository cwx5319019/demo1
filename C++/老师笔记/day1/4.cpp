#include<iostream>
using namespace std;

int main(int argc,char* argv[]){
    long long int phone = 0; //注意一下这里 long long int
    //char phone[11] = "";
    cout << "请告诉我你的电话号码：";
    cin >> phone;
    char chName[10] = "";
    char chWechat[20] = "";
    cout << "请问你的名字和微信：";
    cin >> chName >> chWechat;
    cout << phone << "  " << chName << "  " << chWechat << endl;

    return 0;   
}
