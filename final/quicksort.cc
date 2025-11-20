// Simion Cartis
#include "quicksort.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<vector>
using std::vector;
#include <algorithm>
using std::swap;

int main () {
  vector<double> toSort = {5.0,7.0,1.0,3.0,19.0,10.3,54.0,5.0};
    quickSort(toSort, 0, toSort.size()-1);
  
    for (int i = 0; i < toSort.size(); ++i) {
      if (i == toSort.size()-1) {
        cout << toSort[i] << endl;
      } else {
        cout << toSort[i] << ", ";
      }
    }
  return 0;
}

void quickSort(vector<double>& toSort, int low, int high) {
  if (low < high) {
    int s = partition(toSort, low, high);
    quickSort(toSort, low, s-1);// sort sub-vector of values less than pivot
    quickSort(toSort, s+1, high); // sort sub-vector of values greater than pivot
  }
}

/*
partitions the vector around a pivot. pivot is determined by finding the median value of the
low, middle, and high indexes.
*/
int partition (vector<double>& toSort, int low, int high) {
  findPivot(toSort, low, low+(high-low)/2, high);
  double p = toSort[low];
  int i = low;
  int j = high+1;
  while (true) {
    do {
      ++i;
    } while (toSort[i] < p);
    
    do {
      --j;
    } while (toSort[j] > p);
    if (i > j) {
      swap(toSort[j], toSort[low]);
      return j;
    }
    swap(toSort[i], toSort[j]);
  }
}

/*
this function finds the median of the first, middle, and last value of a sub-vector,
orders them, and swaps the first and middle value (for the partitioning step)
*/
void findPivot(vector<double>& toSort, int low, int middle, int high) {
  if (toSort[low] > toSort[high]) {
    swap(toSort[low], toSort[high]);
  }
  if (toSort[middle] > toSort[high]) {
    swap(toSort[middle], toSort[high]);
  }
  if (toSort[low] > toSort[middle]) {
    swap(toSort[low], toSort[middle]);
  }
  swap(toSort[low], toSort[middle]);
}
