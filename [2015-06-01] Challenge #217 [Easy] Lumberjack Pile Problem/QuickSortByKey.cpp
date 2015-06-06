/* 
 * File:   QuickSortByKey.cpp
 * Author: sammy
 * 
 * Created on June 6, 2015, 1:00 PM
 */

#include "QuickSortByKey.h"

QuickSortByKey::QuickSortByKey() {
}

void QuickSortByKey::sort(std::vector<node> inputArr) {

    if (inputArr.size() == 0)
    {
        return;
    }
    toSort = inputArr;
    length = inputArr.size();
    quickSort(0, length - 1);
}

void QuickSortByKey::quickSort(int lowerIndex, int higherIndex) {

    int i = lowerIndex;
    int j = higherIndex;
    // calculate pivot card, we will use the middle of the array
    int pivot = toSort[lowerIndex+(higherIndex-lowerIndex)/2].value;

    // Split array into 2
    while (i <= j) {
        //Find number from left side of array > pivot
        while (toSort[i].key < pivot) {
            i++;
        }
        //find a number from right side of array < pivot
        while (toSort[j].key > pivot) {
            j--;
        }
        //Exchange numbers and incriment to next position
        if (i <= j) {
            swapNum(i, j);

            i++;
            j--;
        }
    }
    // call quickSort recursively
    if (lowerIndex < j)
        quickSort(lowerIndex, j);
    if (i < higherIndex)
        quickSort(i, higherIndex);
}

void QuickSortByKey::swapNum(int i, int j) {
    node temp = toSort[i];
    toSort[i] = toSort[j];
    toSort[j] = temp;
}