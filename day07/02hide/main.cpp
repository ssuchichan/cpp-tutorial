#include <iostream>
using namespace std;

class Base {
public:
    void foo() {
        cout << "Base::foo()" << endl;
    }
};

class Derive : public Base {
public:
    using Base::foo;
    void foo(int x) {
        cout << "Derive::foo(int)" << endl;
    }
};

int main() {
    Derive d;
    //d.Base::foo();
    d.foo();
    d.foo(1);

    return 0;
}
