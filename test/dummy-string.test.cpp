#include "dummy/dummy.h"

#include <gtest/gtest.h>


TEST(DummyString, CreatesDifferentStrings) {
    auto a = dummy<std::string>(10);
    auto b = dummy<std::string>(10);
    EXPECT_NE(a, b);
}

TEST(DummyString, CreatesStringOfCorrectLength) {
    EXPECT_EQ(dummy<std::string>(10).length(), 10);
    EXPECT_EQ(dummy<std::string>(1).length(), 1);
    EXPECT_EQ(dummy<std::string>(5).length(), 5);
    EXPECT_EQ(dummy<std::string>(30).length(), 30);
    EXPECT_EQ(dummy<std::string>(0).length(), 0);
}