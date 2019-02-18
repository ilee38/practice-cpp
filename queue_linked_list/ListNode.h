#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode{

public:
  ListNode(int, ListNode *);
  ~ListNode();
  int get_value() const;
  void set_value(int);
  ListNode * get_next() const;
  void set_next(ListNode *);

private:
  int val;
  ListNode *next;
};
#endif