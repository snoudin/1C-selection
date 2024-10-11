#include <gtest/gtest.h>
#include "src/cli.hpp"

TEST(Purification, Test_1) {
    ASSERT_EQ(purify("abcd!     a5vй"), std::vector<std::string>({"abcd", "a5vй"}))
}
