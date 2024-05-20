#include <iostream>
using namespace std;

class FileError : public exception {
public:
    const char* what() const throw() override {
        return "file error";
    }
};


int main() {
    try {
        throw FileError();

        char* p = new char[0xFFFFFFFFFF];
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
        return -1;
    }

    return 0;
}
