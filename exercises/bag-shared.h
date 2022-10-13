#pragma once

#include <string>
#include <vector>
#include <memory>


class BagShared
{
public:
    using Item = std::pair<std::string, int>;

    void insert(const std::shared_ptr<Item>& item)
    {
        _items.push_back(item);
    }

    void insert(std::shared_ptr<Item>&& item)
    {
        _items.push_back(std::move(item));
    }

    const std::shared_ptr<Item>& find_by_int(int key) const
    {
        for (const auto& item: _items)
            if (item->second == key)
                return item;

        static std::shared_ptr<Item> notfound;
        return notfound;
    }

    std::size_t remove_by_int(int key)
    {
        std::size_t nremoved = 0;
        auto it = _items.begin();
        while (it != _items.end()) {
            if ((*it)->second == key) {
                it = _items.erase(it);
                nremoved++;
            }
            else 
                ++it;
        }
        return nremoved;
    }

private:
    std::vector<std::shared_ptr<Item>> _items;
};
