#include <fstream>
#include <iostream>
#include <string>

#define MAX 200
using namespace std;

int main() {

  fstream file_R("./TXT/TXT-zoznam.txt", ios::in);
  if (!file_R.is_open()) {
    return 1;
  }

  string name[MAX] = {};
  string first_name[MAX] = {};
  int pocet = 0;
  int name_list[MAX] = {};
  bool new_name = true;

  while (getline(file_R, name[pocet])) {
    for (int i = 0; i < name[pocet].length(); i++) {

      if (name[pocet][i] == ' ') {
        break;
        new_name = true;
      } else {
        first_name[pocet] += name[pocet][i];
      }
    }
    int i = 0;
    while (first_name[i] != first_name[pocet])
      i++;

    if (i == pocet) {
      pocet++;
    } else {
      first_name[pocet] = {};
    }

    name_list[i]++;
  }
  file_R.close();

  for (int i = 0; i < pocet; i++) {
    cout << first_name[i] << ": " << name_list[i] << endl;
  }

  return 0;
}
