#include <fstream>
#include <iostream>
using namespace std;

int main() {

  ifstream call("./test-19.5.22/call.txt");
  if (!call)
    return 1;

  long trvanie_hovoru[100] = {};
  string telefonne_cislo[100] = {};
  int pocet = 0;
  int max = 0;
  int pocet_telefonatov[100] = {};
  int max_pocet_tel = 0;

  while (call >> trvanie_hovoru[pocet] >> telefonne_cislo[pocet]) {
    // najvacsi pocet hovorov, plus ak je to ten isty tak pripocitat k nemu
    int i = 0;
    while (telefonne_cislo[i] != telefonne_cislo[pocet])
      i++; // najde occurence

    if (i == pocet)
      pocet++;
    else
      trvanie_hovoru[i] += trvanie_hovoru[pocet];
    if (trvanie_hovoru[i] > max) {
      max = trvanie_hovoru[i];
    }
    pocet_telefonatov[i]++;
    if (pocet_telefonatov[i] > max) {
      max_pocet_tel = pocet_telefonatov[i];
    }
  }

  call.close();

  bool time = true;
  for (int i = 0; i < pocet; i++) {

    if (trvanie_hovoru[i] == max) {
      if (time) {
        time = false;
        int num = 3600;
        while (trvanie_hovoru[i] > 0) {
          if (trvanie_hovoru[i] / num > 0) {
            if (trvanie_hovoru[i] / num < 10) {
              cout << "0";
            }
            cout << trvanie_hovoru[i] / num;
            trvanie_hovoru[i] -= (trvanie_hovoru[i] / num) * num;
          } else {
            cout << "0";
          }
          if (trvanie_hovoru[i] > 0) {
            cout << ":";
          }
          num /= 60;
        }
      }
      cout << "  " << telefonne_cislo[i];

      cout << "Najviac telefonatov: ";
      if (pocet_telefonatov[i] == max_pocet_tel) {
        cout << telefonne_cislo[i] << "  ";
      }
    }
  }

  return 0;
}
