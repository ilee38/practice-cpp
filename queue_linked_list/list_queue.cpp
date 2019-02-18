/*
 * Implementation of a Queue using a linked list with tail pointer
*/
#include <iostream>
#include <stdexcept>
#include "list_queue.h"

  ListQueue::ListQueue(): size(0), _head(nullptr), _tail(nullptr){}

  ListQueue::~ListQueue(){}

  void ListQueue::enqueue(int val){
    ListNode new_node = ListNode(val, nullptr);
    if(size == 0){                  //if the queue is empty, set the new element
      _head = &new_node;            //as head and tail
      _tail = &new_node;
    }else{
      _tail->set_next(&new_node);    //set current tail's next to new node first
      _tail = &new_node;
    }
    size++;
  }

  int ListQueue::dequeue(){
    if(size == 0){
      throw std::range_error("Queue is empty");
    }
    int ret_val = _head->get_value();
    if(size == 1){
      _head = nullptr;
      _tail = nullptr;
    }else{
      _head = _head->get_next();
    }
    size--;
    return ret_val;
  }

  bool ListQueue::empty() const{
    return (size == 0);
  }

