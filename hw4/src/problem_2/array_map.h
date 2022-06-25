#pragma once

#include <vector>
#include "entry.h"
#include "map.h"
#include <iostream>
#include "../problem_3/list/array_list.h"

template<class KeyType, class ValueType>
class ArrayMap : public Map<KeyType, ValueType> {
private:
    static const int DEFAULT_CAPACITY = 10;
    Entry<KeyType, ValueType> **entries;
    int capacity;
    int count;

    void delete_entry(Entry<KeyType, ValueType> *node) {
        if (node == nullptr) {
            return;
        }
        delete_entry(node->next);
        delete node;
    }

    int hashFunc(KeyType key) const {
        return (int) key % capacity;
    }

public:

    ArrayMap() : ArrayMap(DEFAULT_CAPACITY) {}

    ArrayMap(int capacity) : capacity(capacity), count(0) {
        // () at the end initialize all values to nullptr
        entries = new Entry<KeyType, ValueType> *[capacity]();
    }


    ArrayMap(const std::vector<std::pair<KeyType, ValueType>> &map_data) : ArrayMap(map_data.size()) {
        for (auto &pair: map_data) {
            put(pair.first, pair.second);
        }
    }

    ArrayMap(const ArrayMap &other_map) : ArrayMap(other_map.capacity) {
        for (int i = 0; i < capacity; i++) {
            Entry<KeyType, ValueType> *ptr = other_map.entries[i];
            while (ptr != nullptr) {
                put(ptr->key, ptr->value);
                ptr = ptr->next;
            }
        }
    }

    ~ArrayMap() {
        for (int i = 0; i < capacity; i++) {
            if (entries[i] == nullptr) {
                continue;
            }
            delete_entry(entries[i]);
        }
        delete[]entries;
    }

    int size() override {
        return count;
    }

    bool is_empty() override {
        return count == 0;
    }

    void put(KeyType const &key, ValueType const &value) override {
        /*
         * TODO: homework
         */
        int hashed_key = hashFunc(key);
        Entry<KeyType, ValueType> *curr = entries[hashed_key];
        Entry<KeyType, ValueType> *prev = NULL;

        while(curr != nullptr && curr->key != key){
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            Entry<KeyType, ValueType> *temp = new Entry<KeyType, ValueType>(key, value);
            if(prev == NULL){ // first insert in the bucket
                entries[hashed_key] = temp;
            }else{
                prev->next = temp;
            }
            count++;
        }else{
            //if the code ever gets in to this point, it means the curr value
            //has the matching key, and it's not null
            //update the current value to the new value
            curr->set_value(value);
        }
    }

    bool get(KeyType const &key, ValueType &value) const override {
        int hashed_key = hashFunc(key);
        Entry<KeyType, ValueType> *ptr = entries[hashed_key];
        while (ptr != nullptr) {
            if (ptr->key == key) {
                value = ptr->value;
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            if (entries[i] == nullptr) {
                printf("[%d] = null\n", i);
                continue;
            }
            Entry<KeyType, ValueType> *ptr = entries[i];
            printf("[%d] = {", i);
            while (ptr != nullptr) {
                printf("(%d, %f)", ptr->key, ptr->value);
                ptr = ptr->next;
            }
            printf("}\n");
        }
    }

    bool remove(KeyType const &key) override {
        /*
         * TODO: homework
         */
        int hashed_key = hashFunc(key);
        Entry<KeyType, ValueType> *curr = entries[hashed_key];
        Entry<KeyType, ValueType> *prev = NULL;

        while(curr != NULL && curr->key != key ){
            prev = curr;
            curr = curr->next;
        }
        //after the while loop if curr still == null which mean there are also no matching key
        if(curr == NULL){
            return false;
        }else { //curr is now the match key
            if(prev == NULL){ //curr is the first bucket
                entries[hashed_key] = curr->next;
            }else{//curr is somewhere in the linked list
                //disconnect prev with the curr node and set prev to the curr->next node
                prev->next = curr->next;
            }
            delete curr;
        }
        count--;
        return true;
    }

    bool operator==(const ArrayMap &other_map) const {
        if (count != other_map.count) {
            return false;
        }

        for (int i = 0; i < other_map.capacity; i++) {
            Entry<KeyType, ValueType> *other_ptr = other_map.entries[i];
            while (other_ptr != nullptr) {
                ValueType val;
                if (!get(other_ptr->key, val) || val != other_ptr->value) {
                    return false;
                }
                other_ptr = other_ptr->next;
            }
        }
        return true;
    }

    bool operator!=(const ArrayMap &other_map) const {
        return !(other_map == *this);
    }

    void key_set(List<KeyType> &keys) {
        for (int i = 0; i < capacity; i++) {
            if (entries[i] == nullptr) {
                continue;
            }
            Entry<KeyType, ValueType> *ptr = entries[i];
            while (ptr != nullptr) {
                keys.push_back(ptr->key);
                ptr = ptr->next;
            }
        }
    }
};