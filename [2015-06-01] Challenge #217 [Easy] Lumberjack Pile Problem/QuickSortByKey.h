/* 
 * File:   QuickSortByKey.h
 * Author: sammy
 *
 * Created on June 6, 2015, 1:00 PM
 */

#ifndef QUICKSORTBYKEY_H
#define	QUICKSORTBYKEY_H
#include <vector>
#include "node.h"
class QuickSortByKey {
public:
    QuickSortByKey();
    void sort(std::vector<node> inputArr);
    std::vector<node> toSort; //Array to sort
private:
     
     int  length;   //Length of Array
     void swapNum(int i, int j);
     void quickSort(int lowerIndex, int higherIndex) ;
};

#endif	/* QUICKSORTBYKEY_H */

