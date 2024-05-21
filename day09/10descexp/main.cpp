#include <iostream>
using namespace  std;

void bar()
{
    throw -3;
}

class A
{
public:
    void foo()
    {
        throw -1;
    }
    ~A()
    {
        // 内部消化
        try
        {
            bar();
        }
        catch (int& ex)
        {
            cout << "bar err: " << ex << endl;
        }
        catch (...)
        {

        }
        // 不要从析构函数中主动抛出异常
        // throw -2;
    }
};

int main()
{
    A a;
    try
    {
        a.foo();
    }
    catch (int& ex)
    {
        cout << "foo err: " << ex << endl;
        return -1;
    }
    cout << "ok" << endl;

    return 0;
}
