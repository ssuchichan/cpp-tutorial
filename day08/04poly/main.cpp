#include <iostream>
using namespace std;

class A {
public:
    A() {
        // 基类部分先于子类部分构造，此时子类部分还没构造出来
        // this是指向基类对象的基类指针
        bar();
    }

    ~A() {
        // 子类先析构，此时子类部分已经析构了，因此是指向基类对象的基类指针
        bar();
    }

    void foo() {
        this->bar(); // 指向子类的基类指针调用子类的覆盖函数
    }

    virtual void bar() {
        cout << "A" << endl;
    }
};

class B : public  A {
public:
    void bar() {
        cout << "B" << endl;
    }
};

int main() {
    B b;
    b.foo();

    return 0;
}
