#include<QObject>
#include<iostream>
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
	cout << "MyObject::~MyObject()"<< endl;
}

int main(argc,argv)
{
	QApplication app(argc,argv);
	MyObject* firOject = new MyObject(); 
	//MyObject* firOject = new MyObject(parent); 
	//加parent 就可以形成对象树，销毁基类，子类直接会跟着释放，不加则不构成对象树
	MyObject* secObject = new MyObject();

	
	QObject::connect();
	app.exec();
	return 0;
}

