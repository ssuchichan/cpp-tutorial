#ifndef INC_CLOCK_H
#define INC_CLOCK_H

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <iomanip>

using namespace std;

class Clock {
public:
    Clock(time_t now) {
        tm* local = localtime(&now);
        m_hour = local->tm_hour;
        m_min = local->tm_min;
        m_sec = local->tm_sec;
    }

    void run() {
        while(true) {
            show();
            tick();
        }
    }
private:
    void show() {
        cout << '\r'
            << setfill('0') << setw(2) <<  m_hour << ':'
            << setfill('0') << setw(2) << m_min << ':'
            << setfill('0') << setw(2) << m_sec << flush;
    }
    void tick() {
        sleep(1);
        if (++m_sec % 60 == 0) {
            m_sec = 0;
            if (++m_min % 60 == 0) {
                m_min = 0;
                if (++m_hour % 24 == 0) {
                    m_hour = 0;
                }
            }
        }
    }

    int m_hour;
    int m_min;
    int m_sec;
};


#endif
