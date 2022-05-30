#include <iostream>
using namespace std;

int main() {
  int num = 1, pocet = -1, sucet = 0, max = 0;
  double priemer = 0;
  do {
    cin >> num;
    pocet++;
    if (num > max)
      max = num;
    sucet += num;
  } while (num != 0);
  priemer = float(sucet) / pocet;
  cout << fixed;
  cout.precision(2);
  cout << pocet << " znamok, priemer " << priemer << ",";

  if (priemer < 1.5 && max < 3)
    cout << " prospel s vyznamenanim";
  else if (priemer < 2 && max < 4)
    cout << " prospel velmi dobre";
  else if (max == 5)
    cout << " prospel";
  else
    cout << " neprospel";
  return 0;
}
