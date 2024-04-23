#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
    Student(const string& name, int age) : m_name(name), m_age(age) {}
    void who() const {
        cout << m_name << ", " << m_age << endl;
    }
    string m_name;
    int m_age;
};


int main() {
    string Student::* p1 = &Student::m_name;
    int Student::* p2 = &Student::m_age;

    void(Student::*who)() const = &Student::who;

    int x = 0;
    memcpy((void*)&x, &p1, 4);
    printf("%d\n", (int)x);
    memcpy((void*)&x, &p2, 4);
    printf("%d\n", (int)x);


    Student s1("zhangfei", 35);
    cout << s1.*p1 << ", " << s1.*p2 << endl;
    (s1.*who)();

    Student* ps = new  Student("zhaoyun", 25);
    cout << ps->*p1 << ", " << ps->*p2 << endl;
    (ps->*who)();

    delete ps;

    return 0;
}
