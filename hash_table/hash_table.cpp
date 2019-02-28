/*
 * Implementation of HashTable class
*/
#include "hash_table.h"

HashTable::HashTable(int cap){
  table_ = new HashItem[cap];
  cap_ = cap;
}


HashTable::~HashTable(){
  delete [] table_;
}


/* Returns the index corresponding to the hash code of the given key */
int HashTable::hash_(int key){
  int hashCode = std::hash<int>()(key);
  return abs(hashCode) % cap_;
}


std::string HashTable::get(int key){
  int i = hash_(key);
  while(true){
    int searchKey = table_[i].get_key();
    if(searchKey == key){
      return table_[i].get_value();
    }else if(searchKey == -1 && table_[i].get_value() == "<empty>"){
      throw std::invalid_argument("Key not found in table");
    }
    i = (i+1) % cap_;
  }
}


void HashTable::add(int k, std::string v){
    HashItem newItem = HashItem(k, v);
    int index = hash_(k);
    while(true){
      int availableSlot = table_[index].get_key();
      if(availableSlot == -1){
        table_[index].set_key(k);
        table_[index].set_value(v);
        return;
      }else if(availableSlot == k){       //key already exists, update value
        table_[index].set_value(v);
        return;
      }
      index = (index + 1) % cap_;
    }
}


void HashTable::remove(int key){
  int index = hash_(key);
  while(true){
    int searchKey = table_[index].get_key();
    if(searchKey == -1 && table_[index].get_value() == "<empty>"){
      throw std::invalid_argument("Key not found in table");
    }else if(searchKey == key){
      table_[index].set_key(-1);
      table_[index].set_value("<deleted>");
      return;
    }
    index = (index + 1) % cap_;
  }
}


bool HashTable::exists(int key){
  int index = hash_(key);
  while(true){
    int searchKey = table_[index].get_key();
    if(searchKey == key){
      return true;
    }else if(searchKey == -1 && table_[index].get_value() == "<empty>"){
      return false;
    }
    index = (index + 1) % cap_;
  }
}