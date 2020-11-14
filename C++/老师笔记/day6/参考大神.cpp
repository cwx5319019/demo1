#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
class myString{
	private:
		char* pdata;
	public:
		myString(const char* data = ""){
			if(!data)
				pdata = new char[1];
			else
				pdata = new char[strlen(data) + 1];
			strcpy(pdata,data);
			cout << "构造成功" <<endl;
		}
		myString(const myString& other){
			this->pdata = new char[strlen(other.pdata)+1];
			strcpy(this->pdata,other.pdata);
			cout << "拷贝成功" << endl;
		}
		myString operator+(const myString& other){
			myString str;
			delete []str.pdata;
			str.pdata = new char[strlen(pdata)+strlen(other.pdata)+1];
			strcat(str.pdata, pdata);
			strcat(str.pdata, other.pdata);
			return str;
		}
		myString operator+=(const myString& other){
			int len = strlen(pdata)+strlen(other.pdata)+1;
			char* ppdata = new char[len];
			strcat(ppdata, pdata);
			strcat(ppdata, other.pdata);
			delete pdata;
			pdata = ppdata;
			return *this;
		}
		myString operator=(const myString& other){
			delete []pdata;
			pdata = new char[strlen(other.pdata)+1];
			strcpy(pdata,other.pdata);
			return *this;
		}
		char operator[](int index){
			if(index < 0 || index >= strlen(pdata)){
				cout << "cross the border" << endl;
				return '\0';
			}
			return pdata[index];
		}
		bool operator<(const myString& other){
			if(strcmp(pdata,other.pdata) < 0){
				return true;
			}
			return false;
		}
		bool operator<=(const myString& other){
			if(strcmp(pdata,other.pdata) <= 0)
				return true;
			return false;
		}
		bool operator>(const myString& other){
			if(strcmp(pdata,other.pdata) > 0)
				return true;
			return false;
		}
		bool operator>=(const myString& other){
			if(strcmp(pdata,other.pdata) >= 0)
				return true;
			return false;
		}
		bool operator==(const myString& other){
			if(strcmp(pdata,other.pdata) == 0)
				return true;
			return false;
		}
		char* getMyStr(){
			return pdata;
		}
		~myString(){
			delete []pdata;
			cout << "析构成功" << endl;
		}
};

int main(){
	myString str1("hello ");
	myString str2("iotek");
	myString str3("world ");
	myString str4 = str1 + str2;
	
	cout << str1.getMyStr() << " + " << str2.getMyStr() << 
		" = " << str4.getMyStr() << endl;
	cout << str1.getMyStr() << " < " << str2.getMyStr() 
		<< " is :" << (str1 < str2) << endl;
	cout << str1.getMyStr() << " <= " << str2.getMyStr() 
		<< " is :" << (str1 <= str2) << endl;
	cout << str1.getMyStr() << " > " << str2.getMyStr() 
		<< " is :" << (str1 > str2) << endl;
	cout << str1.getMyStr() << " >= " << str2.getMyStr() 
		<< " is :" << (str1 >= str2) << endl;
	
	return 0;
}
