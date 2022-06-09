#include <fstream>
#include <iostream>

#define MAX 100
using namespace std;

int main() {

  fstream file_R("./TXT/TXT-cisla_2.txt", ios::in);

  int n[MAX] = {};
  int max = 0;
  int min = 0;
  int pocet = 0;
  bool once = true;

  while (file_R >> n[pocet]) {
    if (once) {
      max = n[pocet];
      min = n[pocet];
      once = !once;
    }

    if (n[pocet] > max)
      max = n[pocet];

    if (n[pocet] < min)
      min = n[pocet];

    pocet++;
  }

  file_R.close();

  if (pocet > 0) {
    cout << "minimum: " << min << endl;
    cout << "maximum: " << max << endl;
    cout << "pocet: " << pocet << endl;
  }

  return 0;
}
