<img width="403" alt="image" src="https://user-images.githubusercontent.com/252020/163451813-37c307f1-f9c9-4f9e-853b-dce85c450c7b.png">


## (50pt) ArrayList

### Abstract Data Type (ADT)

In a programming language, we are often provided some data type such as integer, float, and even class such as in Java and C++. 

An Abstract Data Type (ADT) is a fancy term, but it really just means we can create our own data type. In C++ we can do this by using class.

For example, **List** is a very commonly used data type. Similar to array, a list has a few properties:

- A List contains a linear sequence of elements
- A List has a size and capacity, and capacity can be limited or unlimited
- Each element in the List has an index of 0, 1, 2, etc. 
- New element can be add to the front or back of the List
- Element can be removed from a List
- Lists can be merged into each other

And [here](https://github.com/a-teaching-goose/2022-342-sprint-2/blob/7cecf4283222ba282eaa9aee8123a177b62d0c8f/src/problem_2.h#L8)'s an C++ interface that defines a List ADT:

<img width="30%" alt="image" src="https://user-images.githubusercontent.com/252020/163449901-0b752cac-642b-4ce9-9398-9364b3c81b0f.png">

One thing to note: **There's no mentioning of the type of the element, and how data is stored in a List. This is up to specific implementation of a List to decide.**

### The Task

The task here is to implement a List that stores data in an array. Call it "ArrayList". The name may sound familiar if you've written in Java before because there's an [ArrayList ADT in Java](https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html). Similar concepts.

All the functions to be completed is in [src/problem_2.cpp](https://github.com/a-teaching-goose/2022-342-sprint-2/blob/main/src/problem_2.cpp)

In a later homework, we'll have a chance to implement the same List interface but using a different way for storage. (Care to guess?)

### Test As A Manual

All tests are given, and they also serve as an instruction manual. Together with the comment in the [src/problem_2.h](https://github.com/a-teaching-goose/2022-342-sprint-2/blob/main/src/problem_2.h), use the given unit tests to understand the behavior of the functions to be implemented.
