#include <iostream>
#include <cstdio>
#include <csetjmp>

using namespace std;

jmp_buf g_env;

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
        // goto不能跨函数，即goto和escape要在同一个函数
        //goto escape;
        longjmp(g_env, -1);
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
    // 第一次调用setjmp会返回0，把当前栈帧存到g_env中
    if (setjmp(g_env) == -1) {
        cout << "fopen failed" << endl;
        return -1;
    }

    func1();

    return 0;

escape:
    cout << "fopen failed" << endl;

}
