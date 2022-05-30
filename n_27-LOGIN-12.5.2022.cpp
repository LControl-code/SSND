#include <fstream>
#include <iostream>
#define MAX 100
using namespace std;

int main() {

  string login[MAX] = {};
  int pocet = 0, prihlaseny[MAX] = {}, max = 0;

  ifstream fin("./login.txt");

  while (fin >> login[pocet]) {
    int i = 0;
    while (login[i] != login[pocet])
      i++;

    if (i == pocet)
      pocet++;
    prihlaseny[i]++;

    if (prihlaseny[i] > max) {
      max = prihlaseny[i];
    }
  }

  cout << "Pocet pouzivatelov: " << pocet << endl;
  cout << "Pouzivatel : pocet prihlaseni" << endl;
  for (int i = 0; i < pocet; i++) {
    cout << "Login cislo " << i + 1 << " sa prihlasil " << login[i] << " : "
         << prihlaseny[i] << endl;
  }
  cout << "Posledny prihlaseny: " << login[pocet - 1];
  return 0;
}
