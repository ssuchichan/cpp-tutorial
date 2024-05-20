#include <iostream>
using namespace std;

class FileError {};
class MemoryError {};

void foo() throw(FileError, MemoryError) {
    throw -1;
    throw MemoryError();
    throw FileError();
}

int main() {
    try {
        foo();
    }
    catch (FileError& e) {
        cout << "file error" << endl;
    }
    catch (MemoryError& e) {
        cout << "memory error" << endl;
    }
    catch (...) {
        cout << "other error" << endl;
    }

    return 0;
}
