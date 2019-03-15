/**
 * Priority Queue class implementation. The priority queue is implemented using
 * a Max Heap data structure, represented with an underlying array.
*/
#include "priority_queue.h"

PriorityQueue::PriorityQueue(int cap){
  _capacity = cap;
  _size = 0;
  _PQ_data = new HeapNode[cap];
}


PriorityQueue::~PriorityQueue(){
  delete [] _PQ_data;
}


/**
 * Inserts a new element into the priority queue:
 * 1. insert the new element  at the end of the array, then
 * 2. sift up the element to fix the heap (if needed)
*/
void PriorityQueue::insert(int key, std::string value){
  _PQ_data[_size].key = key;
  _PQ_data[_size].value = value;
  _size++;
  _sift_up(_size - 1);
}


/**
 * Sifts up the element at the given position:
 * 1. compare element with its parent and
 * 2. if element is greater, swap it with the parent
 * 3. repeat process until reaching the top of the heap
*/
void PriorityQueue::_sift_up(int pos){
  if(pos <= 0)return;
  int parent = (pos - 1) / 2;
  if(_PQ_data[pos].key > _PQ_data[parent].key){
    HeapNode *tmp = &_PQ_data[parent];
    _PQ_data[parent] = _PQ_data[pos];
    _PQ_data[pos] = *tmp;
    tmp = nullptr;
  }else{
    return;
  }
  _sift_up(parent);
}


/**
 * Returns the element with the maximum value in the
 * priority queue. I.e. the element at the top of the heap.
*/
PriorityQueue::HeapNode PriorityQueue::get_max() const{
  return _PQ_data[0];
}


/**
 * Returns the number of elements in the priority queue
*/
int PriorityQueue::get_size() const{
  return _size;
}


bool PriorityQueue::is_empty() const{
  return (_size == 0);
}


/**
 * Returns and removes the element with the greatest key in the priority queue.
 * I.e. the element at the top of the heap. To remove the top element:
 * 1. Replace the top element with the last element in the array (deleting the
 *  las element)
 * 2. Then sift down the element to fix the heap.
*/
PriorityQueue::HeapNode PriorityQueue::extract_max(){
  HeapNode maxElement = _PQ_data[0];
  _PQ_data[0] = _PQ_data[_size - 1];
  _size--;
  _sift_down(0);
  return maxElement;
}