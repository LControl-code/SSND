#include <fstream>
#include <iostream>

#define MAX 100
using namespace std;

int main() {

  fstream file_R("./TXT/TXT-sloh.txt", ios::in);
  if (!file_R.is_open()) {
    return 1;
  }

  string sentence[MAX] = {};
  int pocet = 0;
  while (file_R >> sentence[pocet]) {
    pocet++;
  }

  file_R.close();

  for (int i = pocet - 1; i >= 0; i--) {
    cout << sentence[i] << ' ';
  }

  return 0;
}
