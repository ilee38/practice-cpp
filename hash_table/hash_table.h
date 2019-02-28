/*
 * Class definition for HashTable
*/
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>
#include <functional>     //provides templated hash() function
#include <stdexcept>
#include <stdlib.h>       //for abs()
#include "hash_item.h"

class HashTable{

public:
  HashTable(int);
  ~HashTable();
  int hash_(int);
  std::string get(int);
  void add(int, std::string);
  void remove(int);
  bool exists(int);

private:
  int cap_;             //capacity of the table
  HashItem *table_;     //pointer to the array of HashItems

};
#endif