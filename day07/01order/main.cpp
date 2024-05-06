#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A::A(): " << this << endl;
    }
    ~A() {
        cout << "A::~A()" << endl;
    }
private:
    int m_data;
};

class C {
public:
    C() {
        cout << "C::C(): " << this << endl;
    }
    ~C() {
        cout << "C::~C()" << endl;
    }
private:
    int m_data;
};

class B : public A {
public:
    B() {
        cout << "B::B(): " << this << endl;
    }
    ~B() {
        cout << "B::~B()" << endl;
    }
private:
    C m_c;
    int m_data;
};

int main() {
    // 构造基类子对象->构造成员变量->执行构造代码
    // B b;
    // cout << sizeof(b) << endl;
    // cout << &b.m_data << endl;
    // 执行析构代码->析构成员变量->析构基类子对象

    A* p = new B;
    // 基类析构函数不会调用子类析构函数
    // 并未执行B、C的析构函数
    // delete p;

    delete static_cast<B*>(p);

    return 0;
}

