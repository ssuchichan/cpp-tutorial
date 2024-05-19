#include <iostream>
#include <cstdio>

using namespace std;

class A {
public:
    A() {
        cout << "A::A()" << endl;
    }
    ~A() {
        cout << "A::~A()" << endl;
    }
};

int func3() {
    A a;
    FILE* fp = fopen("none.txt", "r");
    if (! fp) {
        cout << "fopen failed" << endl;
        return -1; // return下一步到函数的右括号，它的指令就包括对局部变量的析构
    }
    // ...
    fclose(fp);
    return 0;
}

int func2() {
    A a;
    if (func3() == -1) {
        return -1;
    }
    // ...
    return 0;
}

int func1() {
    A a;
    if (func2() == -1) {
        return -1;
    }
    // ...
    return 0;
}


int main() {
    if (func1() == -1) {
        return -1;
    }

    return 0;
}

