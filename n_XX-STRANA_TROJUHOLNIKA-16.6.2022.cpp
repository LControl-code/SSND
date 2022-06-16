#include <iostream>
using namespace std;

void printTriangle_up(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n - 1) - i; j++) { // output whitespaces (n - 1) = 6, keeping the last place for atherisk (*)
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

void printTriangle_down(int n) {
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < n - i; j++) { // output whitespaces (n - 1) = 6, keeping the last place for atherisk (*) on every row
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

  cout << "Enter 1 to print the triangle up, 2 to print the triangle down: ";
  int choice;
  cin >> choice;

  cout << "Enter the number of rows: ";
  int n;
  cin >> n;
  cout << endl;

  bool run = true;
  switch (choice) {
  case 1:
    while (run) {
      printTriangle_up(n);

      cout << endl << "Continue? (y/n): ";
      char c;
      cin >> c;

      if (c == 'n' || c == 'N') {
        run = false;
        continue;
      }

      cout << endl;
      cout << "Enter the number of rows: ";
      cin >> n;
      cout << endl;
    }
    break;

  case 2:
    while (run) {
      printTriangle_down(n);

      cout << endl << "Continue? (y/n): ";
      char c;
      cin >> c;

      if (c == 'n' || c == 'N') {
        run = false;
        continue;
      }

      cout << endl;
      cout << "Enter the number of rows: ";
      cin >> n;
      cout << endl;
    }
    break;
  }
  return 0;
}