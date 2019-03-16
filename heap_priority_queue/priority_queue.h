/**
 * Definition of PriorityQueue class, implemented using
 * a max Heap data structure represented with an underlying array
*/
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <stdexcept>

class PriorityQueue{

  public:

    struct HeapNode{
      int key;
      std::string value;
    };

    PriorityQueue(int);
    ~PriorityQueue();
    void insert(int, std::string);
    HeapNode get_max() const;
    int get_size() const;
    bool is_empty() const;
    HeapNode extract_max();
    void remove(int);
    void heapify(int*, int);
    void heap_sort(int*, int);

  private:
    void _sift_up(int);
    void _sift_down(int);
    void _sift_down(int*, int, int);    //overloaded to work with heapify() function
    int _capacity;                      //capacity of the array
    int _size;                          //number of elements in the priority queue
    HeapNode* _PQ_data;                 //pointer to array of HeapNode elements
};
#endif