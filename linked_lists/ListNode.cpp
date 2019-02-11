#include <iostream>
#include "ListNode.h"

/*
* Constructor with default values for val and next
*/
ListNode::ListNode(int value, ListNode *nxt) : val(0), next(nullptr){
  val = value;
  next = nxt;
}

ListNode::~ListNode(){}

int ListNode::get_value() const{
  return val;
}

void ListNode::set_value(int newVal){
  val = newVal;
}

ListNode * ListNode::get_next() const{
  return next;
}

void ListNode::set_next(ListNode *nxt){
  next = nxt;
}