#include <iostream>
using namespace std;

class Counter {
public:
    Counter(int data=0) : m_data(data) {}

    Counter& add() {
        ++m_data;
        return *this;
    }

    void print() { cout << m_data << endl; }
    void destroy() { delete this; }

private:
    int m_data;
};

int main() {
    Counter c;
    //c.add();
    //c.add();
    //c.add();
    c.add().add().add();
    c.print();

    Counter* pc = new Counter;
    pc->destroy();

    return 0;
}
