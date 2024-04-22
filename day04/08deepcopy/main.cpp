#include <iostream>
using namespace std;

class Integer {
public:
    Integer(int val): m_val(new int(val)) {}

    Integer(const Integer& that) {
        m_val = new int(*that.m_val);
    }

    Integer& operator=(const Integer& that) {
        if (&that != this) { // 避免自赋值
            /*
            delete m_val; // 释放旧资源
            m_val = new int(*that.m_val); // 分配新资源，拷贝新内容
            */
            Integer temp(that);
            swap(m_val, temp.m_val);
        }

        return *this; // 返回自引用
    }

    ~Integer() {
        delete m_val;
    }

    void print() const {
        cout << *m_val << endl;
    }

private:
    int* m_val;
};


int main() {
    Integer t1(100);
    t1.print();

    Integer t2(t1);
    t2.print();

    Integer t3(300);
    t2 = t3; // i2.operator=(t3)
    t2.print();


    return 0;
}

