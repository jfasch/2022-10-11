class TakesOwnership
{
public:
    // attention: only pass dynamically allocated memory!!
    explicit TakesOwnership(const char* s) 
    {
        delete[] s;
    }
};

void f(const TakesOwnership&)
{
    // ...
}

int main()
{
    const char* s = new char[]{"hallo"};
    f(TakesOwnership(s));
    return 0;
}
