#include <iostream>
using namespace std;

int main() {
  int num, sucet = 0;
  cin >> num;
  for (int i = 1; i <= num; i++) {
    sucet += i;
  }
  cout << sucet;
  return 0;
}
