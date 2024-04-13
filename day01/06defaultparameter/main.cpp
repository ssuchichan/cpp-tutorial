#include <iostream>

using namespace std;

void foo(int a = 0, char b = 'X', float c = 4.56f, const char* d = "hello") {
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
}

// 哑元
void bar(int) {
    cout << "bar(int)" << endl;
}

int main() {
    foo(10, 'A', 1.23f, "world");
    // 缺省参数是编译期确定
    foo(10, 'A', 1.23f); // foo(10, 'A', 1.23f, "hello");
    foo(10, 'A');           // foo(10, 'A', 4,56f, "hello");
    foo(10);                   // foo(10, 'X', 4.56f, "hello");
    foo();                        // foo(0, 'X', 4.56f, "hello");

    bar(10);

    return 0;
}
