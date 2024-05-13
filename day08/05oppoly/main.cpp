#include <iostream>
using namespace std;

class Integer {
public:
    Integer(int r) : m_r(r) {}
    virtual Integer& operator+=(const Integer& i) {
        m_r+=i.m_r;
        return *this;
    }

    int m_r;
};

class Complex : public Integer {
public:
    Complex(int r, int i) : Integer(r), m_i(i) {}
    // 参数表不同，无法形成有效覆盖
    // Complex& operator+=(const Complex& c) override {

    Complex& operator+=(const Integer& c) override {
    Integer::operator+=(c);
        m_i += dynamic_cast<const Complex&>(c).m_i;
        return *this;
    }

    int m_i;
};

int main() {
    Complex c1(1, 2), c2(3, 4);
    //c1 += c2;

    Integer& i1 = c1;
    Integer& i2 = c2;
    i1 += i2;
    cout << c1.m_r << '+' << c1.m_i <<'i' << endl;



    return 0;
}
