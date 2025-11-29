// Simion Cartis
#include "cartis_simion_quicksort.h"
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
using std::ifstream;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

static ofstream fileOut;
static random_device rd;
static mt19937 gen(rd());
static uniform_real_distribution<double> dist(-100.0, 100.0);

int main() {
  makeRanFiles(10);
  makeRanFiles(100);
  makeRanFiles(1000);

  return 0;
}

int makeRanFiles(int totalNums) {
  for (int i = 0; i < 25; ++i) {

    fileOut.open((to_string(totalNums)+"_randomNumbers_"+to_string(i+1)+".txt"));
    if (!fileOut) {
      cerr << "could not open file";
      return 1;
    }
    for (int i = 0; i < totalNums; ++i) {
      fileOut << dist(gen) << " ";
    }
    fileOut.close();
  }
  return 0;
}