#include <iostream>
using namespace std;


class Singleton {
public:
    static Singleton& getInstance() {
        if (!s_instance) {
            s_instance = new Singleton;
        }
        return *s_instance;
    }
private:
    Singleton(){}
    Singleton(const Singleton& that){}
    
    static Singleton* s_instance;
};

Singleton* Singleton::s_instance = nullptr;

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    Singleton& s3 = Singleton::getInstance();
    cout << &s1 << " " << &s2 << " " << &s3 << endl;

    return 0;
}
