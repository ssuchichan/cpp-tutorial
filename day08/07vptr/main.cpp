#include <iostream>
using namespace std;

class A {
public:
    virtual void foo() {
        cout << "A::foo()" << endl;
    }
    virtual void bar() {
        cout << "A::bar()" << endl;
    }
};

class B : public A {
public:
    void foo() override {
        cout << "B::foo()" << endl;
    }
};


int main() {
    /*
    B b;
    A* pa = &b;
    pa->foo();
    pa->bar();
    */

    A a;
    void(**vptr)() = *(void(***)())&a;
    cout << vptr << endl;
    cout << (void*)vptr[0] << ' ' << (void*)vptr[1] << endl;
    vptr[0]();
    vptr[1]();

    cout << "--------------------------------------------" << endl;
    B b;
    vptr = *(void(***)())&b;
    cout << vptr << endl;
    cout << (void*)vptr[0] << ' ' << (void*)vptr[1] << endl;
    vptr[0]();
    vptr[1]();

    return 0;
}
