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
#include <filesystem>
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <string>
using std::string;
using std::to_string;
#include <chrono>
using namespace std::chrono;

int main(int argc, char* argv[]) {
  // if no arguments are added, run through randomly created files (the example)
  if (argc == 1) {
    string avgTimeFile = "average_times.txt"; // create the average time file,
    ofstream createAvgTime(avgTimeFile); // don't add numbers yet, jsut the titles
    if (!createAvgTime) {
      cerr << "could not open average time file";
      return 1;
    }
  createAvgTime << "Input Size\taverage execution time\n";
  createAvgTime.close();
  completeExample(makeAllFiles(), avgTimeFile);
  } else { // arguments will just be [1] = input.txt [2] = ouput.txt
    string inputFile = argv[1];
    vector<double> toSort = fileToVector(inputFile);
    string outputFile = argv[2];
    string elapseTimeFile = to_string(toSort.size())+"_elapseTime.txt";
    writeElapseTime(makeOutputFile(outputFile, toSort), elapseTimeFile, toSort.size());
  }
  return 0;
}

void completeExample(vector<vector<string>> unsortedFiles, string avgTimeFile) {
  for (int i = 0; i < unsortedFiles.size(); ++i) { //outer for loop to get 
                                                   //individually, each
                                                   //grouping of unsorted files
    double totalTime = 0;
    for (int j = 0; j < unsortedFiles[i].size(); ++j) { //inner for loop to get each individual file
      vector<double> toSort = fileToVector(unsortedFiles[i][j]);
      string sortedFile = "sorted_"+unsortedFiles[i][j];
      double elapseTime = makeOutputFile(sortedFile,toSort);
      string exampleTimes = "example_times.txt";
      writeElapseTime(elapseTime, exampleTimes, toSort.size(), true);
      totalTime += elapseTime;
    }
    switch(i) { //switch statement to record average times for each goruping of files
      case 0:
        writeElapseTime(totalTime/25.0, avgTimeFile, 10, true);
        break;
      case 1:
        writeElapseTime(totalTime/25.0, avgTimeFile, 100, true);
        break;
      case 2:
        writeElapseTime(totalTime/25.0, avgTimeFile, 1000, true);
        break;
    }
  }
}

double makeOutputFile(string outputFile, vector<double> toSort) {
  ofstream writeToSorted(outputFile);
  if (!writeToSorted) {
    cerr << "cannot write to sorted ouput file";
    return -1;
  }
  auto start = high_resolution_clock::now(); //start time for quicksort
  quickSort(toSort, 0, toSort.size()-1);
  auto stop = high_resolution_clock::now(); //end time for quicksort

  for (int i = 0; i < toSort.size(); ++i) {
    writeToSorted << toSort[i] << " ";
  }
  writeToSorted.close();

  return duration<double, std::micro>(stop - start).count(); //return a double
                                                             //representation of the 
                                                             //difference between stop
                                                             //and start, shown in microseconds
}

void writeElapseTime(double microseconds, string ElapseTimeFile, int inputSize, bool example) {
  ofstream writeToTime;
  if (example) //if called by completeExample, need to append to file
    writeToTime.open(ElapseTimeFile, std::ios::app);
  else
    writeToTime.open(ElapseTimeFile);
  if (!writeToTime) {
    cerr << "cannot write to elapse time file";
    return;
  }
  if (std::filesystem::file_size(ElapseTimeFile) == 0) {//add titles only if file is empty
    writeToTime << "Input Size\texecution time\n" << inputSize << "\t\t\t\t" <<
                    microseconds << "\n";
  } else {
    writeToTime << inputSize << "\t\t\t\t" << microseconds << "\n";
  }
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
