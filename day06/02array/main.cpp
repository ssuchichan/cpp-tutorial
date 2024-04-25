#include <iostream>
using namespace std;

class A100 {
public:
    A100() : m_arr{ 0 } {}

    int& at(size_t i) {
        return m_arr[i];
    }
    const int& at(size_t i) const {
        return const_cast<A100*>(this)->at(i);
    }
    int& operator[](size_t i) {
        return m_arr[i];
    }
    const int& operator[](size_t i) const {
        return const_cast<A100&>(*this)[i];
    }

private:
    int m_arr[100];
};

int main() {
    A100 a;
    /*
    a.at(0) = 100;
    a.at(1) = 200;
    a.at(0)++;
    --a.at(1);
    cout << a.at(0) << " " << a.at(1) << endl;
    const A100* p = &a;
    cout << p->at(0) << " " << p->at(1) << endl;
    */

    a[0] = 100; // a.operator[](0);
    a[1] = 200;
    a[0]++;
    --a[1];
    cout << a[0] << " " << a[1] << endl;
    const A100* p = &a;
    cout << (*p)[0] << " " << (*p)[1] << endl;

    return 0;
}
