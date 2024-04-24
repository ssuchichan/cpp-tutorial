#include <iostream>
using namespace std;

class Complex {
public:
    Complex(int r = 0, int i = 0) : m_r(r), m_i(i) {}

    void print() const {
        cout << m_r  << (m_i > 0 ? "+" : "") << m_i << "i" << endl;
    }

    // 从左到右的三个const：
    // 返回右值
    // 常右操作数
    // 常左操作数
    Complex operator+(const Complex& r) const {
        return Complex(m_r+r.m_r, m_i+r.m_i);
    }

    // 友元函数
    // 虽然写在类内，但仍然是全局函数
    friend const Complex operator-(const Complex& l, const Complex& r) {
        return Complex(l.m_r - r.m_r, l.m_i - r.m_i);
    }

private:
    int m_r;
    int m_i;
};

/*
const Complex operator-(const Complex& l, const Complex& r) {
    return Complex(l.m_r - r.m_r, l.m_i - r.m_i);
}
*/


int main() {
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3 = c1 + c2;
    c3.print();

    Complex c4 = c1 - (c3 + c2);
    c4.print();
    
    return 0;
}
