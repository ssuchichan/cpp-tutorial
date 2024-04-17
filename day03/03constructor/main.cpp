#include <iostream>
using namespace std;

class Student {
public:
    Student() {
        m_name = "default";
        m_age = 18;
    }

    Student(const string& name) {
        m_name = name;
        m_age = 18;
    }

    Student(int age) {
        m_name = "default";
        m_age = age;
    }

    Student(const string& name, int age) {
        m_name = name;
        m_age = age;
    }

    void show() {
        cout << m_name << ": " << m_age << endl;
    }

private:
    string m_name;
    int m_age;
};

class A {
public:
    // A(){}
    A(int a) {}
};

class B {
public:
    B(): m_a(0) {}
private:
    A m_a;
};

int main() {
    Student s1;
    s1.show();

    Student s2("zhangfei");
    s2.show();

    Student s3(30);
    s3.show();

    Student s4("zhaoyun", 25);
    s4.show();

    Student sarr[3]; // 必须要有缺省构造函数

    B b;

    return 0;
}
