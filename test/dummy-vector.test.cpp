#include "dummy/dummy.h"
#include "dummy/dummy-vector.h"
#include "dummy-user-defined.h"
#include <gtest/gtest.h>

TEST(DummyVector, CreatesSpecifiedCount) {
    auto results = dummyVector<int>(10, dummy<int>);
    EXPECT_EQ(results.size(), 10);
}

TEST(DummyVector, RandomisesContents) {
    auto results = dummyVector<int>(10, dummy<int>);
    auto unique = std::set(begin(results), end(results));
    EXPECT_EQ(results.size(), unique.size());
}

TEST(DummyVector, CreatesCollectionWithCustomGenerator) {
    auto intGenerator = [](){return dummy<int>(50, 200);};
    auto results = dummyVector<int>(10, intGenerator);
    for(const auto result : results) {
        EXPECT_GE(result, 50);
        EXPECT_LE(result, 200);
    }
}

TEST(DummyVector, CanCreateUserDefinedTypes) {
    auto results = dummyVector<MyType>(15, dummy<MyType>);
    EXPECT_EQ(results.size(), 15);
    for(const auto& result: results) {
        EXPECT_EQ(result.name.size(), 8);
        EXPECT_GE(result.age, 0);
        EXPECT_LE(result.age, 100);
    }
}