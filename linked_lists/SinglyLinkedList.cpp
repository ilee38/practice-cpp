#include <iostream>
#include <stdexcept>
#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList(): head(nullptr), tail(nullptr), size_(0){}

SinglyLinkedList::~SinglyLinkedList(){
  ListNode *current = head;
  ListNode *next = nullptr;
  while(current){
    next = current->get_next();
    delete current;
    current = next;
  }

}


int SinglyLinkedList::size() const{
  return size_;
}


bool SinglyLinkedList::empty() const{
  return(size_ == 0);
}


int SinglyLinkedList::value_at(int index) const{
  if(index >= size_ || index < 0){
    throw std::invalid_argument("Index is out of bounds");
  }
  if(index == 0){
    return head->get_value();
  }else if(index == size_ - 1){
    return tail->get_value();
  }else{
    ListNode *item = head;
    for(int i = 0; i < index; i++){
      item = item->get_next();
    }
    int ret_val = item->get_value();
    //delete item;
    return ret_val;
  }
}


void SinglyLinkedList::push_front(int val){
  ListNode *newNode = new ListNode(val, head);    //create new node w/ next pointing to head
  head = newNode;
  if(size_ == 0){                 //if the list was empty, set the tail and head to the same element
    tail = newNode;
    newNode->set_next(nullptr);
  }
  size_ ++;
}


int SinglyLinkedList::pop_front(){
  if(size_ == 0){
    throw std::range_error("List is empty");
  }
  ListNode *tmp = head;
  int retVal = head->get_value();
  if(size_ == 1){                   //if there's only 1 element, set the head's next to null
    head->set_next(nullptr);
  }else{
    head = head->get_next();
  }
  delete tmp;
  size_ --;
  return retVal;
}


void SinglyLinkedList::push_back(int val){
  ListNode *newNode = new ListNode(val, nullptr);
  if(size_ == 0){                 //if the list is empty, set head and tail to the new node
    head = newNode;
    tail = newNode;
  }else{
    tail->set_next(newNode);      //set current tail to point to the new element
    tail = newNode;               //update list's tail
  }
  size_++;
}


int SinglyLinkedList::pop_back(){
  if(size_ == 0){
    throw std::range_error("List is empty");
  }
  int retVal = tail->get_value();
  if(size_ == 1){
    ListNode *tmp = tail;                   //case where list has only 1 element
    head->set_next(nullptr);
    tail = head;                    //set head and tail to the same element
    size_--;
    delete tmp;
    return retVal;
  }
  ListNode *item = head;
  for(int i = 0; i < size_ - 1; i++){       //go to second-to-last element
    item = item->get_next();
  }
  item->set_next(nullptr);
  tail = item;
  delete item;
  size_--;
  return retVal;
}


int SinglyLinkedList::front() const{
  return head->get_value();
}


int SinglyLinkedList::back() const{
  return tail->get_value();
}


void SinglyLinkedList::insert(int index, int val){
  if(index >= size_ || index < 0){
    throw std::invalid_argument("Index is out of bounds");
  }else if(index == 0){
    push_front(val);        //push_front() takes care of incrementing list's size
    return;
  }
  ListNode *newNode = new ListNode(val, nullptr);
  ListNode *item = head;
  for(int i = 0; i < index - 1; i++){
    item = item->get_next();
  }
  newNode->set_next(item->get_next());
  item->set_next(newNode);
  size_++;
}


void SinglyLinkedList::erase(int index){
  if(index >= size_ || index < 0){
    throw std::invalid_argument("Index is out of bounds");
  }else if(size_ == 0){
    throw std::range_error("List is empty");
  }
  if(index == 0){
    pop_front();
  }else if(index == size_ - 1){
    pop_back();
  }else{
    ListNode *item = head;
    for(int i = 0; i < index - 1; i++){     //traverse list to element at index-1
      item = item->get_next();
    }
    ListNode *toDelete = item->get_next();
    item->set_next(toDelete->get_next());
    delete toDelete;
    size_--;
  }
}