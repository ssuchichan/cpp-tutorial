#include <iostream>
using namespace std;


void foo() {
    cout << "foo()" << endl;
}

void foo(int a) {
    cout << "foo(int)" << endl;
}
// 重载与返回类型无关
// int foo(int a) {}  // error

void bar(int a, float b) {
    cout << "bar(int,float)" << endl;
}
// 参数表不同指类型不同，而不是参数名
// void bar(int b, float a) {} // error

// 参数个数不同
void bar(int a) {
    cout << "bar(int)" << endl;
}

// 参数顺序不同
void bar(float a, int b) {
    cout << "bar(float, int)" << endl;
}


namespace ns1 {
    void nsfoo(int a) {
        cout << "ns1::foo(int)" << endl;
    }
}

namespace ns2 {
    void nsfoo(float a) {
        cout << "ns2::foo(float)" << endl;
    }
}

int main() {
    foo();
    foo(10);
    bar(10, 1.2f);
    bar(10);
    bar(1.2f, 10);

    using namespace ns1;
    using namespace ns2;
    // 构成重载关系
    nsfoo(10);
    nsfoo(1.2f);

    using ns1::nsfoo;
    // 不构成重载关系
    nsfoo(10); // ns1::foo
    nsfoo(1.2f); // ns1::foo

    using ns2::nsfoo;
    // 构成重载关系
    nsfoo(10); // ns1::foo
    nsfoo(1.2f); // ns2::foo

    return 0;
}
