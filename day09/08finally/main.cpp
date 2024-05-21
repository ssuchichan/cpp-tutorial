#include <iostream>
#include <cstdio>

using namespace std;

class Finally
{
public:
    Finally(const char* filename) : m_fp(fopen(filename, "r")) {}
    ~Finally() {
        cout << "Finally::~Finally()" << endl;
        if (m_fp) {
            delete m_fp;
        }
    }

private:
    FILE* m_fp;
};

void fun() {
    throw -1;
}

int foo() {
    Finally f("a.out");
    try{
        fun();
    }
    catch (int& ex) {
        cout << "err: " << ex << endl;
        return -1;
    }

    return 0;
}

int main()
{
    foo();
    return 0;
}
