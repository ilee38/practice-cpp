/*
 * Tests for HashTable class
*/
#include <iostream>
#include "hash_table.h"

int main(){
  HashTable ht = HashTable(101);
  std::cout<<"Adding (1, one) pair...\n";
  ht.add(1, "one");
  std::cout<<"Adding (2, two) pair...\n";
  ht.add(2, "two");
  std::cout<<"Adding (3, three) pair...\n";
  ht.add(3, "three");
  std::cout<<"Does key 2 exists?\n";
  if(ht.exists(2)){
    std::cout<<"Yes\n";
  }else{
    std::cout<<"No\n";
  }
  std::cout<<"Get value of key 1: " << ht.get(1) <<"\n";
  std::cout<<"Get value of key 2: " << ht.get(2) <<"\n";
  std::cout<<"Get value of key 3: " << ht.get(3) <<"\n";
  std::cout<<"Removing element with key 2...\n";
  ht.remove(2);
  std::cout<<"Does key 2 exists?\n";
  if(ht.exists(2)){
    std::cout<<"Yes\n";
  }else{
    std::cout<<"No\n";
  }
  std::cout<<"Updating value of element with key 3...\n";
  ht.add(3, "THREE");
  std::cout<<"Get value of key 3: " << ht.get(3) <<"\n";
}