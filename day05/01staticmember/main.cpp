#include <iostream>
using namespace std;

class A {
public:
    void bar() {
        cout << m_i << endl;
        cout << m_d << endl;
    }

    static void foo() {
        cout << "A::foo()" << endl;
        cout << m_i << endl;
        // cout << m_d << endl; // ERROR
    }

    static int m_i;

private:
    double m_d;
};

int A::m_i = 1234;


class B {
public:
    void foo() {} // 代码区
    static int m_data; // 数据区
};

int main() {
    cout << A::m_i << endl;

    A a1;
    cout << sizeof(a1) << endl;
    cout << a1.m_i <<endl;

    A a2;
    a2.m_i++;
    cout << a1.m_i << endl;


    cout << sizeof(B) << endl; // 1
    // 引用是实体（有内存）的别名，如果空类的大小是0，则自相矛盾
    B b;
    B& r = b;
    // 如果空类大小是0，如何解释如下代码？
    B b2[10] = {};
    b2[5]; // *(b+5)

    return 0;
}
