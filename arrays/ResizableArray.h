#ifndef RESIZABLEARRAY_H_
#define RESIZABLEARRAY_H_

#include <memory>

class ResizableArray{
public:
    ResizableArray(int = 1);           //constructor: default capacity = 1
    ~ResizableArray();
    int size() const;           //returns num of elements
    int getCapacity() const;    //returns current capacity of the array
    bool isEmpty() const;
    int at(int) const;          //returns element at a given index
    void push(int);             //iserts item at the end. Growa capacity if full

private:
    void resize(int);           //resizes the array to new capacity
    void setCapacity(int);      //set the initial capacity of the array

    int items;
    int capacity;
    std::unique_ptr<int[]> Arr;     //the storage array for ints
};

#endif