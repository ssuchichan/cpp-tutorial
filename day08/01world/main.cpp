#include <iostream>
using namespace std;

class Cat {
public:
    void talk() {
        cout << "miao!" << endl;
    }
};

class Dog {
public:
    void talk() {
        cout << "wang!" << endl;
    }
};

class Human {
public:
    void talk() {
        cout << "hey!" << endl;
    }
};

class A {
public:
    void foo() {
        cout << "A::foo()" << endl;
    }
};
class B :public  A {
public:
    void bar() {
        cout << "B::bar()" << endl;
        cout << ++m_data << endl;
    }
    void foo() {
        cout << "B::foo()" << endl;
    }
    int m_data;
};

int main() {
    Cat cat;
    Dog dog;
    Human human;
    cat.talk();
    dog.talk();
    human.talk();

    B b;
    A* pa = &b;
    // 编译时，编译器只能看到类型，还没有对象
    // p->bar(); // ERROR

    A a;
    B* pb = static_cast<B*>(&a);
    pb->bar();
    //pb = nullptr;
    //pb->bar(); // 运行时错误

    b.foo();
    b.A::foo();

    return 0;
}
