#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    fstream fs("seek.txt", ios::in|ios::out);
    fs << "0123456789";
    cout << fs.tellp() << endl;
    cout << fs.tellg() << endl;

    fs.seekp(-3, ios::cur);
    fs << "XYZ";
    fs.seekg(3, ios::beg);
    string s;
    fs >> s;
    cout << s << endl;
    fs.clear();
    fs.seekp(ios::beg);
    fs << "ABC";


    return 0;
}
