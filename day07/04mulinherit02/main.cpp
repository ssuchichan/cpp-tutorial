#include <iostream>
using namespace std;

class A {
public:
    void foo(int x) {
        cout << "A::foo()" << endl;
    }
    void fun() {
        cout << "A::fun()" << endl;
    }
};

class B {
public:
    void foo(double x) {
        cout << "B::foo()" << endl;
    }
    void fun() {
        cout << "B::fun()" << endl;
    }
};

class C : public A, public B {
public:
    C(bool flag) : m_flag(flag) {}
    // 引入当前作用域，构成重载
    using A::foo;
    using B::foo;
    // 如果无法构成重载，只能用作用域限定符
    // using A::fun;
    // using B::fun;
    void bar() {
        foo(10);
        foo(1.23);
    }

    // 提供一个隐藏的版本，根据业务逻辑来区分调用哪个
    void fun() {
        if (m_flag) {
            A::fun();
        } else {
            B::fun();
        }
    }

private:
    bool m_flag;
};

int main() {
    C c(true);
    /*
    // 作用域不同，不构成重载
    c.foo(100); // ERROR
    c.foo(1.23); // ERROR
    */
    c.foo(10);
    c.foo(1.23);
    //c.A::fun();
    //c.B::fun();
    c.fun();

    return 0;
}
