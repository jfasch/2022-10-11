#ifndef BAG_COPY_H
#define BAG_COPY_H

#include <vector>
#include <string>
#include <cassert>


class BagCopy
{
public:
    using Item = std::pair<std::string, int>;

    void insert(const Item& item)
    {
        _bag.push_back(item);
    }

    const Item& find_by_int(int key) const
    {
        static const Item notfound("", 0);

        for (const auto& item: _bag)
            if (item.second == key)
                return item;
        return notfound;
    }

    std::size_t remove_by_int(int key)
    {
        std::size_t nremoved = 0;
        auto it = _bag.begin();
        while (it != _bag.end()) {
            if (it->second == key) {
                it = _bag.erase(it);
                nremoved++;
            }
            else 
                ++it;
        }
        return nremoved;
    }

private:
    std::vector<Item> _bag;
};

#endif
