/*
 * Implementation of a Queue using a linked list with tail pointer
*/
#include <iostream>
#include <stdexcept>
#include "list_queue.h"

  ListQueue::ListQueue(): size(0), _head(nullptr), _tail(nullptr){}

  ListQueue::~ListQueue(){
    delete _head;
    delete _tail;
  }

  void ListQueue::enqueue(int val){
    ListNode *new_node = new ListNode(val, nullptr);
    if(size == 0){                  //if the queue is empty, set the new element
      _head = new_node;            //as head and tail
      _tail = new_node;
    }else{
      _tail->set_next(new_node);    //set current tail's next to new node first
      _tail = new_node;
    }
    size++;
  }

  int ListQueue::dequeue(){
    if(size == 0){
      throw std::range_error("Queue is empty");
    }
    int ret_val = _head->get_value();
    ListNode *tmp = _head;
    if(size == 1){              //if only 1 element, set head and tail to nullptr
      _head = nullptr;          //before deleting the element
      _tail = nullptr;
    }else{
      _head = _head->get_next();
    }
    delete tmp;                 //delete element
    size--;
    return ret_val;
  }

  bool ListQueue::empty() const{
    return (size == 0);
  }

