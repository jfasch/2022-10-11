#pragma once

#include <string>
#include <vector>
#include <memory>


class BagUnique
{
public:
    using Item = std::pair<std::string, int>;

    void insert(std::unique_ptr<Item>&& item)
    {
        _items.push_back(std::move(item));
    }

    const Item* find_by_int(int key) const
    {
        for (const auto& item: _items)
            if (item->second == key)
                return item.get();
        return nullptr;
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
    std::vector<std::unique_ptr<Item>> _items;
};
