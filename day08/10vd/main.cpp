#include <iostream>
using namespace std;

class X {
public:
    X() {
        cout << "X::X()" << endl;
    }
    ~X() {
        cout << "X::~X()" << endl;
    }
};

class A {
public:
    A() {
        cout << "A::A()" << endl;
    }
    virtual ~A(){
        cout << "A::~A()" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "B::B()" << endl;
    }
    ~B() {
        cout << "B::~B()" << endl;
    }
private:
    X m_x;
};


int main() {
    // 子类析构时会调用基类的析构
    // B* pa = new B;
    // 基类析构时不会调用子类的析构，除非用virtual修饰析构函数
    A* pa = new B;
    delete pa;

    return 0;
}
