#include <iostream>
#include <stdexcept>
#include <memory>

#include "ResizableArray.h"

ResizableArray::ResizableArray(int initialSize){
  setCapacity(initialSize);
  items = 0;
  Arr = std::unique_ptr<int[]>(new int[initialSize]);

}

ResizableArray::~ResizableArray(){}

int ResizableArray::size() const{
  return items;
}

int ResizableArray::getCapacity() const{
  return capacity;
}

bool ResizableArray::isEmpty() const{
  if(items == 0) return true;
  return false;
}

int ResizableArray::at(int index) const{
  if(index > items || index < 0){
    throw std::invalid_argument("index parameter is invalid");
  }else{
    return Arr[index];
  }
}

void ResizableArray::push(int element){
  if(items == capacity){    //check if the array is full
    resize(2*capacity);
  }
  Arr[items] = element;
  items++;              //update elements count

}

void ResizableArray::resize(int newCapacity){
  std::unique_ptr<int[]> B(new int[newCapacity]);
  for(int i = 0; i < items; i++){     //copy elements to new array
    B[i] = Arr[i];
  }
  Arr = std::move(B);       //update array pointer
  capacity = newCapacity;   //update array's capacity
}

void ResizableArray::setCapacity(int c){
  if(c < 0){
    throw std::invalid_argument("array's capacity must be positive");
  }else{
    capacity = c;
  }
}