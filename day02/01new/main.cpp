#include <iostream>
using namespace std;


int main() {
    // int* p1 = (int*)malloc(sizeof(int));
    int* p1 = new int;
    *p1 = 1234;
    cout << *p1 << endl;
    // free(p1);
    delete p1;

    p1 = new int(1000);
    cout << *p1 << endl;
    delete p1;

    p1 = NULL; // NULL不会产生double free
    delete p1;

    p1 = new int[4]{0,1,2,3};
    cout << p1[0] << ' ' << p1[1] << ' ' << p1[2] << ' ' << p1[3] << endl;
    delete[] p1;

    int(*p2)[4] = new int[3][4]{1,2, 3, 4,
                                5, 6, 7, 8,
                                9, 10, 11, 12};
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 4; j++) {
            cout << p2[i][j] << ' ';
        }
        cout << endl;
    }

    delete[] p2;
    /*
    try {
        p1 = new int[0xFFFFFFFF];
    } catch(exception& ex) {
        cout << "new failed: " << ex.what() << endl;
        return -1;
    }
    delete[] p1;
    */

    short buf[4] = {0};
    // 在buf中所指向的内存（栈）中分配内存，因此不需要delete
    p1 = new(buf)int(0x12345678);
    cout << showbase << hex << *p1 << endl;
    for (size_t i = 0; i< 4; ++i) {
        cout << (int)buf[i] << ' ';
    }
    cout << endl;
    cout << "buf: " <<buf << endl;
    cout << "p1: " << p1 << endl;

    return 0;
}
