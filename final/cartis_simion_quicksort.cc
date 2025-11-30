// Simion Cartis
#include "cartis_simion_quicksort.h"
#include "inputFileGenerator.h"
#include<iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
#include<vector>
using std::vector;
#include <algorithm>
using std::swap;
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <string>
using std::string;
using std::to_string;
#include <chrono>
using namespace std::chrono;

int main(int argc, char* argv[]) {
  // if no arguments are added, run through randomly created files
  if (argc == 1) {
    vector<vector<string>> unsortedFiles = makeAllFiles();
    cout << "sorting files with 10 nums..." << endl;
    /* TODO put the numbers that are in the files into vectors, sort the numbers, put
       the now sorted vector into new file, log sorting time for each unsorted list of numbers
    */
  } else {
    string inputFile = argv[1];
    vector<double> toSort = fileToVector(inputFile);
    string outputFile = argv[2];
    makeOutputFiles(outputFile, toSort);
    // arguments will just be [1] = input.txt [2] = ouput.txt.
    // do not have to find average time in this case, although should still ask professor
  }
  return 0;
}

void makeOutputFiles(string& outputFile, vector<double> toSort) {
  ofstream writeToSorted(outputFile);
  if (!writeToSorted) {
    cerr << "cannot write to sorted ouput file";
  }
  auto start = high_resolution_clock::now();
  quickSort(toSort, 0, toSort.size()-1);
  auto stop = high_resolution_clock::now();

  for (int i = 0; i < toSort.size(); ++i) {
    writeToSorted << toSort[i] << " ";
  }
  writeToSorted.close();

  auto duration_us = duration_cast<microseconds>(stop-start);
  double seconds = duration<double>(stop - start).count(); // I HAVE NO CLUE IF THIS TIME THING IS CORRECT
  ofstream writeToTime(to_string(toSort.size())+"_elapseTime.txt");
  if (!writeToTime) {
    cerr << "cannot write to elapse time file";
  }
  writeToTime << "Input Size\texecution time\n" << toSort.size() << "\t\t\t\t" <<
                  seconds;
  writeToTime.close();
}

vector<double> fileToVector(string inputFile) {
  ifstream read(inputFile);
  if (!read) {
    cerr << "could not open input file";
  }
  vector<double> nums;
  double x;
  while (read >> x) {
    nums.push_back(x);
  }
  read.close();
  return nums;
}



void quickSort(vector<double>& toSort, int low, int high) {
  if (low < high) {
    int s = partition(toSort, low, high);
    quickSort(toSort, low, s);// sort sub-vector of values less than pivot
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
  int i = low-1;
  int j = high+1;
  while (true) {
    do {
      ++i;
    } while (toSort[i] < p);
    do {
      --j;
    } while (toSort[j] > p);
    if (i >= j) {
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
