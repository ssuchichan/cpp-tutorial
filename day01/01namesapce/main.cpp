#include <iostream>

float g_balance = 1234;

namespace abc {
    float g_balance = 0.0;

    void save(float money) {
        g_balance += money;
    }

    void withdraw(float money) {
        g_balance -= money;
    }

    void show() {
        std::cout << g_balance << std::endl;
        std::cout << ::g_balance << std::endl;
    }
}

namespace cbc {
    float g_balance = 0.0;

    void save(float money) {
        g_balance += money;
    }

    void withdraw(float money) {
        g_balance -= money;
    }

    void show() {
        std::cout << g_balance << std::endl;
    }
}

namespace abc {
    void foo() {
        std::cout << "abc::foo" << std::endl;
    }
    void bar();
}
void abc::bar() {
    std::cout << "abc::bar" << std::endl;
}


namespace ns1 {
    int x = 100;
    namespace ns2 {
        int x = 200;
        namespace ns3 {
            int x = 300;
        }
    }
}

int main() {
    abc::show();
    abc::save(10000);
    abc::withdraw(5000);
    abc::show();

    cbc::save(8000);
    cbc::withdraw(2000);
    cbc::show();

    abc::foo();
    abc::bar();

    /*
    using namespace abc; // 名字空间指令（全部可见）
    foo();
    bar();
    */
    using abc::foo; // 名字空间声明（部分可见）
    foo();
    abc::bar();

    std::cout << ns1::x << std::endl;
    std::cout << ns1::ns2::x << std::endl;
    std::cout << ns1::ns2::ns3::x << std::endl;
    // 名字空间别名
    namespace ns_three = ns1::ns2::ns3;
    std::cout << ns_three::x << std::endl;

    return 0;
}
