/* 
 * File:   main.cpp
 * Author: Sammy Roberts | Github: github.com/kekeoki
 *
 * Created on June 6, 2015, 10:24 AM
 */

#include <cstdlib>
#include <iostream>
#include "QuickSort.h"
#include <vector>
#include <fstream>
#include "node.h"
using namespace std;

int main(int argc, char** argv) {
    int size;               //INPUT - size of storage area sizexsize grid
    int numLogs;            // INPUT - number of logs to place
    ifstream myInput;       // INPUT - file to get input from
    QuickSort q;            // PROCESSING - Sorts map by value
    QuickSort qByKey;       // PROCESSING - Sorts map by key
    vector<node> sortedMap; // OUTPUT - Stored key value pairs

    //INPUT
    myInput.open("input1.txt", std::ifstream::in);
    myInput >> size;    //Get size of storage area
    myInput >> numLogs; //Get number of logs to emplace
    
    int lcv = 0;
    
    while(!myInput.eof())                   //get input from file
    {
        int tempKey = lcv;                  // Storage location on the grid
        int tempValue;                      // Value of the stack of wood
        myInput >> tempValue;               //gets input from file
        node tempNode(tempKey,tempValue);   // add to temp node
        sortedMap.push_back(tempNode);      //push onto map
    }
    //PROCESSING
    q.sort(sortedMap);                      //Sort Map
    
    //Add to the logs and resort
    while(numLogs != 0)
    {
        std::cout << numLogs << endl;
        q.toSort[0].value++; //incrimient current piles value
        numLogs--;            // subtract from num Logs
        q.sort(q.toSort);    //resort
    } //TODO increase efficentcy by implementing quicker sort for already ordered map
    //OUTPUT
    
    qByKey.sort(q.toSort); // sort by key
    for(int lcv = 0; lcv < (size*size); lcv++)
    {
        //output by until a multiple of size is reached then end the line
        std::cout << qByKey.toSort[lcv].value << " "; 
        if ((lcv+1)%size == 0)
        {
            std::cout << std::endl;
        }
    }
    return 0;
}


