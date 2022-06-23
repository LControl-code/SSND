#include <fstream>
#include <ios>
#include <iostream>
using namespace std;

void KresliTrojuholnik(int n);

int main() {
  fstream file_R("TXT-vstup-2.txt", ios::in);
  if(!file_R.is_open()) return 1;
  int n;

  while (file_R >> n) {
    KresliTrojuholnik(n);
    cout << endl;
  }

  file_R.close();
  return 0;
}

void KresliTrojuholnik(int n) {
  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n - i; j++) { // whitespace
      cout << "  "; // 2 spaces
    }

    for (int j = 0; j <= i; j++) { // asterisks
      if (j == 0 || i == n - 1 || j == i)
        cout << "* ";
      else
        cout << "  "; // 2 spaces
    }
    cout << endl;
  }
}