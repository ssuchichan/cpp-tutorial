#include <iostream>
using namespace std;

class Complex {
public:
    Complex(int r = 0, int i = 0) : m_r(r), m_i(i) {}

    void print() const {
        cout << m_r  << (m_i > 0 ? "+" : "") << m_i << "i" << endl;
    }

    const Complex operator-() {
        return Complex(-m_r, -m_i);
    }

    friend const Complex operator~(const Complex& o) {
        return Complex(o.m_i, o.m_r);
    }

private:
    int m_r;
    int m_i;
};

int main() {
    Complex c1(1, 2);
    c1.print();
    Complex c2 = -c1;
    c2.print();

    c2 = ~c1;
    c2.print(); // 2 + 1i

    return 0;
}