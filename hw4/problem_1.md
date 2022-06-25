<img src="https://user-images.githubusercontent.com/252020/167759795-8d8dbebf-8a43-4e81-bfba-28901f2b93a1.png"
     alt="hand"
     width="40%" />
     
## (20pt) Print A Single Linked List In Reverse Order

Going backward is fun sometimes.

### Going Reverse

Let's write a function that prints a single linked list backward to the screen. 

Linkedlist is straightforward to traverse from front to end. But going backward is not as natural. There are two ways generally:

1. Using a stack
2. Using recursion

Both stack and recursion are typically good for "doing something else before coming back". Both methods are open to use in this task. However, usage of any kind of array/vector/list/queue is not allowed.  

### Testing

By now you should already concluded that the instructor never shuts up about testing. ¯\\\_(ツ)\_/¯ 

Well, if you haven't, here's another proof.

In this task, we need to test a function that's supposed to print string to the screen. For automated testing like what we have done so far, it's not easy (if possible at all) to get the "actual" values to compare with the "expect", because the result of our function is actually on the screen. 

Instead of resorting to "eyeball" testing back again, this task will explore the idea of the "[Dependency Inversion Principle](https://deviq.com/principles/dependency-inversion-principle)", or shorted as "DI". The idea is "high level modules should not depend on low level modules; both should depend on abstractions.". In our case, std::cout or printf is the "low level modules", and having dependency on these (calling them from our function) makes our code tightly coupled with these function. Software hates coupling.

Another thing to note is, what we are testing is the output of the reverse visit of the single linked list. Printing is to show the result, not a logic for us to test. 

As a solution with DI, we change our function to only rely on an abstraction:

```c++
class Printer {
public:
    virtual void print(std::string val) = 0;
}
```

And now our reverse print functions takes an interface as parameter.

```c++
    void reverse_print(Printer &print) const;
```

This is the "abstraction" of printing in the form or an "interface" class (a class with only pure virtual functions). Depending on whether we are running it or testing it, different implementations of the Print interface can be provided. In normal use, the print would actually print to the screen while in testing, it'll print into a "buffer" for us to do validation.

In this task, in addition to implement the reverse print function, we also need to implement two print functions, one to pass test, and the other to actually print to screen. So for this homework:

1. the unit test should pass.
2. run the main function in the src folder, and you should also see the correct screen printout.  




