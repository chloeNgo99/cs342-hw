<img src="https://user-images.githubusercontent.com/252020/171102003-d75bf46c-da78-4feb-ab23-23b0ce049e29.png" width="40%">


## (20pt) Merkle Tree KV Store (Extra Credit)

```
"Ugh..another data structure!", a student sighed. 

"But wait, this one is pretty fun.", says the instructor.

"But you say that about all of them!", a student replies.
```

### Merkle Tree

[Merkle tree](https://en.wikipedia.org/wiki/Merkle_tree), also known as a hash tree, is a tree data structure where each node contains the hash of it's children. One of the key benefits is that it allows quick detect changes, usually used for data validation. Interestingly, We have actually been using Merkle tree throughout the semester and that's in Git. 

Here are some popular application of Merkle tree

- [Git and Bitcoin](https://medium.com/geekculture/understanding-merkle-trees-f48732772199). While we are on it, [here](https://youtu.be/ig5E8CcdM9g) is a great video about how Git works internally. Fancinating talk!
- [IPFS](https://docs.ipfs.io/concepts/merkle-dag/). Also a [good video](https://youtu.be/YIc6MNfv5iQ) here.

### Hashing

For this example, we need to do fancier hashing than using % as we did in the hashtable. [Sha256](https://medium.com/@shahharsh961/sha-265-algorithm-f49184e782d2) is our choice here. An [existing Sha256 implementation](https://create.stephan-brumme.com/hash-library/) is used. The internal working mechanism of Sha256 is not required for this homework. In short, it converts a string into another random string very efficiently with less chance of collision. If you are curious how it works, use [this test](https://github.com/a-teaching-goose/2022-342-sprint-6/blob/main/test/problem_3/unit_test_sha256.cpp) as a manual. 

### Task 1: Implement the Left(...) function

To get a sense of how Merkle Tree could help speed up data validation, this task creates a [key-value store](https://github.com/a-teaching-goose/2022-342-sprint-6/blob/0e917e8ef9a28a8da5fc3cc4cd26cd8549a9979f/src/problem_3/merkle_kv.h#L17), aka "KV store", that carries a Merkle Tree to help detects whether any value of any key has changed. The store itself keeps its data in a std::map 

```c++
    std::map<std::string, std::string> map_sorted;
```

While a Merkle Tree is created for all the key value pairs and stored in a vector

```c++
    std::vector<std::string> meta_tree;
```

And yes, tree data structure is not always stored with pointers. Another example of array-ly stored tree is [heap](https://medium.com/swlh/data-structures-heaps-b039868a521b). In fact our Merkle Tree is stored in a very similiar way, and one task for you is to implement the following function that locates the left tree from a parent node:

```c++
int MerkleKV::left(int node_idx) {
    /*
     * TODO: homework
     */
}
```

As a reference, the corresponding *right* function is already provided. The *left* function would be only a few small changes away.

```c++
int MerkleKV::right(int node_idx) {
    int num_tree_nodes = meta_tree.size() - 1;
    return num_tree_nodes - ((num_tree_nodes - node_idx) * 2 + 1);
}
```

All tests provided, and as usual, upon finish, all tests should pass.



### Task 2: Performance test

To see the benefit of fast validation from using Merkle Tree in action, a performance test is provided. Here's an excerp:

```c++
TEST(problem_3, diff_keys_compare_time_large_kv) {
    std::vector<MerkleKVDiffTestCase> test_cases;
    const int SIZE = 32768;
    diff_key_test_cases_large_kv_no_diff(test_cases, SIZE); // later to convert to time comparison
    diff_key_test_cases_large_kv(test_cases, SIZE); // later to convert to time comparison
...
...
```

There are two test cases here. The first one is a comparison of two identical KV stores of size 32768, and measuring the running time. The second one does the same but with two KV stores that have different values for the same keys. The running time of both cases are compared with the "primitive solution" where there's no Merkle tree and therefore each key-value pair in the store have to be iteratively compared.

On the instructor's laptop, this is the result:

```
time: merkle(11), primitive(115584) ms
time: merkle(87), primitive(98878) ms
```

11ms vs 115584ms, and 87ms vs 98878ms. It's obvious that with the help of the Merkle tree, it takes a lot less time to check whether some values have changed in a key-value store. The task for you is to provide an analysis explaining WHY this is the case. 

In specifc, in your analysis, discuss the reason why our store validation takes less time using Merkle tree. 

This is to be added as a block of comments in the code right below the *diff_keys_compare_time_large_kv* test. Do not add any new file.
