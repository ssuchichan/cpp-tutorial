#include <iostream>
using namespace std;


class Singleton {
public:
    static Singleton& getInstance() {
        if (!s_instance) {
            pthread_mutex_lock(&s_mutex);
            if (!s_instance) {
                s_instance = new Singleton;
            }
            pthread_mutex_unlock(&s_mutex);
        }
        ++s_counter;
        return *s_instance;
    }

    void releaseInstance() {
        if (s_counter && --s_counter == 0) {
            delete this;
        }
    }

private:
    Singleton() {
        cout << "Singleton::Singleton()" << endl;
    }
    Singleton(const Singleton& that) {}
    ~Singleton() {
        cout << "Singleton::~Singleton()" << endl;
        s_instance = nullptr;
    }
    static size_t s_counter;
    static Singleton* s_instance;
    static pthread_mutex_t s_mutex;
};
pthread_mutex_t Singleton::s_mutex = PTHREAD_MUTEX_INITIALIZER;
size_t Singleton::s_counter = 0;
Singleton* Singleton::s_instance = nullptr;

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    Singleton& s3 = Singleton::getInstance();
    cout << &s1 << " " << &s2 << " " << &s3 << endl;
    s1.releaseInstance();
    s2.releaseInstance();
    s3.releaseInstance();


    return 0;
}
