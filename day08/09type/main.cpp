#include <iostream>
#include <typeinfo>
#include <cstring>

using namespace std;

class Human {};
class Student : public Human {};

class Animal{
public:
    virtual void eat(){}
};
class Cat : public Animal {};
class Dog : public Animal {};

void bar(Animal* pa) {
    //if (!strcmp(typeid(*pa).name(), "3Cat")) {
    if (typeid(*pa) == typeid(Cat)){
        cout << "Cat!!!" << endl;
    }
    //else if (!strcmp(typeid(*pa).name(), "3Dog")) {
    else if (typeid(*pa) == typeid(Dog)) {
        cout << "Dog!!!" << endl;
    }
    else {
        cout <<"unknown" << endl;
    }
}

int main() {
    cout << typeid(char).name() << endl; // c
    cout << typeid(unsigned char).name() << endl; // h
    cout << typeid(int).name() << endl; // i
    cout << typeid(int*).name() << endl; // Pi
    cout << typeid(unsigned int).name() << endl; // j
    cout << typeid(float [10]).name() << endl; // A10_f
    cout << typeid(int [10]).name() << endl; // A10_i
    cout << typeid(int* [10]).name() << endl; // A10_Pi
    cout << typeid(int** [10]).name() << endl; // A10_PPi
    cout << typeid(int(*) [10]).name() << endl; // PA10_i
    cout << typeid(int(*)(float)).name() << endl; // PFifE
    cout << typeid(int(*[10])(float)).name() << endl; // A10_PFifE
    cout << typeid(const char*).name() << endl; // PKc
    cout << typeid(char const*).name() << endl; // PKc
    cout << typeid(char* const).name() << endl; // Pc
    cout << typeid(int&).name() << endl; // i
    cout << typeid(Student).name() << endl; // 7Student

    Human* ph = new Student();
    cout << typeid(ph).name() << endl; // P5Human
    cout << typeid(*ph).name() << endl; // 5Human

    Animal* pc = new Cat();
    cout << typeid(pc).name() << endl; // P6Animal
    // 虚函数表中还有类型信息，typeid会根据虚函数表中的类型信息判断
    cout << typeid(*pc).name() << endl; // 3Cat

    Cat c;
    Dog d;
    bar(&c);
    bar(&d);

    return 0;
}
