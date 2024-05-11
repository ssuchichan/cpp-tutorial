#include <iostream>
using namespace std;
class X {};
class T {};
class Y : public X {};
class Z : public Y, public T {};

class A {
public:
    //virtual void foo() {
    virtual X* foo() {
        cout << "A::foo()" << endl;
        return nullptr;
    }
};

class B : public A {
public:
    B() {}
private:
    // int foo() { // 返回类型如果是基本类型，则必须和基类虚函数原型一致
    // int foo() const { //
    // void foo() {
    // Y* foo() {
    Z* foo() {
        cout << "B::foo()" << endl;
        // return 0;
        return nullptr;
    }
};

int main() {
    B b;
    A& rb = b;
    // 编译器在编译期只能看到类型，还没有对象
    // A中foo是公有的，执行的时发生多态，去B中执行
    rb.foo(); // B::foo

    A a1 = b;
    a1.foo(); // A::foo

    return 0;
}
