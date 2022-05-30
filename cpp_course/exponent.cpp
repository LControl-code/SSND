// recreation of pow function
#include <iostream>
using namespace std;

long long power(long long baseNum, int powNum) {
  int result = 1;

  for (int i = 0; i < powNum; i++) {
    result *= baseNum;
  }

  return result;
}

int main() {

  cout << power(2, 16);
  return 0;
}