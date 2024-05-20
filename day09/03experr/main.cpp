#include <iostream>
#include <cstdio>
#include <cstdlib>

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

class FileError {
public:
    FileError(const string& file, int line) : m_file(file), m_line(line) {}
    friend ostream& operator<<(ostream& os, const FileError& ex) {
        return os << ex.m_file << ':' << ex.m_line;
    }
private:
    string m_file;
    int m_line;
};

class MemoryError{};
class SocketError{};
class Error {};
class MathError: public Error {};

void func3() {
    A a;
    // ...
    throw MathError();
    throw SocketError();

    FILE* fp = fopen("none.txt", "r");
    if (!fp) {
        // 异常会放到安全区中，系统保证了异常从抛出到捕获期间，安全区的数据是安全的（不会被修改）
        // 把throw的异常复制到安全区，catch从安全区中取
        // 异常执行流程：
        // 1.跳转到当func3()的右括号
        // 2.跳转到当func2()的右括号
        // 3.跳转到当func1()的右括号
        // 4.跳转到当try的右括号
        // 5.在catch中有没有处理异常值的代码
        //throw -1;
        throw FileError(__FILE__, __LINE__);
    }

    char* buf = (char*)malloc(0xFFFFFFFFFFFF);
    if (!buf) {
        //throw -2;
        throw MemoryError();
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
        // func1()抛出异常时，不执行其后面的代码
        cout << "after exception" << endl;
    }
    // catch(int ex) {
    //     if (ex == -1) {
    //         cout << "fopen failed" << endl;
    //         return -1;
    //     }
    //     else if (ex == -2) {
    //         cout << "alloc memory failed" << endl;
    //         return -1;
    //     }
    // }
    catch (FileError& ex) {
        cout << "fopen failed" << endl;
        cout  << ex << endl;
        return -1;
    }
    catch (MemoryError& ex) {
        cout << "alloc memory failed" << endl;
        return -1;
    }
    catch (MathError& ex) {
        cout << "math error" << endl;
        return -1;
    }
    catch (Error& ex) {
        cout << "error" << endl;
        return -1;
    }
    catch (...) {
        cout << "other error" << endl;
        return -1;
    }
    return 0;
}

