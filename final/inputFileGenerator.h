//Simion Cartis
#ifndef _INPUT_FILE_GENERATOR_H_
#define _INPUT_FILE_GENERATOR_H_
#include <vector>
using std::vector;
#include <string>
using std::string;

vector<vector<string>> makeAllFiles();
int makeRanFiles(int totalNums, int rowInVector, vector<vector<string>>& unsortedFiles);
#endif