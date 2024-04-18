#include <iostream>
using namespace std;

class Student {
public:
    Student(const string& name, int age) {
        m_name = name;
        m_age = age;
    }

    Student(const Student& that) {
        m_name = that.m_name;
        m_age = that.m_age;
    }

    void show() {
        cout << m_name << ": " << m_age << endl;
    }
private:
    string m_name;
    int m_age;
};


int main() {
    Student s1("zhangfei", 30);
    s1.show();

    Student s2(s1);
    s2.show();

    Student s3 = s2;
    s3.show();

    return 0;
}

