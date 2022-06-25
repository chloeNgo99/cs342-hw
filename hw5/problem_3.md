<img src="https://user-images.githubusercontent.com/252020/169449130-8ff2b42f-a573-46de-93d0-a0d73e7a5ed7.png" width="20%">

## (25pt) Sudoku Solver

Finally we get to write a Sudoku solver. Recursion, more specificially, backtracking is to be used. Pretty similiar idea with quiz-3.

Sudoku is written as a class. Here's a partial code of the class:

<img src="https://user-images.githubusercontent.com/252020/169449701-083b275c-8360-4ff7-8c0c-2c7e968937d8.png" width="40%">

The actual Sudoku data is stored in the *challenge* array:

```c++
    int *challenge;
```    

The Sudoku board is a 2D matrix, while here it's stored in a 1D array using [row major](https://en.wikipedia.org/wiki/Row-_and_column-major_order). Basically, it'll store one row after another inside this array.


The solver function is

```c++
bool Sudoku::solve() {
    /*
     * TODO: homework
     */
}
```

This is to be done with recursion so feel free to add a helper function. One of provided as an optional suggestion. When you do, just remember to add the function declaration in *sudoku.h* too. 

All tests are provided, including one that attempts [one of the hardest Sudoku problems in the world](https://www.telegraph.co.uk/news/science/science-news/9359579/Worlds-hardest-sudoku-can-you-crack-it.html).

For 5 extra credit, add at least one more test case to challenge your Sudoku solver.
