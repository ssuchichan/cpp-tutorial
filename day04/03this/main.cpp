#include <iostream>
using namespace std;

class User {
public:
    User(const string& m_name = "", int m_age = 0) {
        cout << "构造函数: " << this << endl;
        // 函数的作用域小，会隐藏类相同的变量
        // m_name = m_name;
        // m_age = m_age;
        this->m_name = m_name;
        this->m_age = m_age;
    }
    void print() {
        // 编译器加了this，可以直接用
        cout << this->m_name << ", " << this->m_age << endl;
    }
    /*
    void print(User* this) {
        cout << this->m_name << ", " << this->m_age << endl;
    }
    */

private:
    string m_name;
    int m_age;
};


int main() {
    User user1("zhangfei", 35);
    cout << "user1: " << &user1 << endl;
    user1.print(); // print(&user1);

    User user2("zhaoyun", 25);
    cout << "user2: " << &user2 << endl;
    user2.print(); // print(&user2);


    return 0;
}
