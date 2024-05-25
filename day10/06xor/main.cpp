#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int _xor(const char* src, const char* dst, unsigned char key)
{
    ifstream ifs(src, ios::binary);
    if (!ifs)
    {
        cout << "open source file failed" << endl;
        return -1;
    }

    ofstream ofs(dst, ios::binary);
    if (!ofs)
    {
        cout << "open dest file failed" << endl;
        return -1;
    }

    char buf[1024];
    // read没读满就会失败
    while (ifs.read(buf, sizeof(buf)))
    {
        for (int i = 0; i < sizeof(buf); ++i)
        {
            buf[i] ^= key;
        }
        ofs.write(buf, sizeof(buf));
    }
    if (!ifs.eof())
    {
        cout << "read source file failed" << endl;
        return -1;
    }

    for (int i = 0; i< ifs.gcount(); ++i)
    {
        buf[i] ^= key;
    }
    ofs.write(buf, ifs.gcount());
    ofs.close();
    ifs.close();

    return 0;
}

int encrypt(const char* plain, const char* cipher)
{
    srand(time(nullptr));
    unsigned char key = rand() % 256;
    if (_xor(plain, cipher, key) == -1)
    {
        return -1;
    }
    cout << "key: " << int(key) << endl;
    return 0;
}

int decrypt(const char* cihper, const char* plain, unsigned char key)
{
    return _xor(cihper, plain, key);
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "encrypt: " << argv[0] << " <plain> <cipher>" << endl;
        cout << "decrypt: " << argv[0] << " <cipher> <plain> <key>" << endl;
        return -1;
    }

    if (argc < 4)
    {
        return encrypt(argv[1], argv[2]);
    }
    else
    {
        return decrypt(argv[1], argv[2], atoi(argv[3]));
    }
}
