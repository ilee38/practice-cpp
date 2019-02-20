#include <iostream>
#include "array_queue.h"

int main(){
  ArrayQueue q = ArrayQueue();

  std::cout<<"Is queue empty?\n";
  if(q.empty()){
    std::cout<<"yes\n";
  }else{
    std::cout<<"no.\n";
  }
  std::cout<<"Enqueueing 9...\n";
  q.enqueue(9);
  std::cout<<"Is queue empty?\n";
  if(q.empty()){
    std::cout<<"yes\n";
  }else{
    std::cout<<"no\n";
  }
  std::cout<<"Dequeueing 9...\n";
  std::cout<<(q.dequeue()) <<"\n";
  std::cout<<"Enqueueing 84, 95, 103...\n";
  q.enqueue(84);
  q.enqueue(95);
  q.enqueue(103);
  std::cout<<"Now dequeueing all...\n";
  std::cout<<(q.dequeue()) <<"\n";
  std::cout<<(q.dequeue()) <<"\n";
  std::cout<<(q.dequeue()) <<"\n";
  std::cout<<"Is queue empty?\n";
  if(q.empty()){
    std::cout<<"yes\n";
  }else{
    std::cout<<"no.\n";
  }
}