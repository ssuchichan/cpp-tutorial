#include <iostream>
using namespace std;

class Complex {
public:
    Complex(int r = 0, int i = 0) : m_r(r), m_i(i) {}

    void print() const {
        cout << m_r  << (m_i > 0 ? "+" : "") << m_i << "i" << endl;
    }

    Complex& operator++() {
        ++m_r;
        ++m_i;
        return *this;
    }

    const Complex operator++(int) {
        Complex old = *this;
        ++*this;
        return old;
    }

    friend Complex& operator--(Complex& o) {
        --o.m_r;
        --o.m_i;
        return o;
    }

    friend const Complex operator--(Complex& o, int) {
        Complex old = o;
        --o;
        return old;
    }

private:
    int m_r;
    int m_i;
};

int main() {
    Complex c1(1, 2);
    Complex c2 = ++++c1; // c1.operator++().operator++();
    c1.print(); // 3 + 4i
    c2.print(); // 3 + 4i

    c2 = ----c1;
    c2.print(); // 1 + 2i

    c2 = c1++; // c2 = c1.operator++(0)
    c1.print(); // 2 + 3i
    c2.print(); // 1 + 2i

    c2 = c1--;
    c1.print(); // 1 + 2i
    c2.print(); // 2 + 3i

    return 0;
}
