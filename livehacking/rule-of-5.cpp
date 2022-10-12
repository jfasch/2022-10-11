#include <cstring>
#include <iostream>

using namespace std;


class String
{
public:
    String() = default;
    String(const char* s)
    {
        _s = new char[strlen(s)+1];
        strcpy(_s, s);
    }
    String(const String&) = delete;
    String& operator=(const String&) = delete;
    ~String()
    {
        delete[] _s;
    }

    const char* c_str() const { return _s; }

private:
    char* _s = 0;
};

int main()
{
    String s("hallo");
    return 0;
}
