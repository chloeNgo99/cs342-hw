<img src="https://user-images.githubusercontent.com/252020/171264166-344df444-3ffc-4ab9-8054-9dffe8261253.png"
     alt="hand"
     width="40%" />
     
## (20pt) Possible Parentheses

### 1.1 The Function (15pt)

Given a positive integer n, how many possible valid parentheses could there be? Say we use "(" and ")" pair.

For example:

When n is 1, there is only one, "()".

When n is 2, there are two, "()()" and "(())".

When n is 3, there are "(())()", "()()()", "((()))", so on. 

How about when n is 15?

In this problem, let's write the code that does this:

```c++
void CatalanNumberSolver::possible_parenthesis(size_t n, std::vector<std::string> &result) {
    /*
     * TODO: homework
     */
}
```

Requirements:

- This is to be done with recursion
- O(1) space (not using any buffer such as vector/array/stack/queue/map) 
- No loop of any kind is permitted.

This is yet another backtracking recursive problem. Also on [LeetCode](https://leetcode.com/problems/generate-parentheses/).

This problem has a lot of similarity with the permutation and Soduku solver, and be careful, it is very easy to overthink. Try it yourself for a few hours and if nothing comes up, research some solution and understand it. The code in the right implementation is all beauty with recursion. 

### 1.2 The Test (5pt)

Add your test to validate cases when n is 1,2,3. This is to be added in

```c++
TEST(problem_1, your_test) {
    /*
     * TODO: homework
     * Add test for possible parentheses size up to 3
     */
    ASSERT_TRUE(false); // remove this when homework is done
}
```

This should be done by simply listing out the input and expected outputs in literal strings, and use a loop to test each cases. 

In additon, another test is provided already. 

```c++
TEST(problem_1, possible_parentheses) {...}
```

Usually this problem can be validated with just n=1,2,3 cases by writing out all the expect solutions in string literals such as "()()". Not for us 342ers. Instead, the test is written here to be able to validate *any* size. Larger sizes may take longer to run but it will finish if you have a better computer. Best part is we human doesn't have to spell out all those literals. Take a read of how the testing is written, and write a section of comments in the test code explaining the testing logic. 
