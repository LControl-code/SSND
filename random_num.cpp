#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {

  srand(time(NULL));
  int min, max;
  cin >> min >> max;
  int i_rand_number;
  for(int i = 0; i < 50; i++) {
    i_rand_number = min + rand() % (max - min + 1);
    cout << i_rand_number << ' ';
  }

  return EXIT_SUCCESS;
}