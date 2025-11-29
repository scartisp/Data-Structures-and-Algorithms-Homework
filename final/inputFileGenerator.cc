// Simion Cartis
#include "inputFileGenerator.h"
#include <iostream>
using std::cerr;
#include <string>
using std::string;
using std::to_string;
#include <vector>
using std::vector;
#include <fstream>
using std::ofstream;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

static ofstream fileOut;
static random_device rd;
static mt19937 gen(rd());
static uniform_real_distribution<double> dist(-100.0, 100.0);


vector<vector<string>> makeAllFiles() {
  vector<vector<string>> unsortedFiles(3, vector<string>(25));
  makeRanFiles(10, 0, unsortedFiles);
  makeRanFiles(100, 1, unsortedFiles);
  makeRanFiles(1000, 2, unsortedFiles);
  return unsortedFiles;
}

int makeRanFiles(int totalNums, int rowInVector, vector<vector<string>>& unsortedFiles) {
  for (int i = 0; i < 25; ++i) {
    string name = to_string(totalNums)+"_randomNumbers_"+to_string(i+1)+".txt";
    unsortedFiles[rowInVector][i] = name;
    fileOut.open(name);
    if (!fileOut) {
      cerr << "could not open file";
      return 1;
    }
    for (int j = 0; j < totalNums; ++j) {
      fileOut << dist(gen) << " ";
    }
    fileOut.close();
  }
  return 0;
}