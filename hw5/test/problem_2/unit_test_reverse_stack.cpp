/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "unit_test_reverse_stack.h"


TEST(problem_2, stack_reversal) {
    test_stack_reversal<int>();
    test_stack_reversal<float>();
}