/*
 * Definition of a Queue using a fixed-size array
*/
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class ArrayQueue{

public:
  ArrayQueue();
  ~ArrayQueue();
  void enqueue(int);
  int dequeue();
  bool empty() const;

private:
  int _size;
  int *_data;     //pointer to the array

};
#endif