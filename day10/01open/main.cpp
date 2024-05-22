#include <iostream>
#include <fstream>
using namespace std;

class Complex {
public:
    Complex(int r = 0, int i = 0) : m_r(r), m_i(i) {}

    friend istream& operator>>(istream& is, Complex& c) {
        return is >> c.m_r >> c.m_i;
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        return os << c.m_r << ' ' << c.m_i;
    }
private:
    int m_r, m_i;
};

int main() {
    // 离开作用于，析构函数会调用close
    ofstream ofs("open.txt", ios::out);
    // 显式关闭
    ofs.close();

    ofs.open("open.txt");
    ofs << "hello,world " << 1234 << ' ' << 56.68 << endl;
    Complex c(123, 456);
    ofs << c << endl;
    ofs.close();

    ofs.open("open.txt", ios::app);
    ofs << "good" << endl;
    ofs.close();

    ifstream ifs("open.txt", ios::in);
    int i;
    double d;
    string s;
    Complex c2;
    ifs >> s >> i >> d >> c2; // 按空格分割
    cout << s << endl;
    cout << i << endl;
    cout << d << endl;
    cout << c2 << endl;
    ifs.close();

    return 0;
}
