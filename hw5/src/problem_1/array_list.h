/*
 * OK only to add helper function
 */

#ifndef ARRAY_LIST
#define ARRAY_LIST

#include "list.h"

template<class T>
class ArrayList : public List<T> {
private:
    T *data;
    size_t max_capacity;
    size_t num_of_element;

public:
    ArrayList() = delete;   // disable default constructor

    // constructor
    ArrayList(size_t capacity) : max_capacity(capacity), num_of_element(0) {
        data = new T[capacity];
    }

    ArrayList(const std::vector<T> &other_list) : ArrayList(other_list.capacity()) {
        num_of_element = other_list.size();
        for (size_t i = 0; i < num_of_element; i++) {
            data[i] = other_list[i];
        }
    }

    // copy constructor
    ArrayList(const ArrayList<T> &other_list) : ArrayList(other_list.max_capacity) {
        num_of_element = other_list.num_of_element;
        for (size_t i = 0; i < other_list.num_of_element; i++) {
            data[i] = other_list.data[i];
        }
    }

    // destructor
    virtual ~ArrayList() {
        delete[]data;
    }

    size_t capacity() const override {
        return max_capacity;
    }

    size_t size() const override {
        return num_of_element;
    }

    T &operator[](size_t index) const override {
        if (index >= num_of_element) {
            throw std::out_of_range("index out of range");
        }
        return data[index];
    }

    bool operator==(const ArrayList<T> &other_list) {
        // not comparing capacity as eventually array list can be made capacity irrelevant using dynamic allocation
        if (num_of_element != other_list.num_of_element) {
            return false;
        }
        for (int i = 0; i < num_of_element; i++) {
            if (data[i] != other_list.data[i]) {
                return false;
            }
        }
        return true;
    }

    void push_front(const T &value) override;

    void push_back(const T &value) override;

    void pop_back() override;

    void pop_front() override;

    void remove(T &val) override;

    void merge(const List<T> &other) override;

    void reverse_iterative() override;

    void reverse_recursive() override;

private:
    void shift_left_to(size_t start) {
        for (size_t i = start; i < num_of_element - 1; i++) {
            data[i] = data[i + 1];
        }
    }

    void swap(size_t i, size_t j) {
        T tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }

    //void _reverse_recursive(size_t idx); // use this or add your own below
    void _reverse_recursive(int i, int j);
};

#include "array_list.cpp"

#endif