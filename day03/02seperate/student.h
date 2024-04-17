#ifndef INC_STUDENT_H
#define INC_STUDENT_H

#include <iostream>
using namespace std;

class Student {
public:
    Student(const string& name="hello", int age = 20);
    void who();
    void learn(const string& course);
    void setName(const string& name);
    void setAge(int age);

private:
    string m_name;
    int m_age;
};


#endif
