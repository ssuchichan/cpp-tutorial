#include <iostream>
#include <unistd.h>
#include <ctime>
#include <iomanip>
#include <set>
using namespace std;

ostream& datetime(ostream& os) {
    time_t t = time(nullptr);
    tm* local = localtime(&t);

    return os << '[' <<
        setfill('0') <<
        local->tm_year + 1900 << '-' <<
            setw(2) << local->tm_mon+1 << '-' <<
            setw(2) << local->tm_mday << ' ' <<
            setw(2) << local->tm_hour << ':' <<
            setw(2) << local->tm_min << ':' <<
            setw(2) << local->tm_sec <<']';
}

ostream& red(ostream& os) {
    return os <<"\033[;;31m";
}

ostream& def(ostream& os) {
    return os << "\033[0m";
}

int main() {
    cout << red << datetime << def << "open failed" << endl;
    sleep(1);
    cout << red << datetime << def << "alloc failed" << endl;
    sleep(1);
    cout << red <<  datetime << def << "create process failed" << endl;

    return 0;
}
