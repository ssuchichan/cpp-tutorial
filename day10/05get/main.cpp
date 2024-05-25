#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifs("get.txt");
    char c;
    while((c = ifs.get()) != EOF)
    {
        cout << c;
    }
    cout << "------------------------------------" << endl;
    ifs.clear();
    ifs.seekg(ios::beg);

    while(ifs.get(c))
    {
        cout << c;
    }
    cout << "------------------------------------" << endl;

    ifs.clear();
    ifs.seekg(ios::beg);
    char sz[4];
    while(ifs.get(sz, sizeof(sz), '\n'))
    {
        cout << sz;
        if (ifs.peek() == '\n')
        {
            ifs.ignore();
        }
    }
    cout << "------------------------------------" << endl;
    ifs.clear();
    ifs.seekg(ios::beg);
    char s2[256];
    while(ifs.getline(s2, sizeof(s2), '\n'))
    {
        cout << s2 << endl;
    }

    cout << "------------------------------------" << endl;
    ifs.clear();
    ifs.seekg(ios::beg);
    c = ifs.get();
    cout << c << endl;
    ifs.putback(c);
    c = ifs.get();
    cout << c << endl;
    c = ifs.get();
    cout << c << endl;
    ifs.close();

    fstream fs("put.txt", ios::out);
    for (char c = ' '; c <= '~'; ++c)
    {
        fs.put(c);
    }
    fs.clear();

    return 0;
}
