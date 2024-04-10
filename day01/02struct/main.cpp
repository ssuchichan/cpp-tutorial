#include <iostream>
using namespace std;

struct Student{
    // 成员变量
    char name[256];
    int age;

    // 成员函数
    void who() {
        cout << "I am " << name << ", " << age << " years old." << endl;
    }
};



int main() {
    Student s1 = {"zhangfei", 25};
    // .: 成员访问运算符
    cout << s1.name << ' ' << s1.age << endl;

    Student* ps = &s1;
    // ->: 间接成员访问运算符
    cout << ps->name << ' ' << ps->age << endl;

    s1.who();
    ps->who();

    return 0;
}
