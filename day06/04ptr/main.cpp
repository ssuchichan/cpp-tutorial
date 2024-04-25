#include <iostream>
#include <memory>
using namespace std;

class A {
public:
    A() { cout << "A::A()" << endl; }
    ~A() { cout << "A::~A()" << endl; }
    void foo() { cout << "A::foo() " << m_data << endl; }

private:
    int m_data;
};

class PA {
public:
    PA(A* p = nullptr) : m_p(p) { }

    ~PA() {
        if (m_p) {
            delete m_p;
        }
    }

    PA(PA& that) : m_p(that.release()) { }

    PA& operator=(PA& that) {
        if (&that != this) {
            reset(that.release());
        }
        return *this;
    }

    A* operator->() {
        return m_p;
        // return &**this;
    }

    A& operator*() {
        return *m_p;
    }

private:
    A* release() {
        A* p = m_p;
        m_p = nullptr;
        return p;
    }
    void reset(A* p) {
        if (p != m_p) {
            delete m_p;
            m_p = p;
        }
    }

    A* m_p;
};

int main() {
    /*
    A* pa = new A;
    pa->foo();
    (*pa).foo();
    delete pa;
    */

    PA pa(new A);
    pa->foo(); // pa.operator->()->foo();
    (*pa).foo();

    PA pb;
    pb = pa;
    (*pb).foo();
    // pa->foo(); // 此刻pa已经失效 ERROR

    auto_ptr<A> ap(new A);
    ap->foo();
    (*ap).foo();

    auto_ptr<A> bp = ap;
    bp->foo();
    (*bp).foo();
    // ap->foo(); // ERROR

    return 0;
}
