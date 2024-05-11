#include <iostream>
using namespace std;

class A {
public:
    A(int n) : m_n(n) {
        cout << "A::A(int) : " << this << endl;
    }
protected:
    int m_n;
};

class X : virtual public A {
public:
    X(int n) : A(n) {
        cout << "X::X(int) : " << this << endl;
    }
    int get() {
        cout << "X::get " << &m_n << endl;
        return m_n;
    }
};

class Y : virtual public A {
public:
    Y(int n) : A(n) {
        cout << "Y::Y(int) : " << this << endl;
    }

    void set(int n) {
        cout << "Y::set " << &m_n << endl;
        m_n = n;
    }
};

class Z : public X, public Y {
public:
    Z(int n): X(n), Y(n), A(n) {
        cout << "Z::Z(int) : " << this << endl;
    }
    Z(const Z& that): X(that), Y(that), A(that) {

    }
};


int main() {
    Z z(100);
    z.set(200);
    cout << z.get() << endl;

    Z z2 = z;
    cout << z2.get() << endl;

    return 0;
}
