#include <iostream>
#include "ResizableArray.h"

int main(){
  ResizableArray testArr;     //instantiate array with default capacity

  assert(testArr.getCapacity());
  assert(!testArr.size());      //initial size should be 0
  assert(testArr.isEmpty());
  std::cout << "Initial capacity: " << testArr.getCapacity() << std::endl;
  std::cout << "Initial size: " << testArr.size() << std::endl;

  testArr.push(9);
  assert(!testArr.isEmpty());
  assert(testArr.at(0));
  std::cout << "Item at index 0: " << testArr.at(0) << std::endl;
  std::cout << "Capacity: " << testArr.getCapacity() << std::endl;

  testArr.push(21);
  std::cout << "Item at index 1: " << testArr.at(1) << std::endl;
  std::cout << "Capacity: " << testArr.getCapacity() << std::endl;
  assert(testArr.at(1));
  assert(testArr.size());
  assert(testArr.getCapacity());

  testArr.push(45);
  std::cout << "Item at index 2: " << testArr.at(2) << std::endl;
  std::cout << "Capacity: " << testArr.getCapacity() << std::endl;
  assert(testArr.at(2));
  assert(testArr.size());
  assert(testArr.getCapacity());

  testArr.push(38);
  std::cout << "Item at index 3: " << testArr.at(3) << std::endl;
  std::cout << "Capacity: " << testArr.getCapacity() << std::endl;
  assert(testArr.at(3));
  assert(testArr.size());
  assert(testArr.getCapacity());

  return EXIT_SUCCESS;
}