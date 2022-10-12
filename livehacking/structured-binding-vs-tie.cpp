#include <map>
#include <iostream>


int main()
{
    std::map<int, int> m;

    // auto /*std::pair<std::map<int, int>::iterator, bool>>*/ rv = m.insert(std::make_pair(1, 2));

    // bool inserted;
    // std::tie(std::ignore, inserted) = m.insert(std::make_pair(1, 2));

    auto [_, inserted] = m.insert(std::make_pair(1, 2));

    if (inserted)
        std::cout << "inserted!" << std::endl;

    return 0;
}
