#include <cmath>
#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;

int main() {
    cout << cout.precision() << endl; // 永久有效，精度是小数点前后的总位数
    cout << sqrt(200) << endl; // 14.1421
    cout << cout.precision(10) << endl; // 返回的是改之前的值
    cout << sqrt(200) << endl; // 14.14213562
    cout << sqrt(300) << endl;
    cout.setf(ios::right);
    cout.width(10); // 一次有效
    cout << 123 << endl;
    cout.width(10);
    cout << 456 << endl;
    cout.width(10);
    cout.fill('0'); // 持续有效，填充字符
    cout.setf(ios::left, ios::adjustfield);
    cout << 789 << endl; // 7890000000
    cout.width(10);
    cout << 9527 << endl; // 9527000000

    cout.setf(ios::internal, ios::adjustfield); // 符号位靠左，数字靠右
    cout.width(10);
    cout << -123 << endl; // -000000123

    cout.setf(ios::uppercase);
    cout.setf(ios::showbase);
    cout.setf(ios::hex, ios::basefield);
    cout << 255 << endl; // 0xFF
    cout.setf(ios::dec, ios::basefield);

    cout.setf(ios::scientific, ios::floatfield);
    cout << 1234.5678 << endl; // 1.2345678000E+03
    cout.setf(ios::fixed, ios::floatfield);
    cout << 1234.5678 << endl; // 1234.5678000000

    cout.setf(ios::showpos);
    cout << 100 << endl; // +100
    cout << 100.0 << endl; // +100.0000000000
    cout.setf(ios::showpoint);
    cout.unsetf(ios::fixed);
    cout << 100.0 << endl; // +100.0000000

    cout << true << ' ' << false << endl;
    cout.setf(ios::boolalpha);
    cout << true << ' ' << false << endl;
    cout << (1 > 0) << ' ' << (1 < 0) << endl;
    cout.setf(ios::unitbuf);
    cout << "hello, world";
    sleep(5);
    cout << endl;

    ifstream ifs("ws.txt");
    ifs.unsetf(ios::skipws);
    char c;
    while(ifs >> c) {
        cout << c;
    }
    cout << endl;

    cout << showpos << 123 << endl;
    cout << noshowpos << 456 << endl;

    return 0;
}
