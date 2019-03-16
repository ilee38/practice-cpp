/**
 * Test file for the PriorityQueue class
*/
#include <iostream>
#include <stdexcept>
#include <array>
#include "priority_queue.h"

int main(){
  PriorityQueue PQ = PriorityQueue(10);

  std::cout<<"Created a new priority queue, current size is: " <<PQ.get_size() <<"\n";
  std::cout<<"Is the queue empty? " <<PQ.is_empty() <<"\n";
  std::cout<<"Inserting 6 elements...\n";
  PQ.insert(23, "Hello");
  PQ.insert(98, "world!");
  PQ.insert(186, "Im");
  PQ.insert(12, "in");
  PQ.insert(354, "a");
  PQ.insert(6, "queue");
  std::cout<<"Done, current size is: " <<PQ.get_size() <<"\n";
  std::cout<<"Is the queue empty? " <<PQ.is_empty() <<"\n";
  std::cout<<"Max element is: " <<PQ.get_max().key <<" " <<PQ.get_max().value <<"\n";
  PriorityQueue::HeapNode maxElement = PQ.extract_max();
  std::cout<<"Removing max element... " <<maxElement.key <<" " <<maxElement.value <<"\n";
  std::cout<<"Done, current size is: " <<PQ.get_size() <<"\n";
  std::cout<<"Max element is now: " <<PQ.get_max().key <<" " <<PQ.get_max().value <<"\n";
  std::cout<<"Removing element at position 2...\n";
  PQ.remove(2);
  std::cout<<"Done, current size is: " <<PQ.get_size() <<"\n";

  int unsortedList[10] = {613, 55, 8721, 472, 94, 72, 74, 8, 61, 356};
  std::cout<<"Printing unsorted array...\n";
  for(int i = 0; i < 10; i++){
    std::cout<<unsortedList[i]<<" ";
  }
  std::cout<<std::endl;
  std::cout<<"Sorting the array with Heap-sort...\n";
  PQ.heap_sort(unsortedList, 10);
  std::cout<<"Printing sorted array...\n";
  for(int j = 0; j < 10; j++){
    std::cout<<unsortedList[j]<<" ";
  }
  std::cout<<std::endl;
}