#include <iostream>
using namespace std;
class Date{
public:
    Date(int year, int month, int day) :
        m_year(year),
        m_month(month),
        m_day(day)
        {}

    void print() {
        cout << m_year << '-' << m_month << '-' << m_day << endl;
    }
    int year() { return m_year; }
    int month() { return m_month; }
    int day() { return m_day; }
private:
    int m_year;
    int m_month;
    int m_day;
};

class Student{
public:
    /*
    // 两步：先构造，后赋值
    Student(const string& name = "", int age = 0) {
        cout << "name: " << m_name << endl; // ""
        cout << "age: " << m_age << endl;   // 未定义的值
        m_name = name;
        m_age = age;
    }*/

    // 一步：构造同时就赋值，性能有所提升
    Student(const string& name = "", int age = 0, int year = 2000, int month = 1, int day=1) :
        m_name(name),
        m_age(age),
        m_arr{10,20,30},
        m_birth{2011, 11, 11},
        m_born(year, month, day)
        {}

    void who() {
        cout << m_name << ", " << m_age << ", " << endl;
        for(auto& i:m_arr) {
            cout << i << ' ';
        }
        cout << endl;
        cout << m_birth.year << '-' << m_birth.month << '-' << m_birth.day << endl;
        cout << m_born.year() << '-' << m_born.month() << '-' << m_born.day() << endl;
    }


private:
    // 所有成员变量的定义都是在构造函数中做的，而不是在声明中做的
    // string m_name = "hello";       // ERROR
    // int m_age = 18;                // ERROR
    // int m_arr[3] = { 10, 20, 30 }; // ERROR

    string m_name;
    int m_age;
    int m_arr[3];
    struct {
        int year;
        int month;
        int day;
    } m_birth;
    Date m_born;
};



int main() {
    Student s1("zhengfei", 35);
    s1.who();

    return 0;
}
