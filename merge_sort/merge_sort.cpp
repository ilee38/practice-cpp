/**
 * Implementation of the MergeSort algorithm
*/
#include <iostream>
#include <stdexcept>
#include "merge_sort.h"


void merge(int *S, int *aux, int lo, int mid, int hi){
  for(int k = lo; k <= hi; k++){    //copy to aux array
    aux[k] = S[k];
  }
  int i = lo, j = mid+1;    //i = index of left sub-array. j = index of right sub-array
  for(int k = lo; k <= hi; k++){
    if(i > mid){      //check that we haven't run out of left's sub-array bounds
      S[k] = aux[j];  //copy whats left on right sub-array
      j++;
    }else if(j > hi){   //check that we haven't run out of right's sub-array bounds
      S[k] = aux[i];    //copy whats left on left sub-array
      i++;
    }else if(aux[j] < aux[i]){      //copy the lowest element from right sub-array
      S[k] = aux[j];
      j++;
    }else{                //otherwise copy the left sub-array's. Also if they're equal, we always
      S[k] = aux[i];      //copy the left sub-array's first to preserve stability.
      i++;
    }
  }
}


void sort(int *S, int *aux, int lo, int hi){
  if(lo >= hi)return;
  int mid = (lo + hi) / 2;
  sort(S, aux, lo, mid);
  sort(S, aux, mid+1, hi);
  merge(S, aux, lo, mid, hi);
}


void merge_sort(int *S, int size){
  int *aux = new int[size];   //array to store unsorted items
  sort(S, aux, 0, size - 1);
  delete [] aux;
}

