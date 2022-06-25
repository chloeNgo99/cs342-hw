#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    /*
     * TODO: homework
     * add element to the front of the linked list
     * create a new node to hold the new value
     * then linked the new node to the head list
     */
    num_of_element++;

    ListNode<T> *newNode = new ListNode<T>(value);
    newNode->next = head->next;
    head->next = newNode;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    /*
     * TODO: homework
     * add element to the end of the linked list
     * loop through the head list till we hit the last node
     * then linked it to the new value node
     */
    num_of_element++;
    ListNode<T> *newNode = new ListNode<T>(value);
    ListNode<T> *curr = head;
    if(head == NULL){
        head = newNode;
        return;
    }
    while(curr->next){
        curr = curr->next;
    }
    curr->next = newNode;
}

template<class T>
void LinkedList<T>::pop_back() {
    /*
     * TODO: homework
     * loop through the head list till we hit the last node
     * delete the last node and set the previous node to null
     */
    if(num_of_element == 0){
        return;
    }

    ListNode<T> *prev = head;
    while(prev->next->next != NULL){
        prev = prev->next;
    }
    delete prev->next;
    prev->next = NULL;

    num_of_element--;
}

template<class T>
void LinkedList<T>::pop_front() {
    /*
     * TODO: homework
     * move the head node to the second node and delete the
     * first node
     */
    if(num_of_element == 0){
        return;
    }
    ListNode<T> *temp = head;
    head = head->next;
    delete temp;
    num_of_element--;
}

template<class T>
void LinkedList<T>::remove(T &val) {
    /*
     * TODO: homework
     * loop through the whole list, find all occurrents that has
     * the same value as val and delete them
     */
    if(num_of_element == 0){
        return;
    }
    ListNode<T> *curr = head;
    while(curr->next){
        if(curr->next->val == val){
            num_of_element--;
            ListNode<T> *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }else{
            curr = curr->next;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    /*
     * TODO: homework
     * since other list and head list are already in ascending order
     * use while loop to do the comparision and add the node to
     * newly created merge list
     */
    auto &other = (LinkedList<T>&) ot;
    ListNode<T> *node = other.head->next;
    ListNode<T> *list = head->next;
    ListNode<T> *merge = new ListNode<T>();
    ListNode<T> *curr = merge;

    while (node != nullptr && list != nullptr){
        if(node->val < list->val){
            curr->next = new ListNode<T>(node->val);
            node = node->next;
            num_of_element++;
        }else{
            curr->next = new ListNode<T>(list->val);
            list = list->next;
        }
        curr = curr->next;
    }
    while(node != nullptr){
        curr->next = new ListNode<T>(node->val);
        node = node->next;
        curr = curr->next;
        num_of_element++;
    }
    while(list != nullptr){
        curr->next = new ListNode<T>(list->val);
        list = list->next;
        curr = curr->next;
    }
    //delete every node in the head list (this is why we love JAVA :'< )
    ListNode<T> *p0 = head, *p1 = head->next;
    if (p1 == nullptr) {
        delete p0;
    }else{
        while (p1 != nullptr) {
            delete p0;
            p0 = p1;
            p1 = p1->next;
        }
        delete p0;
    }
    head = merge;
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    /*
     * TODO: homework
     * use 3 pointers approach to go through the list
     * and switch the direction of each node
     */
    if(head->next->next == nullptr){
        return;
    }
    ListNode<T> *prev = nullptr;
    ListNode<T> *curr = head->next;
    ListNode<T> *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = prev;
}
