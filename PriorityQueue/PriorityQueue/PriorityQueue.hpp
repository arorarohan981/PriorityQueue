//
//  PriorityQueue.hpp
//  PriorityQueue
//
//  Created by Rohan Arora on 07/11/21.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp
#include <iostream>
#include <stdio.h>
#include <memory>
#include <list>

namespace mylib{
    
template <typename T>
class PriorityQueue{
private:
    std::list<T> listOfData;
    size_t queueSize;
    int dataCount{-1};
    
public:
    /*Returns True if the PriorityQueue is Empty or else returns False .*/
    bool isEmpty() const;
    
    
    /*Returns True if the PriorityQueue is Full or else returns False   */
    bool isFull() const;
    
    
    /*Enqueue's the Data according to its priority in the Queue.Returns True if the data is inserted Successfully in the Queue or else returns false .*/
    bool enQueue(T data);
    
    /*Removes the Element with highest Priority from the Queue.*/
    bool deQueue();
    
    /* Returns Copy of Element with highest Priority .*/
    T peek() const;
    
    
    /* Prints the Queue with elements in higher priority first to low priority  */
    void print() const;
};

}

#endif /* PriorityQueue_hpp */
