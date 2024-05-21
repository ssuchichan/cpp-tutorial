#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;

class A {
public:
    A() { cout << "A::A()" << endl; }
    ~A() { cout << "A::~A()" << endl; }
};

class C {
public:
    C() { cout << "C::C()" << endl; }
    ~C() { cout << "C::~C()" << endl; }
};

class B {
public:
    B() : m_apa(new A) {
        m_a = new A;
        FILE* fp = fopen("none.txt", "r");
        if (!fp) {
            delete m_a;
            throw -1;
        }
        fclose(fp);
    }
    ~B() {
        delete m_a;
    }

private:
    A* m_a;
    auto_ptr<A> m_apa; // 智能指针是类
    C m_c; // 类类型对象，会被正确析构
};



int main() {
    try {
        B b;
    }
    catch (int& ex) {
        cout << "err: " << ex << endl;
    }

    return 0;
}
