/*
 * DO NOT TOUCH THIS FILE
 */

#pragma once

template<class T>
class Stack {
public:
    virtual bool is_empty() const = 0;

    virtual bool push(const T &) = 0;

    virtual bool pop() = 0;

    virtual T peek() const = 0;

    virtual ~Stack() {};
};