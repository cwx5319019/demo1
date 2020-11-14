#ifndef user_h
#define user_h

//User结构体采用单向链表
typedef struct User{
	char name[20];//用户名
	char pwd[20];//密码
	int cash;//余额
	struct User* next;//指向下一个User结构体
}user_t;

#endif
