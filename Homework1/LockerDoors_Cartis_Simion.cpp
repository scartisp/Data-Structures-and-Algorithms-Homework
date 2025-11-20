// Simion Cartis
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<vector>
using std::vector;

int main() {
 // get user input for locker amount and passes
  cout << "input the amount of locker doors" << endl;
  int size;
  cin >> size;
  cout << "how many passes will you make?" << endl;
  int passes;
  cin >> passes;

 // fill vector
  vector<bool> lockers(size);
  for (int i = 0; i < size; ++i) {
    lockers[i] = false;
  }

  // go through vector i amount of times, if j + 1 (index + 1) % i+1 == 0, flip value 
  for (int i = 0; i < passes; ++i) {
    for (int j = 0; j < size; ++j) {
      if((j+1)%(i+1) == 0) {
        lockers[j] = !lockers[j];
      }
    }
  }

  // print out results to console
  int num_open = 0;
  for (int i = 0; i < size; ++i) {
    if (lockers[i] == true) { 
      cout << "locker " << i+1 << " is open" <<endl;
      ++num_open;
    } else {
    cout << "locker " << i+1 << " is closed" << endl;
    }
  }
  num_open != 1 ? cout << "there are " << num_open << " lockers opened" << endl :
  cout << "there is " << num_open << " locker opened" << endl;

  return 0;
}
