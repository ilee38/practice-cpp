#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "ListNode.h"

class SinglyLinkedList{

public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  int size() const;         //returns the number of elements in the list
  bool empty() const;
  int value_at(int) const;   //returns the value of item at index
  void push_front(int);      //add item with given value at the front of the list
  int pop_front();           //removes item at the front and returns its value
  void push_back(int);
  int pop_back();           //removes item at the back and returns its value
  int front() const;
  int back() const;
  void insert(int, int);    //inserts element at index, so current item at index is now pointed to by inserted element
  void erase(int);          //deletes element at index

private:
  ListNode head;
  ListNode tail;
  int size_;

};
#endif