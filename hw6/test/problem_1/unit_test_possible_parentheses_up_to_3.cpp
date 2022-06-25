#include "problem_1/catalan_number_solver.h"
#include "unit_test_possible_parentheses.h"
#include "unit_test_utils.h"


TEST(problem_1, your_test) {
    /*
     * TODO: homework
     * Add test for possible parentheses size up to 3
     */
    std::vector<std::string> expect0 = {""};
    std::vector<std::string> results0;
    CatalanNumberSolver::possible_parenthesis(0, results0);
    ASSERT_EQ(results0, expect0);
    std::vector<std::string> expect1 ={"()"};
    std::vector<std::string> results1;
    CatalanNumberSolver::possible_parenthesis(1, results1);
    ASSERT_EQ(results1, expect1);
    std::vector<std::string> expect2 ={"(())","()()"};
    std::vector<std::string> results2;
    CatalanNumberSolver::possible_parenthesis(2, results2);
    ASSERT_EQ(results2, expect2);
    std::vector<std::string> expect3 ={"((()))", "(()())", "(())()", "()(())", "()()()"};
    std::vector<std::string> results3;
    CatalanNumberSolver::possible_parenthesis(3, results3);
    ASSERT_EQ(results3, expect3);
}
