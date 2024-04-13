#include <iostream>
using namespace std;


int main() {
    int* pi;
    // int*能隐式地转为void*
    void* pv = pi;
    pi = static_cast<int*>(pv);

    // doule不能隐式地转为void*
    // double d = static_cast<double>(pv);

    const int* p1;
    int* p2 = const_cast<int*>(p1);

    int a  = 10;
    const int& r1 = a;
    int& r2 = const_cast<int&>(r1);
    r2 = 20;
    cout << a << endl;

    // 编译器常量优化：c有长属性，所用出现c的地方都用100替换
    // 如果想改，可以使用volatile关键字。告诉编译器可以通过变量名意外的方式修改。
    const int c = 100;
    int* pc = const_cast<int*>(&c);
    *pc = 200;
    cout << pc << ' ' << &c << endl;
    cout << *pc << endl; // 200
    cout << c << endl; // 100

    const volatile int d = 300;
    int* pd = const_cast<int*>(&d);
    *pd = 400;
    cout << pd << ' ' << &c << endl;
    cout << *pd << endl; // 400
    cout << d << endl; // 400

    struct Student {
        char name[256];
        int age;
    };
    Student s = {"zhangfei", 20};
    char* ps = reinterpret_cast<char*>(&s);
    cout << ps << endl; // zhangfei
    int* pn = reinterpret_cast<int*>(ps + 256);
    cout << *pn << endl; // 20
    uint64_t n = reinterpret_cast<uint64_t>(pn);
    cout << showbase << hex << n << ' ' << pn << endl;
    cout << dec << *reinterpret_cast<int*>(n) << endl; // 20

    return 0;
}

