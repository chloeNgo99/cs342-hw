#include "problem_2.h"

template<class T>

void ArrayList<T>::push_front(const T &value) {

    /*
     * divide the problem into 2 case
     * 1st - create new array T with the capacity is one more larger than
     * the original one if number of element == number of max cap
     * 2nd - create new array T with the capacity equal the
     * original one if number of element < number of max cap
     * then add the new value at the beginning of array arr
     * then loop through the data list to fill up the rest of the value into array arr
     */

    if(num_of_element == max_capacity){
        T *arr = new T[max_capacity+1];
        arr[0] = value;
        int j = 1;
        for(int i = 0; i < num_of_element; i++){
            arr[j++] = data[i];
        }
        num_of_element++;
        max_capacity++;
        delete[] data;
        data = arr;
    }else{
        T *arr = new T[max_capacity];
        arr[0] = value;
        int j = 1;
        for(int i = 0; i < num_of_element; i++){
            arr[j++] = data[i];
        }
        num_of_element++;
        delete[] data;
        data = arr;
    }
}

template<class T>
void ArrayList<T>::push_back(const T &value) {

    /*
     * add new value at the end of the list and update the num_of_element
     */
    if(num_of_element < max_capacity){
        data[num_of_element] = value;
        num_of_element++;
    }
}

template<class T>
void ArrayList<T>::pop_back() {

    /*
     * delete the last element from the data array
     * just simply decrease number of element by 1
     */
    if(num_of_element == 0){
        return;
    }
    data[num_of_element--];
}

template<class T>
void ArrayList<T>::pop_front() {

    /*
     * use for loop to move every element in the array up by 1
     * and update the number of element
     */
    if(num_of_element == 0){
        return;
    }
    for(int i = 0; i < num_of_element -1; i++){
        T next = data[i+1];
        data[i] = next;
    }
    data[num_of_element--];
}

template<class T>
void ArrayList<T>::remove(T &val) {

    /*
     * create new array T
     * use for loop to go through the data list
     * if data[value] not equal T val, add them to the new array arr
     * set number of element and the max capacity equal to new array size
     */

    T *arr = new T[max_capacity];
    int count = 0;
    for(int i = 0; i < num_of_element; i++){
        if(data[i] != val){
            arr[count] = data[i];
            count++;
        }
    }
    delete[] data;
    data = arr;
    num_of_element = count;
    max_capacity = count;

}

/*
 * merge in ascending order
 */
template<class T>
void ArrayList<T>::merge(const List<T> &ot) {

    /*
     * create newArray T
     * use while loop to check if i and j < the data and other_list length
     * use if statement to compare the values of the 2 list
     * add the smaller one into the newArr
     * after the first while loop is done
     * fill the rest of the values from data or other_list to the newArr
     * update num_of_element and max_capacity equal to the newArr length
     */

    auto &other_list = (ArrayList<T> &)ot;
    int j = 0;
    int i = 0;
    int k = 0;
    int dataLength = num_of_element;
    int listLength = other_list.size();
    T *newArr = new T[dataLength + listLength];

    while(i < dataLength && j < listLength){
        if(data[i] < other_list[j]){
            newArr[k] = data[i];
            i++;
        }else{
            newArr[k] = other_list[j];
            j++;
        }
        k++;
    }
    if(i < dataLength){
        while(i < dataLength){
            newArr[k] = data[i];
            i++;
            k++;
        }
    }else{
        while(j < listLength){
            newArr[k] = other_list[j];
            j++;
            k++;
        }
    }
    delete[] data;
    data = newArr;
    num_of_element = k;
    max_capacity = k;
}