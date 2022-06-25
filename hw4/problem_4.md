<img src="https://user-images.githubusercontent.com/252020/167758663-db2d99f5-2e8c-41cd-9dae-59a62266339d.png"
     width="50%" />


### (10pt) Write a function to perform binary search recursively in an ascendingly sorted integer array. ###

We did the binary search in homework 1. This time let's do it again but put our recursion idea to some use. 

The binary search function takes an integer to find, and returns an **index** of the input value if found. -1 if target is not found.

For example:

- Searching 6 in array [1, 3, 6, 8, 9] should return 2 because number 6 appears at index 2.
- Searching 9 in array [1, 3, 6, 8, 9] should return 4.
- Searching 7 in array [1, 3, 6, 8, 9] should return -1 because 7 is not found in this array.
- Searching 6 in array [1, 3, 6, 6, 9] should return 2 because the first 6 appears at index 2.

Your test can assume input array is correctly sorted.

The following function signature cannot be changed 

```c++
int binary_search(int *data, int length, int target);
```

So for recursion you might need to add a "helper" function to perform the recursion on.
