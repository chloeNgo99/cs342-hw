/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "problem_2/linked_stack.h"
#include "problem_2/reverse_stack.h"

template<typename T>
void test_stack_reversal() {
    LinkedStack<T> stack;

    reverse_stack_recursively(stack);   // no T specified
    ASSERT_TRUE(stack.is_empty());

    const size_t SIZE = 10;
    for (size_t i = 1; i < SIZE; i++) {
        size_t number_of_elements = i;
        for (T j = 0; j < number_of_elements; j++) {
            stack.push(j);
        }
        reverse_stack_recursively(stack);
        for (T j = 0; j < number_of_elements; j++) {
            ASSERT_EQ(j, stack.peek());
            stack.pop();
        }
        ASSERT_TRUE(stack.is_empty());
    }
}