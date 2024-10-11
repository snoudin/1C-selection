#include <gtest/gtest.h>
#include "cli.hpp"

TEST(Purification, Test_1) {
    ASSERT_EQ(purify("abcd!     a5v"), std::vector<std::string>({"abcd", "a5v"}));
}
