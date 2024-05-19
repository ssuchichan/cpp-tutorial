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

void func3() {
    A a;
    FILE* fp = fopen("none.txt", "r");
    if (!fp) {
        throw -1;
        // 1.跳转到当func3()的右括号
        // 2.跳转到当func2()的右括号
        // 3.跳转到当func1()的右括号
        // 4.跳转到当try的右括号
        // 5.在catch中有没有处理异常值的代码
    }
    // ...
    fclose(fp);
}

void func2() {
    A a;
    func3();
}

void func1() {
    A a;
    func2();
}


int main() {
    try {
        func1();

        // 不执行后面的代码
        cout << "after exception" << endl;
    }
    catch(int ex) {
        if (ex == -1) {
            cout << "fopen failed" << endl;
            return -1;
        }
    }

    return 0;
}

