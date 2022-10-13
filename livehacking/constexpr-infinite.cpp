constexpr int infinite(int start)
{
    return infinite(start+1);
}

int main()
{
    constexpr int result = infinite(1);
    (void)result;
    return 0;
}
