#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void hum() {
    // ...
    throw 1;
}

void bar() {
    char* buf = (char*)malloc(256);
    try {
        hum();
    }
    //catch (int ex) { // 捕获的ex是从安全区复制的异常的一个副本
    catch (int& ex) {
        cout << ex << " hum failed" << endl;
        free(buf);
        ++ex;
        throw; // 把捕获的异常继续往上扔
    }
}

void foo() {
    FILE* fp = fopen("good.txt", "r");
    try {
        bar();
    }
    catch(int& ex) {
        cout << ex << " bar failed" << endl;
        fclose(fp);
        ++ex;
        throw;
    }
}

int main() {
    try {
        foo();
    }
    catch (int& ex) {
        cout << ex << " foo failed" << endl;
        return -1;
    }

    return 0;
}
