/**
 * Test file for SimplyLinkedList class
*/
#include <iostream>
#include "SinglyLinkedList.h"

int main(){
  SinglyLinkedList ll = SinglyLinkedList();

  std::cout<< "initial size: " << ll.size() << "\n";
  std::cout<< "is list empty?\n";
  if(ll.empty()){
    std::cout<< "yes\n";
  }else{
    std::cout<< "no\n";
  }
  std::cout<< "pushing 24 to front...\n";
  ll.push_front(24);
  std::cout<< "new size: " << ll.size() <<"\n";
  std::cout<< "value at index 0: " << ll.value_at(0) << "\n";
  std::cout<< "pushing 6 to back...\n";
  ll.push_back(6);
  std::cout<< "value at index 0: " << ll.value_at(0) << "\n";
  std::cout<< "value at index 1: " << ll.value_at(1) << "\n";
  std::cout<< "now pushing 783 at front...\n";
  ll.push_front(783);
  std::cout<< "new size: " << ll.size() << "\n";
  std::cout<< "value at index 0: " << ll.value_at(0) << "\n";
  std::cout<< "value at index 1: " << ll.value_at(1) << "\n";
  std::cout<< "value at index 2: " << ll.value_at(2) << "\n";
  std::cout<< "front value: " << ll.front() << "\n";
  std::cout<< "back value: " << ll.back() << "\n";
  std::cout<< "inserting 4 at index 1...\n";
  ll.insert(1,4);
  std::cout<< "new size: " << ll.size() << "\n";
  std::cout<< "value at index 0: " << ll.value_at(0) << "\n";
  std::cout<< "value at index 1: " << ll.value_at(1) << "\n";
  std::cout<< "value at index 2: " << ll.value_at(2) << "\n";
  std::cout<< "value at index 3: " << ll.value_at(3) << "\n";
  std::cout<< "front value: " << ll.front() << "\n";
  std::cout<< "back value: " << ll.back() << "\n";
  std::cout<< "popping from front... " << ll.pop_front() << "\n";
  std::cout<< "popping from back... " << ll.pop_back() << "\n";
  std::cout<< "pushing 18 to front...\n";
  ll.push_front(18);
  std::cout<< "erasing node at index 1...\n";
  ll.erase(1);
  std::cout<< "new value at index 0: " << ll.value_at(0) << "\n";
  std::cout<< "new value at index 1: " << ll.value_at(1) << "\n";
  std::cout<< "new size: " << ll.size() << "\n";
}