#include "linked_stack.h"

template<typename T>
void reverse_stack_recursively(Stack<T> &stack) {
    /*
     * TODO: homework
     */
    if(stack.is_empty()){
        return;
    }
    //pop all the element out of the stack
    //store the value in the recursive call
    T temp = stack.peek();
    stack.pop();
    reverse_stack_recursively(stack);
    //after pop all the value out, start adding to the stack
    insert(stack, temp);
}

template<typename T>
void insert(Stack<T> &stack, T top) {
    //repeat the same step, but this time insert the value to the stack
    //in reverse order
    if (stack.is_empty()) {
        stack.push(top);
        return;
    }
    T temp = stack.peek();
    stack.pop();

    insert(stack, top);
    stack.push(temp);
}