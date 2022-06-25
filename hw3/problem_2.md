<img width="368" alt="image" src="https://user-images.githubusercontent.com/252020/165891673-4eff8c7f-1d42-435d-843d-de035dde5980.png">

## (45pt) LinkedList

### Abstract Data Type (ADT)

This section about ADT is the same in the last homework. Read [here](https://github.com/a-teaching-goose/CSS342A-2022-Spring/blob/main/homeworks/homework-2/problem_2.md#abstract-data-type-adt) if you need some reminder.

ArrayList is provided from last homework. 

### The Task

The task here is to implement a List that stores data in a single linked list. Call it "LinkedList". The name may sound familiar if you've written in Java before because there's an [LinkedList ADT in Java](https://docs.oracle.com/javase/7/docs/api/java/util/LinkedList.html). Similar concepts. Except in the Java LinkedList it's a double linked list.

All the functions to be completed is in [src/problem_2.cpp](https://github.com/a-teaching-goose/2022-342-sprint-3/blob/main/src/problem_2). Here's list of functions to finish, with 5pt per function:

<img width="322" alt="image" src="https://user-images.githubusercontent.com/252020/165891328-b0b467be-9609-4523-8079-e287bc61add8.png">

Comparing to the last homework, an additional **reverse** function is to be implemented for both ArrayList and LinkedList. The reverse function for linkedlist is to be implement iteratively, meaning no recursion is allowed.

The cool part is the test for both reverse functions (in ArrayList and LinkedList) is the same piece of code:

<img width="439" alt="image" src="https://user-images.githubusercontent.com/252020/165891548-92eb1406-2046-407e-9284-78568771b399.png">

Talking about the rule of DRY ("Don't Repeat Yourself")! This is where C++ "late binding" shines!

### Test As A Manual

All tests are given, and they also serve as an instruction manual. Use the given unit tests to understand the behavior of the functions to be implemented.
