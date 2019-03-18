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
  if(_size == _capacity){
    throw std::invalid_argument("Error: queue is full");
  }
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
    HeapNode tmp = _PQ_data[parent];
    _PQ_data[parent] = _PQ_data[pos];
    _PQ_data[pos] = tmp;
  }else{
    return;
  }
  _sift_up(parent);
}


/**
 * Returns the element (w/out removing it) with the maximum value in the
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
 *  last element)
 * 2. Then sift down the element to fix the heap.
*/
PriorityQueue::HeapNode PriorityQueue::extract_max(){
  HeapNode maxElement = _PQ_data[0];
  _PQ_data[0] = _PQ_data[_size - 1];
  _size--;
  _sift_down(0);
  return maxElement;
}


/**
 * Sifts the element at the given position down the heap to comply with the
 * Max Heap cnstraints:
 * 1. Compare the element's key with its children's keys. If the element's key is
 * lower, then choose the child with the greatest key value and swap them (first
 * check if the element has left and/or right children)
 * 2. Continue until reaching the end of the Heap.
*/
void PriorityQueue::_sift_down(int pos){
  if((2*pos + 1) >= _size)return;
  int max_pos = pos;
  int l_child = 2*pos + 1;
  int r_child = 2*pos + 2;
  /* check if there are left and/or right children and compare keys */
  if(l_child <= _size && _PQ_data[max_pos].key < _PQ_data[l_child].key){
    max_pos = l_child;
  }
  if(r_child <= _size && _PQ_data[max_pos].key < _PQ_data[r_child].key){
    max_pos = r_child;
  }
  if(max_pos != pos){
    HeapNode tmp = _PQ_data[pos];
    _PQ_data[pos] = _PQ_data[max_pos];
    _PQ_data[max_pos] = tmp;
    _sift_down(max_pos);
  }
}


/**
 * Removes item at given index from the array
 * 1. Swap with last element, then
 * 2. sift down
*/
void PriorityQueue::remove(int index){
  HeapNode tmp = _PQ_data[index];
  _PQ_data[index] = _PQ_data[_size - 1];
  _size--;
  _sift_down(index);
}


/**
 * Creates a Heap from an array of elements. Needed for heap sort.
 * 1. Start from the first non-leaf node (i.e. position [(n-1)/2]-1) going up.
 * 2. Call sift_down() for each of these nodes.
 *
 * Parameters:
 * list = pointer to an array of integers
 * conut = number of elements in the array
*/
void PriorityQueue::heapify(int *list, int count){
  for(int i = (count - 1)/2 - 1; i >= 0; i--){
    _sift_down(list, i, count);
  }
}


/**
 * Performs in-place heap-sort algorithm on an array of elements.
 * 1. Make the array a Max Heap
 * 2. Since the max element is always at the top, we swap the first and last
 * elements in the array (n-1) times. (this puts the max element at the end of the array)
 * 3. Each time we swap the elements, we "decrease" the array's size and call sift_down.
 *
 * Parameters:
 * list = pointer to an array of integers
 * conut = number of elements in the array
*/
void PriorityQueue::heap_sort(int* list, int count){
  int temp;
  heapify(list, count);
  for(int i = count - 1; i > 0; i--){
    temp = list[i];
    list[i] = list[0];
    list[0] = temp;
    //before calling sift_down, "decrease" the array size (i.e. the last index is now i-1)
    _sift_down(list, 0, i-1);
  }
}


/**
 * Overloaded _sift_down()
 * Takes a pointer to an array of values, a position, and the size of the array (i.e.
 * the number of elements in the array)
*/
void PriorityQueue::_sift_down(int* arr, int pos, int size){
  if((2*pos + 1) > size)return;
  int max_pos = pos;
  int l_child = 2*pos + 1;
  int r_child = 2*pos + 2;
  /* check if there are left and/or right children and compare keys */
  if(l_child <= size && arr[max_pos] < arr[l_child]){
    max_pos = l_child;
  }
  if(r_child <= size && arr[max_pos] < arr[r_child]){
    max_pos = r_child;
  }
  if(max_pos != pos){
    int tmp = arr[pos];
    arr[pos] = arr[max_pos];
    arr[max_pos] = tmp;
    _sift_down(arr, max_pos, size);
  }
}