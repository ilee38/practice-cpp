/*
 * Definition of HashItem class.
 * A HashItem represents an element (with key, value pair) stored in a
 * Hash table. In this case, it only supports keys of type int and
 * values of type std::string.
 * A key_ = -1 and value_ = "<empty>" indicates the item is empty.
*/
#include <iostream>
#include <string>
#include "hash_item.h"

HashItem::HashItem(int k, std::string v): key_(-1), value_("<empty>"){}

HashItem::HashItem(): key_(-1), value_("<empty>"){}

HashItem::~HashItem(){}

std::string HashItem::get_value() const{ return value_;}

int HashItem::get_key() const{ return key_;}

void HashItem::set_value(std::string val){
  value_ = val;
}

void HashItem::set_key(int k){
  key_ = k;
}