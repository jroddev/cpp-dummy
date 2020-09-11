#include "dummy/dummy.h"
#include "dummy-user-defined.h"

#include <gtest/gtest.h>


TEST(DummyUserDefinedType, CanCreateUserDefinedTypes) {
    auto result = dummy<MyType>();
    EXPECT_EQ(result.name.size(), 8);
    EXPECT_GE(result.age, 0);
    EXPECT_LE(result.age, 100);
}
