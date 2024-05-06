#include <iostream>
using namespace std;

class Phone {
public:
    Phone(const string& no) : m_no(no) {
        cout << "Phone::Phone(): " << this << endl;
    }
    ~Phone() {
        cout << "Phone::~Phone()" << endl;
    }
    void call(const string& no) const {
        cout << m_no << " call " << no << endl;
    }
private:
    string m_no;
};

class Player {
public:
    Player(const string& media) : m_media(media) {
        cout << "Player::Player(): " << this << endl;
    }
    ~Player() {
        cout << "Player::~Player()" << endl;
    }
    void play(const string& clip) const {
        cout << m_media << " play " << clip << endl;
    }
private:
    string m_media;
};

class Computer {
public:
    Computer(const string& os) : m_os(os) {
        cout << "Computer::Computer(): " << this << endl;
    }
    ~Computer() {
        cout << "Computer::~Computer()" << endl;
    }
    void run(const string& app) const {
        cout << m_os << " run " << app << endl;
    }
private:
    string m_os;
};

class SmartPhone : public Phone, public Player, public Computer {
public:
    SmartPhone(const string& no, const string& media, const string& os) : Phone(no), Player(media), Computer(os) {
        cout << "SmartPhone::SmartPhone(): " << this << endl;
    }
    ~SmartPhone() {
        cout << "SmartPhone::~SmartPhone()" << endl;
    }
    void gps() const {}
};



int main() {
    SmartPhone sp("13910110072", "MP4", "Android");
    sp.call("62332018");
    sp.play("high");
    sp.run("qq");
    cout << sizeof(sp) << endl;
    //编译器会做偏移，指向对应的子对象
    Phone* phone = &sp;
    Player* player = &sp;
    Computer* computer = &sp;
    cout << phone << ", " << player << ", " << computer << endl;

    // 编译器会做偏移，指向起始位置
    SmartPhone* psp = static_cast<SmartPhone*>(computer);
    cout << psp << endl;

    // 只做类型转换，不做偏移计算
    psp = reinterpret_cast<SmartPhone*>(computer);
    cout << psp << endl;

    return 0;
}
