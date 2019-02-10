#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode{

public:
  ListNode(int, int *);
  ~ListNode();
  int get_value() const;
  void set_value(int);
  int* get_next() const;
  void set_next(int*);

private:
  int val;
  int *next;
};
#endif