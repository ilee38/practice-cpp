/*
 * Implementation of recursive binary search.
 * Returns the index of the target element in the array,
 * a returned value of -1 indicates the target value was
 * not found.
 * It uses STL's Vector class for the array containing the elements.
 * Note: to avoid compilation errors with g++, use option -std=c++11
 * (e.g. g++ -std=c++11 <filename>)
*/
#include <iostream>
#include <vector>

int binarySearch(std::vector<int> arr, int target, int low, int high){
  int mid = (low + high) / 2;
  if(arr[mid] == target){
    return mid;
  }else if(low > high){
    return -1;
  }
  if(arr[mid] > target){
    return binarySearch(arr, target, low, mid-1);
  }else{
    return binarySearch(arr, target, mid+1, high);
  }
}


int main(){
  std::vector<int> myArr = {5, 6};
  int index = binarySearch(myArr, 5, 0, myArr.size()-1);
  std::cout <<"index of 5: " <<index <<"\n";
  index = binarySearch(myArr, 6, 0, myArr.size()-1);
  std::cout <<"index of 6: " <<index <<"\n";
  std::vector<int> myArr2 = {1, 8, 11, 51, 78, 95, 132, 256, 389};
  index = binarySearch(myArr2, 132, 0, myArr2.size()-1);
  std::cout <<"index of 132: " <<index <<"\n";
  index = binarySearch(myArr2, 1, 0, myArr2.size()-1);
  std::cout <<"index of 1: " <<index <<"\n";
  index = binarySearch(myArr2, 389, 0, myArr2.size()-1);
  std::cout <<"index of 389: " <<index <<"\n";
  index = binarySearch(myArr2, 500, 0, myArr2.size()-1);
  std::cout <<"index of 500 (not in array): " <<index <<"\n";
}