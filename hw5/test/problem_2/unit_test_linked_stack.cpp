/*
 * DO NOT MAKE ANY CHANGES
 */

#include "unit_test_linked_stack.h"

TEST(problem_2, is_empty) {
    is_empty_number_type<int>();
    is_empty_number_type<float>();
}

TEST(problem_2, push_pop_peak) {
    push_pop_peak_number_type<int>();
    push_pop_peak_number_type<float>();
}

TEST(problem_2, copy_constructor) {
    copy_constructor<int>();
    copy_constructor<float>();
}

TEST(problem_2, peek_empty) {
    LinkedStack<int> stack;
    EXPECT_THROW(stack.peek(), std::out_of_range);
}