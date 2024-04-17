#include <iostream>
using namespace std;

class Student {
public:
    Student(const string &name = "anonymous", int age = 18);
    // 在类内实现的成员函数缺省就是内联的，如果是类外实现如需要内联，则需显式加上inline关键字
    inline void who();
    /*
    Student(const string& name, int age) {
        m_name = name;
        m_age = age;
    }
    void who() {
        cout << "I am " << m_name << ", " << m_age << " years old" << endl;
    }
     */
    void learn(const string& course) {
        cout << "I am learning " << course << endl;
    }
    void setName(const string& name) {
        if (name == "250") {
            cout << "invalid name" << endl;
            return;
        }
        m_name = name;
    }
    void setAge(int age) {
        if (age <= 0) {
            cout << "invalid age" << endl;
            return;
        }
        m_age = age;
    }
    void foo(Student& s) {
        // 可以访问同一个类的对象的非公有部分
        s.m_name = "250";
    }
private:
    string m_name;
    int m_age;
};

// 类的声明与实现分开
Student::Student(const string& name, int age) {
    m_name = name;
    m_age = age;
}
void Student::who() {
    cout << "I am " << m_name << ", " << m_age << " years old" << endl;
}

int main() {
    Student s1("zhangfei", 20);
    s1.setName("250");
    s1.setAge(-10);
    s1.who();
    // s1.setName("zhangfei");
    // s1.setAge(30);
    // s1.who();
    s1.learn("C++");

    Student s2("zhaoyun", 20);
    s1.foo(s2);
    s2.who();

    Student s3("guanyu", 40);
    s3.who();

    // 编译器会认为在声明函数
    // Student s4();
    Student s4; // 别加()
    s4.who();

    Student sa[3];
    for (Student& s : sa) {
        s.who();
    }
    Student sc[3] = {
            Student("zhangfei", 18),
            Student("zhaoyun", 17),
            Student("guanyu", 30)
    };
    for(auto& s: sc) {
        s.who();
    }


    Student* ps = new Student;
    ps->who();
    auto ps2 = new Student(); // 前面有new编译器会不会认为是声明函数
    ps2->who();
    auto ps3 = new Student("hello", 10);
    ps3->who();
    delete ps;
    delete ps2;
    delete ps3;

    Student* parr1 = new Student[3];
    delete[] parr1;

    auto parr2 = new Student[3]{Student("hello"),
                        Student("world"),
                        Student("haha")};
    delete[] parr2;

    return 0;
}
