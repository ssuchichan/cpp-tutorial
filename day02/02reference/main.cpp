#include <iostream>
using namespace std;

void swap1(int a, int b) {
    int c = a;
    a = b;
    b = c;
}

void swap2(int* a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void swap3(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void swap4(const char* x, const char* y) {
    const char* z = x;
    x = y;
    y = z;
}

void swap5(const char** x, const char** y) {
    const char* z = *x;
    *x = *y;
    *y = z;
}

void swap6(const char*&x, const char*& y) {
    const char* z = x;
    x = y;
    y = z;
}

struct Student {
    char name[256];
    int age;
};

// 不用复制实参
// 常引用防止对实参的意外修改
void print(const Student& s) {
    // cout << s.name << ' ' << ++s.age << endl;
    cout << s.name << ' ' << s.age << endl;
}
// 接受常量型实参
void show(const int& i) {
    cout << i << endl;
}

int main() {
    int a = 10;
    int& b = a;
    cout << b << endl;
    ++b;
    cout << a << endl;

    // int& c; // error
    int d = 20;
    b = d;
    cout << a << ' ' << b << endl;
    // int& c = NULL; // error
    const int& c = NULL;
    cout << c << endl;

    int n1 = 10, n2 = 20;
    swap1(n1, n2);
    cout << n1 << ' ' << n2 << endl; // 10 20
    swap2(&n1, &n2);
    cout << n1 << ' ' << n2 << endl; // 20 10
    swap3(n1, n2);
    cout << n1 << ' ' << n2 << endl; // 10 20

    const char* x = "hello";
    const char* y = "world";
    swap4(x, y);
    cout << x << ' ' << y << endl; // hello world
    swap5(&x, &y);
    cout << x << ' ' << y << endl; // world hello
    swap6(x, y);
    cout << x << ' ' << y << endl; // hello world

    Student s = Student{"zhangfei", 20};
    print(s);
    show(a);

    return 0;
}
