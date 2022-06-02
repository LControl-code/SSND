#include <iostream>
using namespace std;

void test();

int main() {

  // * we can inicialize 2d array like this
  int numberGrid[3][2] = {{1, 2}, {3, 4}, {5, 6}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      cout << numberGrid[i][j] << ' '; // prints out all of the elements in the array
    }
  }

  return 0;
}
