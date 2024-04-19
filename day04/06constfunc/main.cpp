#include <iostream>
using namespace std;


class A{
public:
    A(int a = 0) : m_data(a), m_mtb(0) {}
    void print() const {
        cout << m_data << endl;
        m_mtb = 200; // const_cast<A*>(this)->m_mtb = 100;
        const_cast<A*>(this)->m_mtb = 300;
        cout << m_mtb << endl;
    }
    /*
    void print(const A* this) {
        cout << this->m_data << endl;
    }
    */
    void foo() { cout << "非常函数" << endl; }
    void foo() const { cout << "常函数" << endl; }
private:
    int m_data;
    mutable int m_mtb;
};

int main() {
    A a(100);
    a.print();
    a.foo();

    const A& cr = a;
    cr.foo();
    const A* cp = &a;
    cp->foo();

    return 0;
}
