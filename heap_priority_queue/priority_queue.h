/**
 * Definition of PriorityQueue class, implemented using
 * a Heap data structure represented with an underlying array
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

    PriorityQueue();
    ~PriorityQueue();
    void insert(HeapNode*);
    int get_max() const;
    int get_size() const;
    bool is_empty() const;
    int extract_max();
    void remove(int);
    void heapify();
    void heap_sort();

  private:
    void sift_up(HeapNode*);
    void sift_down(HeapNode*);
    int _capacity;
    int _size;
    HeapNode* PQ_data;    //pointer to array of HeapNode pointers
};
#endif