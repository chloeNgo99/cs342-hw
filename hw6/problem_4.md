<img width="30%" alt="image" src="https://user-images.githubusercontent.com/252020/171221986-94791b45-a81a-4d0a-a8bb-b262c1d4a4a1.png">

## (50pt) Final Project

Important note here: **This counts as 50% of the final exam points**.

[TL;DR](https://www.howtogeek.com/435266/what-does-tldr-mean-and-how-do-you-use-it/): A summary of tasks to do

1. Answer the study questions about B-tree
2. Finish the *find_by_name* function
3. Run performance test and write analysis for single query
4. Run performance test and write analysis for range query

Answers for 1,3 and 4 are to be written in the *test/problem_4/report* file. All tests should pass upon completion.

Note: the performance test could take a long time to run. Advise to not change the test size in the code you submit to github. You can play with different sizes on your machine all you want. Change them back to the original settings before you commit and push.

### Storing large amount of data

The story here is that we need to store a large number of user records. Each record contains username, age and a set of hobbies. (What's your favorite hobby by the way?)

The data entry is modelled as the following:

```c++
class Record {
private:
    unsigned id;
    std::string name;
    unsigned age;
    std::unordered_set<std::string> hobbies;
...
...
}
```

When a user data is inserted into our data store, a self monotonically increasing *id* is assigned to the record with the user data. For simplicity, the id here matches the array index id. There could be cases where they differ but it's out of the scope for our little example here.

User data is stored in an std::vector as follows:

```c++
    std::vector<Record> table;
```

This vector or "collection" of data altogether is called a table. 

"Why a vector?" you ask? It goes to one of the key benefit of using vector comparing to other data structures we've covered: **Random Access**. 

### Fast Search

The purpose of storing all these data is so we could search them by a certain way. For example, search by name, age or hobbies. And with large amount of records, we want the search to be as fast as possible. As [discussed in lecture](https://youtu.be/fy7bFpptVco?t=388), additional data structures are needed to speed up the search, similar to the index section at the end of a book. It helps you quickly locate where a certain word or phrase appears in the book without having to go through it page by page, which could take hours.

Here's an illustration from the lecture slide:

<img src="https://user-images.githubusercontent.com/252020/171221019-dcfa7a32-46a8-4ef5-bef1-7ee77ac945cd.png" width="40%">

And an index is modelled as this "interface":

```c++
template<typename KeyType>
class Index {

public:
    virtual void insert_record(KeyType key, unsigned record_id) = 0;

    virtual void find_records(KeyType key, std::vector<unsigned> &found_record_ids) = 0;

    virtual void find_records_by_age_range(KeyType lower_bound,
                                           KeyType upper_bound,
                                           std::vector<unsigned> &found_record_ids) = 0;
};
```

Regardless how an index is implemented, the input to an idex is a key or a range of keys, and the output is a set of record *id* that matches the given key. Note there could be multiple matches, and therefore the output is stored in a vector. Using the output ids from the index, the corresponding records can be quickly located. Quickly how? Because records are stored in a vector which supports O(1) random access using. 

### Index with B-Tree (20pt)

So how do we implement the index? There are many options. Remember, the goal of the index is allowing quick search. Among the ADTs we've covered this semester, hashtable and binary search trees are the ones that fit that profile. To push things to another level, instead of using good'o binary search tree, we'll opt for a fancier version search tree: B-Tree. 

Two indexes are implemented and provided in our code base. One with hashtable (std::std::unordered_map) and the other with B-tree (using an [existing implementation](https://github.com/Kronuz/cpp-btree)). Here's an illustration from our lecture slides.

<img width="257" alt="image" src="https://user-images.githubusercontent.com/252020/171229584-c04a24e5-3f0d-4de5-be63-d670f9363bf8.png">

Your task is to conduct some self-study and understand the following:

- How B-Tree works? (focus on searching in an B-Tree)
- How does B-Tree compares to a binary search tree?
- Why could B-Tree be helpful for data indexing?
- What's the search complexity of B-Tree? And how does it affect search efficiency (time) comparing to hashtable?
- B-Tree provides advantage over hashtable for range query. For example, 

Add your study result in the *report* file.

Here are a few good materials for you to start:

- [B-Trees and B+ Trees. How they are useful in Databases](https://youtu.be/aZjYr87r1b8)
- [A visualization to play around with a B-tree](https://www.cs.usfca.edu/~galles/visualization/BTree.html)
- [Some study on database storage internals](https://kousiknath.medium.com/data-structures-database-storage-internals-1f5ed3619d43)

We have google so find more materials. For this study, focus on high-level mechanism. No need to understand every single details.

### Finish Missing Code (20pt)

In our DB implementation, finish the following function:

```c++
bool GasWorksDB::find_by_name(const std::string &name, std::vector<Record> &found_records) {
    if (enable_index) {
        std::vector<unsigned> record_ids;
        index_group->get_name_index().find_records(name, record_ids);

        if (record_ids.empty()) {
            return false;
        }

        for (auto id: record_ids) {
            found_records.push_back(table[id]);
        }
        return true;
    }

    /*
     * TODO: homework
     */
    return 0;   // remove this when homework is done
}
```

Test should pass upon finish. The missing part to be finished is searching through the record vector for those that matches the name. There are similar functions such as *find_by_age* for your reference. Don't over think this one. It's *that* simple.

### Performance Test (10pt)

For this section, we evaluate how much an index could really help with performance. 

#### Single Query
In this test, the same search (same key) is performed using hashtable index, B-Tree index and simply in the record vector. 

The test is this:

```c++
TEST(problem_4, perf_single_entry_query) {

    const int MIN_HOBBY_COUNT = 5;
    const int HOBBY_TYPE_COUNT = 50;
    const int AGE_MAX = 300;

    const int MAX_TABLE_SIZE = 5000;
    const int STEP_TABLE_SIZE = 1000;

    for (unsigned table_size = 0; table_size <= MAX_TABLE_SIZE; table_size += STEP_TABLE_SIZE) {
        run_index_perf_single_entry_query(table_size, MIN_HOBBY_COUNT, HOBBY_TYPE_COUNT, AGE_MAX);
    }
}
```

Here are some prelimary result:

```
1000,56,55,82
2000,48,48,116
3000,45,44,227
4000,30,31,161
5000,51,51,288
```

First column is table size and the rest are running time in microseconds in the sequence of hashtable index, B-tree index and direct search in vector.

Run this with larger table size (change only STEP_TABLE_SIZE and MAX_TABLE_SIZE), and write an analysis of what you observes with your running output.

#### Range Query
In this test, we are search a range of keys instead of a single one.

The test code is this:

```c++
TEST(problem_4, perf_range_query) {

    const int MIN_HOBBY_COUNT = 5;
    const int HOBBY_TYPE_COUNT = 50;
    const int AGE_MAX = 300;

    const int MAX_TABLE_SIZE = 50000;
    const int STEP_TABLE_SIZE = 10000;

    for (unsigned table_size = 0; table_size <= MAX_TABLE_SIZE; table_size += STEP_TABLE_SIZE) {
        run_index_perf_range_query(table_size, MIN_HOBBY_COUNT, HOBBY_TYPE_COUNT, AGE_MAX);
    }
}
```

Different from the single-key search, age used. To observe a more dramatic comparison, the range of search is set in *run_index_perf_range_query* to 

```
    unsigned age_lower_bound = 50;
    unsigned age_upper_bound = 51;
```

Here are some prelimary result:

```
10000,1527,722,877
20000,2941,1374,1585
30000,5022,2431,3335
40000,6633,2788,3185
50000,7522,3435,4167
```

First column is table size and the rest are running time in microseconds in the sequence of hashtable index, B-tree index and direct search in vector. Notice here the B-tree time is smaller than both hashtable index and direct search. This shows the benefit of the B-tree for range query.

Similarly, run this with larger table size (change only STEP_TABLE_SIZE and MAX_TABLE_SIZE), and write an analysis of what you observes with your running output. 

### Trivia

What's with the name of the database *GasWorksDB*?

The entire code was written on the day where I took a bike ride to gasworks park in Seattle. There was [a band on top of the hill](https://youtu.be/RzzsI6qEDsI) and weather was nice. The name of our DB is just to remember that good day. :)
