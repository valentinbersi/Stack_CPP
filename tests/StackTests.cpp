#include "gtest/gtest.h"
#include "Stack.hpp"

class StackTests : public ::testing::Test {
protected:
    Stack<int> stack{};
    int element{};
};

// last() is tested here.
TEST_F(StackTests, Add) {
    stack.add(2);
    EXPECT_EQ(stack.last(), 2);

    stack.add(1);
    stack.add(3);
    EXPECT_EQ(stack.last(), 3);
}

TEST_F(StackTests, Remove) {
    stack.add(1);
    stack.add(3);

    element = stack.remove();
    EXPECT_EQ(element, 3);
    EXPECT_EQ(stack.last(), 1);
}

TEST_F(StackTests, RemoveHannlesEmptyQueue) {
    EXPECT_THROW(stack.remove(), EmptyException);
}

TEST_F(StackTests, Empty) {
    EXPECT_TRUE(stack.empty());

    stack.add(1);
    EXPECT_FALSE(stack.empty());

    stack.remove();
    EXPECT_TRUE(stack.empty());
}

TEST_F(StackTests, Size) {
    EXPECT_EQ(stack.size(), 0);

    stack.add(1);
    stack.add(2);
    stack.add(3);
    EXPECT_EQ(stack.size(), 3);

    stack.remove();
    EXPECT_EQ(stack.size(), 2);
}

TEST_F(StackTests, LastHandlesEmptyQueue) {
    EXPECT_THROW(stack.last(), EmptyException);
}