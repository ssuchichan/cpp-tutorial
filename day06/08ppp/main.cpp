#include <iostream>
using namespace std;

class A {
public:
    int m_pub;
protected:
    int m_pro;
private:
    int m_pri;
};

class B : public A {};
class C : protected A {};
class D : private A {
public:
    void foo() {
        // D是A的直接子类，不用考虑继承方式。即除了私有的，都能访问
        m_pub = 10;
        m_pro = 10;
        // m_pri = 10;
    }
};

class X : public B {
public:
    void foo() {
        m_pub = 10;
        m_pro = 10;
        // m_pri = 10; // ERROR
    }
};

class Y : public C {
public:
    void foo() {
        m_pub = 10;
        m_pro = 10;
        // m_pri = 10; // ERROR
    }
};

class Z : public D {
public:
    void foo() {
        // m_pub = 10; // ERROR
        // m_pro = 10; // ERROR
        // m_pri = 10; // ERROR
    }
};


int main() {
    B b;
    b.m_pub = 10;
    // b.m_pro = 10; // ERROR
    // b.m_pri = 10; // ERROR

    C c;
    // c.m_pub = 10; // ERROR
    // c.m_pro = 10; // ERROR
    // c.m_pri = 10; // ERROR

    D d;
    // d.m_pub = 10; // ERROR
    // d.m_pro = 10; // ERROR
    // d.m_pri = 10; // ERROR

    return 0;
}
