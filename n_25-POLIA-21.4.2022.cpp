#include <fstream>
#include <iostream>
#define MAX 100
using namespace std;

int main() {
  ifstream pokladna("./fstream/items/pokladne/pokladne.txt");
  float suma1 = 0.0, suma2 = 0.0, suma3 = 0.0, pocet1 = 0, pocet2 = 0,
        pocet3 = 0;
  int p = 0, s = 0;
  double suma[MAX] = {};
  int pocet[MAX] = {};
  while (pokladna >> p >> s) {

    if (p <= 3) {
      suma[s] += s;
      pocet[p]++;
    } else {
      cout << "Pokladna " << p << " neexistuje";
    }
  }
  pokladna.close();

  for (int i = 0; i < pocet1; i++)
    if (pocet[i])
      cout << "Pokladna c. " << i << " - pocet nakupov: " << pocet[i]
           << ", suma: " << suma[i] << " EUR\n";

  return 0;
}
