#include <iostream>
using namespace std;

class Complex {
public:
    Complex(int r = 0, int i = 0) : m_r(r), m_i(i) {}

    void print() const {
        cout << m_r  << (m_i > 0 ? "+" : "") << m_i << "i" << endl;
    }

    Complex add(const Complex& c) {
        return Complex(m_r+c.m_r, m_i+c.m_i);
    }

    Complex sub(const Complex& c) {
        return Complex(m_r-c.m_r, m_i-c.m_i);
    }

private:
    int m_r;
    int m_i;
};

int main() {
    Complex c1(1, 2);
    c1.print();

    Complex c2(3,4);
    Complex c3 = c1.add(c2);
    c3.print();

    Complex c4 = c1.sub(c2);
    c4.print();

    return 0;
}
