#include <iostream>
using namespace std;

void foo(char* p, int n) { cout << "foo(1)" << endl; }
void foo(const char* p, char c) { cout << "foo(2)" << endl; }

void bar(char c) { cout << "bar(1)" << endl; }
void bar(int n) { cout << "bar(2)" << endl; }
void bar(long long l) { cout << "bar(3)" << endl; }

void hum(double f, ...) { cout << "hum(1)" << endl; }
void hum(int n, void* p) { cout << "hum(2)" << endl; }

int main() {
    // 编译器：
    // 安全原则
    // 工作量最小原则

    char* p;
    char c;
    // foo(1): 升级转换, char  -> int
    // foo(2): 常量转换, char* -> const char*
    foo(p, c); // f(2)

    short s;
    // bar(1): 标准转换，short -> char
    // bar(2): 升级转换, short -> int，增加2个字节，工作量小
    // bar(3): 升级转换, short -> long long，要增加6个字节，工作量大
    bar(s); // bar(2)

    double f;
    void* pv;
    // hum(1): 省略号匹配是最差的选择
    // hum(2): 标准转换
    hum(f, pv); // hum(2)

    void(*pfunc)(char*,int) = foo; // 指定了只能调foo(char*,char)
    // pfunc((const char*)NULL, (char)0); // error

    return 0;
}
