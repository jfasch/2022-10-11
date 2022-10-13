#include "bag-shared.h"

#include <gtest/gtest.h>

TEST(bag_shared_suite, find_by_int_ok)
{
    BagShared bag;
    bag.insert(std::make_shared<BagShared::Item>("something", 42));

    auto item2 = std::make_shared<BagShared::Item>("anything", 666);
    bag.insert(item2);

    ASSERT_EQ(item2.use_count(), 2);

    auto item = bag.find_by_int(42);
    ASSERT_NE(item, nullptr);
    ASSERT_EQ(item->first, "something");
    ASSERT_EQ(item->second, 42);
}

TEST(bag_shared_suite, find_by_int_nok)
{
    BagShared bag;
    bag.insert(std::make_shared<BagShared::Item>("something", 42));
    bag.insert(std::make_shared<BagShared::Item>("anything", 666));

    auto item = bag.find_by_int(7);
    ASSERT_EQ(item, nullptr);
}

TEST(bag_shared_suite, remove_by_int_ok)
{
    BagShared bag;
    bag.insert(std::make_shared<BagShared::Item>("something", 42));
    bag.insert(std::make_shared<BagShared::Item>("anything", 666));

    std::size_t nremoved = bag.remove_by_int(42);
    ASSERT_EQ(nremoved, 1);
}

TEST(bag_shared_suite, move_and_copy_possible)
{
    BagShared bag;
    auto item1 = std::make_shared<BagShared::Item>("something", 42);
    auto item2 = std::make_shared<BagShared::Item>("something", 42);

    // copy
    bag.insert(item1);
    ASSERT_NE(item1.get(), nullptr);

    // move
    bag.insert(std::move(item2));
    ASSERT_EQ(item2.get(), nullptr);
}
