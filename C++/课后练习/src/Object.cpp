#include<iostream>
#include<QObject>
using namespace std;
class MyObject:public QObject
{
public:
	MyObject(QObject* parent = 0);
	~MyObject();

};
MyObject::MyObject(QObject* parent)
	:QObject(parent)
{
	cout << "MyObject::MyObject(parent)" << endl;

}
MyObject::~MyObject()
{
	cout << "MyObject::~MyObject()" << endl;

}

int main(void)
{
	MyObject* parent = new MyObject();  //没有指定父对象
	MyObject* child1 = new MyObject(parent);//指定父对象
	MyObject* child2 = new MyObject(parent);
	
	delete parent;
}
