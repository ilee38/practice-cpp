/*
 * Class implementation of a Queue using a fixed-size array
*/
#include <iostream>
#include <stdexcept>
#include "array_queue.h"

#define ARRAY_SIZE 100        //default size of the internal array

ArrayQueue::ArrayQueue(): _size(0), _data(new int[ARRAY_SIZE]){}

ArrayQueue::~ArrayQueue(){
  delete [] _data;
}


void ArrayQueue::enqueue(int val){
  if(_size >= (ARRAY_SIZE - 1)){
    throw std::invalid_argument("Queue is full");
  }
  _data[_size] = val;     //add element to the back of the array
  _size++;
}


int ArrayQueue::dequeue(){
  if(_size == 0){
    throw std::invalid_argument("Queue is empty");
  }
  int ret_val = _data[0];     //return element on the front of the array
  for(int i = 1; i < _size; i++){
    _data[i-1] = _data[i];
  }
  _data[_size] = NULL;      //at the end of the loop the last element didn't change, so set it to null
  _size--;
  return ret_val;
}


bool ArrayQueue::empty() const{
  return _size == 0;
}