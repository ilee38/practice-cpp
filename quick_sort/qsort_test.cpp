/**
 * Test file for quick_sort() function
*/
#include <iostream>
#include "quick_sort.h"

int main(){
  const int ARR_SIZE = 30;
  int original[] = {325432, 989,   547510, 3,   -93,  189019, 5042,  123,
                    597,    42,    7506,   184, 184,  2409,   45,    824,
                    4,      -2650, 9,      662, 3928, -170,   45358, 395,
                    842,    7697,  110,    14,  99,   221};

  int S[ARR_SIZE];
  memcpy(S, original, sizeof S);

  quick_sort(S, ARR_SIZE);

  std::cout<<"Original array:\n";
  for(int i = 0; i < ARR_SIZE; i++){
    std::cout<<original[i] <<" ";
  }
  std::cout<<std::endl;

  std::cout<<"Sorted array:\n";
  for(int i = 0; i < ARR_SIZE; i++){
    std::cout<<S[i] <<" ";
  }
  std::cout<<std::endl;
}