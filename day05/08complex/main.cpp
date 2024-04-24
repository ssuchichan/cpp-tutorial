#include <iostream>
using namespace std;

class Complex {
public:
    Complex(int r = 0, int i = 0) : m_r(r), m_i(i) {}

    void print() const {
        cout << m_r  << (m_i > 0 ? "+" : "") << m_i << "i" << endl;
    }

    Complex& operator+=(const Complex& r) {
        m_r += r.m_r;
        m_i += r.m_i;
        return *this;
    }

    friend Complex& operator-=(Complex& l, const Complex& r) {
        l.m_r -= r.m_r;
        l.m_i -= r.m_i;
        return l;
    }

private:
    int m_r;
    int m_i;
};

int main() {
    Complex c1(1, 2);
    Complex c2(3, 4);
    const Complex c3(5, 6);
    c1 += c2;
    c1.print(); // 4 + 6i

    (c1 += c2) += c3;
    c1.print(); // 12 + 16i

    ((c1 -= c3) -= c2) -= c2;
    c1.print(); // 1 + 2i

    return 0;
}
