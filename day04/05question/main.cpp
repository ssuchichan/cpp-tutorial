#include <iostream>
using namespace std;

class Student;

class Teacher {
public:
    /*
    void educate(Student* student) {
        student->ask("什么事this指针？", this);
        cout << "回答：" << m_answer << endl;
    }
    */
    void educate(Student* student);

    void reply(const string& answer) {
        m_answer = answer;
    }
private:
    string m_answer;
};

class Student {
public:
    void ask(const string& question, Teacher* teacher) {
        cout << "问题: " << question << endl;
        teacher->reply("不知道！");
    }
};

// 将educate放到Student的面
void Teacher::educate(Student* student) {
    student->ask("什么事this指针？", this);
    cout << "回答：" << m_answer << endl;
}

int main() {
    Teacher t;
    Student s;
    t.educate(&s);

    return 0;
}
