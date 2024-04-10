#include <iostream>

int main() {
    union {
        int i;
        char c[4];
    };
    i = 0x12345678;
    printf("%x %x %x %x\n", c[0],c[1],c[2],c[3]);
    i = 65536;
    printf("%x %x %x %x\n", c[0],c[1],c[2],c[3]);
    return 0;
}
