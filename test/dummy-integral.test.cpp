#include "dummy/dummy.h"

#include <gtest/gtest.h>

TEST(DummyInt, CreatesDifferentIntegers) {
    auto a = dummy<int>();
    auto b = dummy<int>();
    EXPECT_NE(a, b);
}

TEST(DummyInt, CreatesIntegersWithinRange) {
    auto min = 123;
    auto max = 299;
    for(auto i = 0; i < 100; i++) {
        auto result = dummy<int>(min, max);
        EXPECT_GE(result, min);
        EXPECT_LE(result, max);
    }
}

TEST(DummyLong, CreatesDifferentLong) {
    auto a = dummy<long>();
    auto b = dummy<long>();
    EXPECT_NE(a, b);
}

TEST(DummyLong, CreatesLongsWithinRange) {
    auto min = 123L;
    auto max = 299L;
    for(auto i = 0; i < 100; i++) {
        auto result = dummy<long>(min, max);
        EXPECT_GE(result, min);
        EXPECT_LE(result, max);
    }
}