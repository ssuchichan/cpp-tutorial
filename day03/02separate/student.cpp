#include "student.h"

Student::Student(const string& name, int age){
    m_name = name;
    m_age = age;
}

void Student::who() {
    cout << "I am " << m_name << ", " << m_age << " years old" << endl;
}

void Student::learn(const string& course) {
    cout << "I am learning " << course << endl;
}

void Student::setName(const string& name) {
    if (name == "250") {
        cout << "invalid name" << endl;
        return;
    }
    m_name = name;
}

void Student::setAge(int age) {
    if (age <= 0) {
        cout << "invalid age" << endl;
        return;
    }
    m_age = age;
}
