#include <iostream>
#include <cstdio>
using namespace std;


class Integer {
public:
    explicit Integer(int data = 0) : m_data(data) { }

    explicit operator int() const {
        return m_data;
    }
    
    explicit operator int&() {
        return m_data;
    }

private:
    int m_data;
};

class Student {
public:
    Student(const string& name="", int age=0) : m_name(name), m_age(age) {}

    explicit operator string() const {
        char str[128] = {0};
        sprintf(str, "%s, %d", m_name.c_str(), m_age);
        return str;
    }

private:
    string m_name;
    int m_age;
};

int main() {
    Integer i1 = Integer(100);
    int i2 = int(i1);
    cout << i2 << endl;
    
    i1 = Integer(200);
    cout << int(i1) << endl;


    Student s("zhangfei", 35);
    cout << string(s) << endl;

    return 0;
}
