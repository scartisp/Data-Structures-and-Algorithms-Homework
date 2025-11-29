//Simion Cartis
#ifndef _CARTIS_SIMION_QUICKSORT_H_
#define _CARTIS_SIMION_QUICKSORT_H_
#include<vector>
using std::vector;

void quickSort(vector<double>& toSort);
void quickSort(vector<double>& toSort, int low, int high);
int partition (vector<double>& toSort, int low, int high);
void findPivot(vector<double>& toSort, int low, int middle, int high);
#endif