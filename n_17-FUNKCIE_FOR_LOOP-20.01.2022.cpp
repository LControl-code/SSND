#include <iostream>
using namespace std;
int triangle_Right(int n) {
  for (int i = 1; i <= n; i++) {
    for (int e = n; e >= i; e--) {
      cout << "* ";
    }
    cout << endl;
  }
  return n;
}
int triangle_Left(int n) {
  for (int i = 1; i <= n; i++) {
    for (int e = 1; e <= n - i; e++) {
      cout << "  ";
    }
    for (int e = 1; e <= i; e++) {
      cout << "* ";
    }
    cout << endl;
  }
  return n;
}
int triangle_Downside_Right() {
  int n;
  cin >> n;
  cout << endl;
  for (int i = 1; i <= n; i++) {
    for (int e = n - i; e < n; e++) {
      cout << "* ";
    }
    cout << endl;
  }
  return n;
}
int triangle_Downside_Left(int n) {
  for (int i = n; i > 0; i--) {
    for (int e = n - i; e > 0; e--) {
      cout << "  ";
    }
    for (int r = i; r > 0; r--) {
      cout << "* ";
    }
    cout << endl;
  }
  return n;
}

int main() {
  int n;
  n = triangle_Downside_Right();
  cout << endl;
  n = triangle_Right(n);
  cout << endl;
  triangle_Left(n);
  cout << endl;
  n = triangle_Downside_Left(n);
  cout << endl;
  return 0;
}
