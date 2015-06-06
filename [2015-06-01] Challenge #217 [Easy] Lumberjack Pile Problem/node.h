/* 
 * File:   node.h
 * Author: sammy
 *
 * Created on June 6, 2015, 12:39 PM
 */

#ifndef NODE_H
#define	NODE_H

struct node
{
    int key;
    int value;
    
    node(int k, int v)
    {
        key = k;
        value = v;
    }
};

#endif	/* NODE_H */

