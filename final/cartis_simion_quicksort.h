//Simion Cartis
#ifndef _CARTIS_SIMION_QUICKSORT_H_
#define _CARTIS_SIMION_QUICKSORT_H_
#include<vector>
using std::vector;
#include <string>
using std::string;

/*
this function completes the example (the 25 files of size 10, 100 and 1000)
it creates one sorted file for each unsorted file, one file to show all execution times,
and one file to show the average execution times for each grouping of files (10,100, 1000)
*/
void completeExample(vector<vector<string>> unsortedFiles, string avgTime);

//FUNCTIONS FOR READING AND WRITING TO FILES
/*
this function creates the sorted file for a given unsorted file
*/
double makeOutputFile(string outputFile, vector<double> unsortedNums);
/*
this function creates a file with the execution time (in microseconds) 
of quicksort for each unsorted file
*/
void writeElapseTime(double microseconds, string ElapseTimeFile,
                     int inputSize, bool example = false);
/*
this function translates a file with unsorted numbers (seperated by spaces)
into unsorted vectors
*/
vector<double> fileToVector(string inputFile);

//FUNCTIONS FOR QUICKSORT
/*
implementation of recursive quicksort
*/
void quickSort(vector<double>& toSort, int low, int high);
/*
partitions the vector using the median of three method,
returns the index of the partition
*/
int partition (vector<double>& toSort, int low, int high);
/*
finds the median of the first, middle, and last element,
puts the median at the first index of the vector
*/
void findPivot(vector<double>& toSort, int low, int middle, int high);
#endif