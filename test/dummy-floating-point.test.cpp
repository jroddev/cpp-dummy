#include "dummy/dummy.h"

#include <gtest/gtest.h>

TEST(DummyFloat, CreatesDifferentFloats) {
    auto a = dummy<float>();
    auto b = dummy<float>();
    EXPECT_NE(a, b);
}

TEST(DummyFloat, CreatesFloatsWithinRange) {
    auto min = 123.F;
    auto max = 299.F;
    for(auto i = 0; i < 100; i++) {
        auto result = dummy<float>(min, max);
        EXPECT_GE(result, min);
        EXPECT_LE(result, max);
    }
}