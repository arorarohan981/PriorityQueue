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
#include <exception>
#include <list>

namespace mylib{
    
template <typename T>
class PriorityQueue{
private:
    std::list<T> listOfData;
    size_t queueSize;
    int dataCount{-1};
    
public:
    
    /*Creates Priority Queue of Specified Size */
    PriorityQueue(size_t size);
    
    
    
    /*Returns True if the PriorityQueue is Empty or else returns False .*/
    bool isEmpty() const;
    
    
    /*Returns True if the PriorityQueue is Full or else returns False   */
    bool isFull() const;
    
    
    /*Enqueue's the Data according to its priority in the Queue.Returns True if the data is inserted Successfully in the Queue or else returns false .
        Throws Overflow Exception if the Queue is full and we try to insert data*/
    bool enQueue(T data);
    
    /*Removes the Element with highest Priority from the Queue.
     Throws Underflow Exception if the Queue is Empty.*/
    bool deQueue();
    
    /* Returns Copy of Element with highest Priority .*/
    T peek() const;
    
    
    /* Prints the Queue with elements in higher priority first to low priority  */
    void print() const;
};


template <typename T>
PriorityQueue<T>::PriorityQueue(size_t size){
    queueSize=size;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const {
    if(dataCount==-1){
        return true;
    }
    return false;
}


template <typename T>
bool PriorityQueue<T>::isFull() const{
    if(dataCount==queueSize-1){
        return true;
    }
    return false;
}


template <typename T>
bool PriorityQueue<T>::enQueue(T data){
    if(isFull()){
        throw std::overflow_error("Queue is Full we can't insert more elements to the Queue ");
    }
    if(isEmpty()){
        listOfData.push_back(data);
        dataCount++;
        return true;
    }
    auto queueIterator=listOfData.begin();
    while (queueIterator!=listOfData.end()) {
        
        if(*queueIterator<data){
            listOfData.insert(queueIterator, data);
            dataCount++;
            return true;
        }
        queueIterator++;
    }
    
    listOfData.push_back(data);
    dataCount++;
    return true;
    
}


template <typename T>
void PriorityQueue<T>::print() const{
    std::cout<<"Elements in the Priority Queue are as Follows : \n";
    auto queueIterator=listOfData.cbegin();
    while(queueIterator!=listOfData.cend()){
        std::cout<<*queueIterator<<std::endl;
        queueIterator++;
    }
}



template <typename T>
bool PriorityQueue<T>::deQueue(){
    if(isEmpty()){
        throw std::underflow_error("Queue is Empty Cannot DeQueue Elements ");
    }

    listOfData.pop_front();
    dataCount--;
    return true;
}

template <typename T >
T PriorityQueue<T>::peek() const {
    if(isEmpty()){
        throw std::underflow_error("Queue is Empty ! Nothing to Peek In ");
    }
    T data=listOfData.front();
    return data;
}


}

#endif /* PriorityQueue_hpp */
