## (30pt) Binary Search

### Implement The Binary Search (20pt)

Write a function to perform binary search in an ascendingly (small to large) **sorted** integer array. 

The binary search function signature is defined [here](https://github.com/a-teaching-goose/2022-342-sprint-1/blob/main/src/problem_1.h#L7):

```c++
    static int binary_search(const int *data, int length, int target);
```

It takes an integer as the number to search, and returns the first **index** of the input value if found. -1 if target is not found. 

Why is -1 okay to be used as the indication of "nothing found"?

For example:

- Searching 6 in array [1, 3, 6, 8, 9] should return 2 because number 6 appears at index 2.
- Searching 9 in array [1, 3, 6, 8, 9] should return 4.
- Searching 7 in array [1, 3, 6, 8, 9] should return -1 because 7 is not found in this array.
- Searching 6 in array [1, 3, 6, 6, 9] should return 2 because the first 6 appears at index 2.

Tests are provided, but one of the marked tests needs some additional work to pass validation. 

Binary search will be discussed in class as part of the search problem. If you need help, [here](https://www.geeksforgeeks.org/binary-search/) is a good start. Note that binary search can be implemented with or without recursion. If you are comfortable with recursion already, feel free to use it. Otherwise for-loop would be just fine. In fact, which method do you think is faster? (you can answer this in your code as a comment if you want to)

When the homework is done, your code should pass all the tests that come from with assignment.

### Fix The Tests (10pt)

Tests are given for this task, however, one of the tests is missing something, and will fail (memory leak) even if your binary search is correct. This failure would definitely show up when Nop the cat (github PR robot) inspects your code. 

<img width="80%" alt="image" src="https://user-images.githubusercontent.com/252020/159639333-aad68023-f68a-4eee-be05-0aeee62a9e9a.png">

And you are to fix it so all GitHub tests pass.
