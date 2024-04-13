#include <iostream>
using namespace std;


int g_x;

int& foo() { return g_x; }
const int& foo2() { return g_x; }

int& bar() {
    int a = 100;
    // 返回局部变量的引用
    return a;
}

int& hum() {
    int b = 200;
    return b;
}

struct Student {
    char name[256];
    int age;

    int& howOld() {
        return age;
    }
};

int& fun(int& r) { return r; }

/*
int& fun(int r) { // ERROR
    return r;
}
int fun(int r) { // OK
    return r;
}
int fun(int& r) { // OK
    return r;
}
*/
int main() {
    foo() = 10;
    cout << g_x << endl;
    ++foo();
    cout << g_x << endl;
    foo()++;
    cout << g_x << endl;
    foo() += 10;
    cout << g_x << endl;

    // int& a = bar();
    // cout << a << endl;
    // hum();
    // cout << a << endl;

    Student s = {"zhengfei", 20};
    // age在s中，而s在main函数的栈中
    // 只要main函数不返回，就不用担心age被释放
    int age = s.howOld();
    cout << age << endl;

    int y = 1000;
    int& r = fun(y);
    ++r;
    cout << y << endl;

    cout << foo2() << endl;
    // foo2()++; // ERROR

    return 0;
}
