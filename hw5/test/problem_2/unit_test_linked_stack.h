/*
 * DO NOT MAKE ANY CHANGES
 */

#pragma once

#include "problem_2/linked_stack.h"
#include "gtest/gtest.h"

template<typename T>
void is_empty_number_type() {
    LinkedStack<T> stack;
    ASSERT_TRUE(stack.is_empty());

    const size_t SIZE = 10;
    for (size_t i = 0; i < SIZE; i++) {
        ASSERT_TRUE(stack.push((T) i));
        ASSERT_FALSE(stack.is_empty());
    }

    for (size_t i = 0; i < SIZE - 1; i++) {
        ASSERT_TRUE(stack.pop());
        ASSERT_FALSE(stack.is_empty());
    }
    ASSERT_TRUE(stack.pop());
    ASSERT_TRUE(stack.is_empty());
}

template<typename T>
void push_pop_peak_number_type() {
    LinkedStack<T> stack;
    const size_t SIZE = 10;
    for (size_t i = 0; i < SIZE; i++) {
        T expect = (T) i;
        ASSERT_TRUE(stack.push(expect));
        ASSERT_FALSE(stack.is_empty());
        ASSERT_EQ(expect, stack.peek());
    }

    for (size_t i = 0; i < SIZE; i++) {
        T expect = (T) (SIZE - i - 1);
        ASSERT_FALSE(stack.is_empty());
        ASSERT_EQ(expect, stack.peek());
        ASSERT_TRUE(stack.pop());
    }
    ASSERT_TRUE(stack.is_empty());
}

template<typename T>
void copy_constructor() {
    const size_t SIZE = 10;
    LinkedStack<T> stack_1;
    LinkedStack<T> stack_2(stack_1);

    for (size_t i = 0; i < SIZE; i++) {
        stack_1.push((T) i);
    }
    ASSERT_TRUE(stack_2.is_empty());

    LinkedStack<T> stack_3(stack_1);
    while (!stack_1.is_empty() && !stack_3.is_empty()) {
        ASSERT_TRUE(stack_1 == stack_3);
        ASSERT_EQ(stack_1.peek(), stack_3.peek());
        stack_1.pop();
        stack_3.pop();
    }

    ASSERT_TRUE(stack_1.is_empty() && stack_3.is_empty());
}
