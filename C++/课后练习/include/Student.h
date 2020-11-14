#ifndef _STUDENT_H
#define _STUDENT_H
class Student
{
public:
	int id;
	int score;
	Student(const int id,const int  score);

	~Student();

	virtual void print();

};


#endif
