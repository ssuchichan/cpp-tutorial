#include "student.h"
#include "clock.h"

int main() {
    Student s;
    s.setName("Zhangfei");
    s.setAge(30);
    s.who();
    s.learn("Sun Zi Bing Fa");

    Clock clock(time(NULL));
    clock.run();
    return 0;
}
