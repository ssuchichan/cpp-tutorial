#include <iostream>
using namespace std;

int main() {
    enum COLOR {
        RED, // 0
        GREEN, // 1
        BLUE // 2
    };

    COLOR color = RED;
    cout << color << endl;
    color = BLUE;
    cout << color << endl;

    // 因为int比枚举的值域大
    int i = GREEN;
    cout << i << endl;
    int j = color;
    cout << j << endl;

    // 大值域赋值给小值域，有风险
    // color = 0; // error

    return 0;
}
