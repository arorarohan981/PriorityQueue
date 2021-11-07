//
//  main.cpp
//  PriorityQueue
//
//  Created by Rohan Arora on 07/11/21.
//

#include <iostream>
#include "PriorityQueue.hpp"
int main(int argc, const char * argv[]) {
    mylib::PriorityQueue<int> intQueue{3};
    intQueue.enQueue(9);
    intQueue.enQueue(1);
    intQueue.enQueue(174);
//    intQueue.enQueue(4);
    intQueue.print();
    std::cout<<"Is Queue Empty "<<std::boolalpha<<intQueue.isEmpty()<<std::endl;
    std::cout<<"Is Queue Full "<<intQueue.isFull()<<std::endl;
    std::cout<<"Peeking Element with Highest Priority in the Queue "<<intQueue.peek()<<std::endl;
    intQueue.deQueue();
    intQueue.print();
    return 0;
}
