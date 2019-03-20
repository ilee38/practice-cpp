/**
 * Definitions for the Mergesort algorithm
*/
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

void merge_sort(int*, int);    //sorts the given int array from lo to hi indices

void merge(int*, int*, int, int, int);    //overwrites the original array with merged values

void sort(int*, int*, int, int);

#endif