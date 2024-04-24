#include <iostream>
#include <fstream>
using namespace std;

class Complex {
public:
    Complex(int r = 0, int i = 0) : m_r(r), m_i(i) {}

    void print() const {
        cout << m_r  << (m_i > 0 ? "+" : "") << m_i << "i" << endl;
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        return os << c.m_r  << (c.m_i > 0 ? "+" : "") << c.m_i << "i";
    }
    friend istream& operator>>(istream& is, Complex& c) {
        return is >> c.m_r >> c.m_i;
    }
private:
    int m_r;
    int m_i;
};

int main() {
    Complex c1(1, 2);
    // cout.operator<<(c)
    // ::operator<<(cout, c).operator<<(endl);
    cout << c1 << endl;

    ofstream ofs("complex.txt");
    ofs << c1 << endl;

    Complex c2, c3;
    cin >> c2 >> c3;// ::operator>>(::operator>>(cin,c1), c2);
    cout << c2 << ", " << c3 << endl;

    return 0;
}