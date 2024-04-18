#include <iostream>
#include <cstring>

using namespace std;

class A {
public:
    A() : m_r(* new int(100)), m_c(200) {
        // 引用和常量要在定义时初始化，如下两行不是初始化而是赋值
        // m_r = *new int(100);
        // m_c = 200;
    }

    void print() {
        cout << m_r << ", " << m_c << endl;
    }

private:
    int& m_r;
    const int m_c;
};

class Dummy{
public:
    // 根据声明顺序，先初始化m_len再初始化m_str
    // Dummy(const char* psz) : m_str(psz), m_len(m_str.length()) {}

    // 降低耦合，减少对成员变量的依赖
    Dummy(const char* psz) : m_str(psz), m_len(strlen(psz ? psz : "")) {}
    int len() { return m_len; }
    string str() { return m_str; }

private:
    size_t m_len;
    string m_str;
};

int main() {
    A a;
    a.print();

    Dummy d("hello");
    cout << d.len() << " " << d.str() << endl;

    return 0;
}
