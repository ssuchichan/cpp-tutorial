#include <iostream>
#include <sstream>
using namespace std;

int main ()
{
    string is("1234 56.78 hello,world");
    //istringstream iss(is);
    istringstream iss;
    iss.str(is);
    int i;
    double d;
    string s;
    iss >> i >> d >> s;
    cout << i << endl;
    cout << d << endl;
    cout << s << endl;

    ostringstream oss;
    oss << 9527 << ' ' << 54.32 << ' ' << "hello,world";
    string os = oss.str();
    cout << os << endl;

    return 0;
}
