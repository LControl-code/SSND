#include <iostream>
using namespace std;

// void printTriangle(int n) {
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < (n - 1) - i; j++) { // output whitespaces (n - 1) = 6
//       cout << " ";
//     }

//     for (int j = 0; j <= i; j++) { // output the triangle
//       if (j == 0 || j == i || i == n - 1) {
//         cout << "* ";
//       } else {
//         cout << "  ";
//       }

//     }
//     cout << endl;
//   }
// }

void printTriangle(int n) {
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < n - i; j++) { // output whitespaces (n - 1) = 6
      cout << " ";
    }

    for (int j = 0; j <= i; j++) { // output the triangle
      if (j == 0 || j == i || i == n) {
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