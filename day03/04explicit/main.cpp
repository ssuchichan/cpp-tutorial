#include <iostream>
using namespace std;

class Dog;

class Cat {
public:
    Cat(const string& name) {
        m_name = name;
    }
    explicit Cat(const Dog& dog);
    // Cat(const Dog& dog) {
    //     m_name = dog.m_name;
    // }
    void talk() {
        cout << m_name << ": 喵喵" << endl;
    }
private:
    string m_name;
};

class Dog {
public:
    Dog(const string& name) {
        m_name = name;
    }
    void talk() {
        cout << m_name << ": 汪汪" << endl;
    }
private:
    string m_name;
    friend class Cat; // 友元
};


Cat::Cat(const Dog& dog) {
    m_name = dog.m_name;
}

int main() {
    Dog dog("小白");
    dog.talk();

    // 编译器会去寻找有没有能接受Dog的构造函数
    // Cat cat = dog;
    Cat cat = static_cast<Cat>(dog);
    cat.talk();

    Cat cat2("大橘");
    cat2.talk();
    cat2 = static_cast<Cat>(dog);
    cat2.talk();

    return 0;
}
