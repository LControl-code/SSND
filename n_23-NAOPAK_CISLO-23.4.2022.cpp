#include <iostream>

using namespace std;

int main() {
  int num = 0;
  cin >> num;
  while (num != 0) {
    if (num % 10 != 0)
      cout << num % 10;
    num /= 10;
  }
  return 0;
}
