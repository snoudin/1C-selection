#include <gtest/gtest.h>
#include "cli.hpp"
#include "tree.hpp"

TEST(Purification, Test_1) {
    ASSERT_EQ(purify(""), std::vector<std::string>(0));
}

TEST(Purification, Test_2) {
    ASSERT_EQ(purify_string("abc.7845235,"), "abc7845235");
}

TEST(Purification, Test_3) {
    ASSERT_EQ(purify("abcd!   :  a5v,."), std::vector<std::string>({"abcd", "a5v"}));
}

TEST(SimpleSearch, Test_1) {
    Tree searcher;
    searcher.add({"abc", "abd", "abd"});
    ASSERT_EQ(searcher.process("a"), "abd");
}

TEST(Search, Sample) {
    Tree searcher;
    searcher.add({"pelun", "pelun", "pehrr"});
    ASSERT_EQ(searcher.process("pe"), "pelun");
    ASSERT_EQ(searcher.update("h"), "pehrr");
    searcher.add({"pehem", "pehem", "pehem"});
    ASSERT_EQ(searcher.process("pe"), "pehem");
    ASSERT_EQ(searcher.update("hem"), "pehem");
}
