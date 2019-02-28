/*
 * Definition of HashItem class.
 * A HashItem represents an element (with key, value pair) stored in a
 * Hash table. In this case, it only supports keys of type int and
 * values of type std::string.
 * A key_ = -1 and value_ = "<empty>" indicates the item is empty.
*/
#ifndef HASH_ITEM_H
#define HASH_ITEM_H

#include <string>
#include <iostream>

class HashItem{

public:
  HashItem(int, std::string);
  HashItem();
  ~HashItem();
  std::string get_value() const;
  int get_key() const;
  void set_value(std::string);
  void set_key(int);

private:
  int key_;
  std::string value_;

};
#endif