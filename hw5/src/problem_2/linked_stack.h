/*
 * DO NOT TOUCH THIS FILE
 */

#pragma once

#include "stack.h"
#include <stdexcept>      // std::out_of_range
#include "../problem_1/linked_list.h"

template<class T>
class LinkedStack : public Stack<T> {
private:
    LinkedList<T> data;
public:
    LinkedStack(const LinkedStack<T> &another_stack) : data(another_stack.data) {};

    LinkedStack();

    bool is_empty() const override {
        return data.size() == 0;
    };

    bool push(const T &) override;

    bool pop() override;

    T peek() const override;

    bool operator==(const LinkedStack<T> &) const;

    bool operator!=(const LinkedStack<T> &) const;
};

template<class T>
bool LinkedStack<T>::push(const T &val) {
    data.push_front(val);
    return true;
}

template<class T>
bool LinkedStack<T>::pop() {
    data.pop_front();
    return true;
}

template<class T>
T LinkedStack<T>::peek() const {
    if (data.size() == 0) {
        throw std::out_of_range("empty stack");
    }
    return data[0];
}

template<class T>
LinkedStack<T>::LinkedStack() = default;

template<class T>
bool LinkedStack<T>::operator==(const LinkedStack<T> &another_stack) const {
    return data == another_stack.data;
}

template<class T>
bool LinkedStack<T>::operator!=(const LinkedStack<T> &another_stack) const {
    return another_stack != *this;
}