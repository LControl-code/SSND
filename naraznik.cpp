#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream fin;
  fin.open("telefony.txt");
  if (!fin.is_open())
    return EXIT_FAILURE;

  long long tel[100];
  long cas[100], max = 0;
  int pocet = 0;

  while (fin >> cas[pocet] >> tel[pocet]) { // nacitavame premenne
    int i = 0;
    while (tel[i] != tel[pocet]) i++; // hladame ci cislo existuje
    if (i == pocet) // pokial neexistuje tak zapisujeme, pretoze pocet zvacsime
      pocet++;
    else // telefon existuje, tak
      cas[i] += cas[pocet]; // inak nepridame telefon, tak pridame cas uz do existujuceho podla indexu i
    if (cas[i] > max) // hladanie maximalneho cisla
      max = cas[i];
  }
  fin.close(); // potrebne pre uvolnenie ram

  cout << max / 3600 << ':';
  int m = (max % 3600) / 60;
  if (m < 10)
    cout << 0;
  cout << m << ':';
  int s = max % 60;
  if (s < 10)
    cout << 0;
  cout << s;

  for (int i = 0; i < pocet; i++)
    if (cas[i] == max)
      cout << ' ' << tel[i];
  cout << endl;

  return 0;
}