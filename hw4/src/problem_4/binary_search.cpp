#include "binary_search.h"

int search(int *list, int left, int right, int target) {

    if(left > right){
        return -1;
    }
    int mid = (left + right)/2;
    if(list[mid] == target){
            return mid;
    }
    if(target < list[mid]){
            return search(list,left, mid-1, target);
    }else{
            return search(list,mid+1, right, target);
    }
}

int binary_search(int *data, int length, int target) {
    /*
     * TODO: homework
     * For recursion, you might need to add another function to recurse on
     */
    if(data == nullptr || length < 1){
        return -1;
    }
    int left = 0;
    int right = length-1;
    int result = search(data, left, right, target);
    return result;
}



