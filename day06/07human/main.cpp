#include <iostream>
using namespace std;

class Human {
public:
    Human(const string& name = "", int age = 0) : m_age(age), m_name(name) {}
    void who() const {
        cout << m_name << ", " << m_age << endl;
    }
    void eat(const string& food) const {
        cout << "eat " << food << endl;
    }
    void sleep(int hour) const {
        cout << "sleep " << hour << " hours" << endl;
    }

protected:
    string m_name;
    int m_age;
};


class Student: public Human {
public:
    Student(const string& name = "", int age = 0, int no = 0) {
        m_name = name;
        m_age = age;
        m_no = no;
    }

    void learn(const string& course) const {
        cout << "learn " << course << endl;
    }

    // 继承不会改变作用域，不会和父类的who构成重载
    // 父子类同名标识符构成隐藏关系
    void who() const {
        cout << m_name << ", " << m_age << ", " << m_no << endl;
    }
private:
    int m_no;
};

class Teacher : public Human {
public:
    Teacher(const string& name = "", int age = 0, double salary = 10000)
        : m_salary(salary) // 写在初始化表里的成员必须是自己的，不能是继承的
        , Human(name, age)
        {}
    void who() const {
        cout << m_name << ", " << m_age << ", " << m_salary << endl;
    }
    void teach(const string& course) const {
        cout << "teach " << course << endl;
    }
private:
    double m_salary;
};


int main() {
    Student s("zhangfei", 35, 1001);
    s.who();
    s.Human::who(); // 显式调用父类的函数
    s.eat("pancake");
    s.sleep(2);
    s.learn("C++");
    cout << "--------------------------------" << endl;
    Human* phuman = &s; // 隐式转换
    phuman->who();
    phuman->sleep(3);
    phuman->eat("banana");
    cout << "--------------------------------" << endl;
    // 编译器只看类型
    Student* pstudent = static_cast<Student*>(phuman);
    pstudent->who();
    pstudent->learn("C");
    pstudent->sleep(4);
    pstudent->eat("apple");
    cout << "--------------------------------" << endl;
    Teacher t("zhaoyun", 25, 20000);
    t.who();
    t.eat("steak");
    t.sleep(5);
    t.teach("Unix");

    return 0;
}
