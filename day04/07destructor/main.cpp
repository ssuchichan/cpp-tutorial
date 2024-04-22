#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A构造" << endl;
    }
    ~A() {
        cout << "A析构" << endl;
    }
};

class B {
public:
    B():m_aa(new A) {
        cout << "B构造" << endl;
    }
    ~B() {
        cout << "B析构" << endl;

        // 指针是基本类型，它指向的内存要手动释放
        delete m_aa;
    }
private:
    A m_a; // 类类型的变量会自动调用相应类型的析构函数
    A* m_aa;
};

int main() {
    B b;
    return 0;
}
