#include <iostream>
using namespace std;

class Square {
public:
    double operator()(double r = 0) {
        return r * r;
    }
};

int main() {
    Square square;
    cout << square(10) << endl; // s.operator()(10)
    cout << square() << endl;

    return 0;
}
