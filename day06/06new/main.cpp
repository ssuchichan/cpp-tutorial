#include <iostream>
#include <cstdlib>
using namespace std;

class A {
public:
    A(int data = 0, char c=0): m_data(data), m_ch(c) {
        cout << "A::A(): this=" << this << endl;
    }

    ~A() {
        cout << "A::~A(), this=" << this << endl;
    }

    static void* operator new(size_t size) {
        cout << "A::new(" << size << "): ";
        void* pv = malloc(size);
        cout << pv << endl;
        return pv;
    }

    static void operator delete(void* pv) {
        cout << "A::delete(" << pv << ")" << endl;
        free(pv);
    }

    static void* operator new[](size_t size) {
        cout << "A::new[](" << size <<"): ";
        void* pv = malloc(size);
        cout << pv << endl;
        return pv;
    }

    static void operator delete[](void* pv) {
        cout << "A::delete[](" << pv << ")" << endl;
        free(pv);
    }

private:
    int m_data;
    char m_ch;
};


int main() {
    A* pa1 = new A;
    /*
    A* pa1 = (A*)A::operator new(sizeof(A));
    pa1->A();
    */

    cout << "pa1 = " << pa1 << endl;

    delete pa1;
    /*
    pa1->~A();
    A::operator delete(pa1);
    */
    cout << "-------------------------------------" << endl;
    A* pa2 = new A[3];
    /*
    A* pa2 = ((size_t*)A::operator new[](sizeof(size_t) + sizeof(A) * 3) + 1);
    *((size_t*)pa2 - 1) = 3;
    for (size_t i = 0; i < *(size_t*)pa2 - 1; ++i) {
        (pa2+i)->A();
    }
    */
    cout << "len=" << *((size_t*)pa2 -1) << endl;
    cout << "pa2 = " << pa2 << endl;
    delete[] pa2;
    /*
    for (size_t i = *((size_t*)pa2 -1) - 1; ; --i ) {
        (pa2+i)->~A();
        if (i == 0) {
            break;
        }
    }
    A::operator delete[]((size_t*)pa2-1);
    */

    return 0;
}
