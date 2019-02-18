#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "ListNode.h"

class ListQueue{

public:
  ListQueue();
  ~ListQueue();
  void enqueue(int);
  int dequeue();
  bool empty() const;

private:
  int size;
  ListNode *_head;
  ListNode *_tail;

};
#endif