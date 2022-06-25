#include "problem_2.h"

/*
 * homework
 */
void Sorter::bubble_sort(int *data, int length) {
    // add your work
    if(data == nullptr || length < 2){
        return;
    }
    //using 2 for loop and check the i and j index every time
    //do the swap if the current index is greater than the next index
    for(int i = 1; i < length ; i++){
        for(int j = 0; j < length-1; j++){
            if(*(data+i) < *(data+j)){
                int temp = *(data+i);
                *(data+i) = *(data+j);
                *(data+j) = temp;
            }
        }
    }
}

void Sorter::swap(int *data, int i, int j) {
    // add your work if this function is needed
}