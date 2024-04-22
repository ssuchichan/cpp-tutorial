#include <iostream>
using namespace std;


class Singleton {
public:
    static Singleton& getInstance() {
        return s_instance;
    }
private:
    Singleton(){}
    Singleton(const Singleton& that){}

    // 静态变量不在类中，计算大小不计算它
    static Singleton s_instance;
};

Singleton Singleton::s_instance;

int main() {
    // Singleton s; // ERROR
    // Singleton* ps = new Singleton; // ERROR
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    Singleton& s3 = Singleton::getInstance();
    cout << &s1 << " " << &s2 << " " << &s3 << endl;

    // Singleton s4(s3); // ERROR


    return 0;
}
