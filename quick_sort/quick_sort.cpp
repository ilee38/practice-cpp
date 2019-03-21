/**
 * Implementation of the Quicksort algorithm
*/
#include <iostream>
#include <algorithm>      //for random_suffle() utility
#include "quick_sort.h"

/**
 * Performs the partitioning for quicksort. It does 3-way partition.
 * Arguments:
 * 1: Pointer to array of ints,
 * 2: Index of lo (i.e. first element in the array),
 * 3: Index of hi (i.e. last element in the array)
*/
void qs_partition(int *A, int lo, int hi){
  //since the array is shuffled, choose pivot to be the first element
  if(lo >= hi)return;
  int lt = lo, gt = hi;
  int i = lo, v = A[lo];
  int tmp;
  while(i <= gt){
    if(A[i] < v){
      tmp = A[i];
      A[i] = A[lt];
      A[lt] = tmp;
      i++; lt++;
    }else if(A[i] > v){
      tmp = A[i];
      A[i] = A[gt];
      A[gt] = tmp;
      gt--;
    }else{
      i++;
    }
  }
  qs_partition(A, lo, lt-1);
  qs_partition(A, gt+1, hi);
}


/**
 * Overwrites the input array into a sorted array.
 * Takes an array of ints and the number of elements in the array.
*/
void quick_sort(int *A, int size){
  //shuffle the array first
  std::random_shuffle(&A[0], &A[size]);

  //print out the shuffled array (for testing only)
  /*std::cout<<"Shuffled array:\n";
  for(int i = 0; i < size; i++){
    std::cout<<A[i] <<" ";
  }
  std::cout<<std::endl;*/

  qs_partition(A, 0, size - 1);
}