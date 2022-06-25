#include "problem_1.h"

/*
 * homework
 * DO NOT MODIFY THE FUNCTION SIGNATURE (NAME, PARAMETERS)
 */
int Searcher::binary_search(const int *data, int length, int target) {
    // add your work
    if(data == nullptr || length < 1){
    return -1;
    }
    int left = 0, mid = 0;
    int right = length -1;
    //compare the middle pivot with target
    //if target greater than middle pivot, make the middle pivot become
    //the new left pivot, right otherwise.
    while(left <= right){
        mid = (left + right)/2;
        if(*(data+mid) == target){
            return mid;
        }else if(target < *(data+mid)){
            right = mid -1;
        }else {
            left = mid +1;
        }
    }
    return -1;
}