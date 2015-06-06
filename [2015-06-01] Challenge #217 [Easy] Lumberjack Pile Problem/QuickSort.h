/* 
 * File:   QuickSort.h
 * Author: sammy
 *
 * Created on June 6, 2015, 10:29 AM
 */

#ifndef QUICKSORT_H
#define	QUICKSORT_H
#include <vector>
#include "node.h"
class QuickSort {
public:
    QuickSort();
    void sort(std::vector<node> inputArr);
    std::vector<node> toSort; //Array to sort
private:
     
     int  length;   //Length of Array
     void swapNum(int i, int j);
     void quickSort(int lowerIndex, int higherIndex) ;
};

#endif	/* QUICKSORT_H */

