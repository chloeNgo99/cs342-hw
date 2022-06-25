#include "catalan_number_solver.h"
#include <iostream>

void backtrack(size_t n, int count, std::string &str, std::vector<std::string> &result){

    /*
    if(list.length() == n* 2){
        return list;
    }
    if(open < n){
        backtrack(n, open + 1, close ,list += "(");
    }
    //close < open because we dont want to have close parenthesis places before the open one
    if(close < open){
        backtrack(n, open, close +1, list += ")");
    }
     */
    if(n == 0){
        //push the new string into the vector and return when there is no more space
        result.push_back(str);
        return;
    }
    //if there are still empty places, push open parenthesis into the string
    if(n > count){
        str.push_back('(');
        backtrack(n-1, count + 1, str, result);
        str.pop_back();
    }
    //we want the close parenthesis to always push after the open one
    if(count > 0){
        str.push_back(')');
        backtrack(n-1, count -1, str, result);
        str.pop_back();
    }
}

void CatalanNumberSolver::possible_parenthesis(size_t n, std::vector<std::string> &result) {
    /*
     * TODO: homework
     */

    std::string list;
    backtrack(n*2, 0, list, result);
    //result.push_back(list);
}

size_t CatalanNumberSolver::catalan_number(size_t n) {
    if (n < 2) {
        return 1;
    }
    size_t numerator = 1, denominator = 1;

    for (size_t k = 2; k <= n; k++) {
        numerator *= (n + k);
        denominator *= k;
    }

    return numerator / denominator;
}
