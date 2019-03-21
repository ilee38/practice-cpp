/**
 * Function definitions for the Quicksort algorithm
*/
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

/**
 * Takes an array of ints and the number of elements in the array.
 * Overwrites the array into a sorted array
*/
void quick_sort(int*, int);


/**
 * Performs the partitioning for quicksort. It does 3-way partition.
 * Arguments:
 * 1: Pointer to array of ints,
 * 2: Index of lo (i.e. first element in the array),
 * 3: Index of hi (i.e. last element in the array)
*/
void qs_partition(int*, int, int);

#endif