//Simion Cartis
#ifndef _CARTIS_SIMION_QUICKSORT_H_
#define _CARTIS_SIMION_QUICKSORT_H_
#include<vector>
using std::vector;
#include <string>
using std::string;

void makeOutputFiles(string& outputFile, vector<double> unsortedNums);
vector<double> fileToVector(string inputFile);

//functions for quicksort
void quickSort(vector<double>& toSort, int low, int high);
int partition (vector<double>& toSort, int low, int high);
void findPivot(vector<double>& toSort, int low, int middle, int high);
#endif