#include <iostream>
using namespace std;

void printTriangle(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n - 1) - i; j++) { // output whitespaces
      cout << " ";
    }

    for (int j = 0; j <= i; j++) { // output the triangle
      if (j == 0 || j == i || i == n - 1) {
        cout << "* ";
      } else {
        cout << "  ";
      }

    }
    cout << endl;
  }
}

int main() {

  cout << "Enter the number of rows: ";
  int n;
  cin >> n;
  printTriangle(n);
  return 0;
}