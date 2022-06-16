#include <fstream>
#include <iostream>
#include <string>

#define MAX 200

int main() {

  std::fstream file_R("./TXT/TXT-zoznam.txt", std::ios::in);
  if (!file_R.is_open()) { // ak sa subor nepodarilo otvorit
    return 1;
  }

  std::string name[MAX] = {};
  std::string first_name[MAX] = {};
  int pocet = 0;
  int name_list[MAX] = {};
  
  /*
  * MOJA METODA
  */
  while (std::getline(file_R, name[pocet])) {
    for (int i = 0; i < name[pocet].length(); i++) {

      if (name[pocet][i] == ' ') {
        break;
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
    std::cout << first_name[i] << ": " << name_list[i] << " (pen/s)" << std::endl;
  }

  /*
   * UCITELOVA METODA
  */
  // std::string text;
  // while (file_R >> name[pocet]) {
  //   std::getline(file_R, text); 
  //   int i = 0;
  //   while (name[i] != name[pocet]) // najde poziciu v poli pre danu meno
  //     i++;

  //   if (i == pocet) { // ak nenajde, prida nove meno do pola
  //     pocet++;
  //   }

  //   name_list[i]++;
  // }

  // file_R.close();

  // for (int i = 0; i < pocet; i++) { // vypis vsetkych mien
  //   std::cout << name[i] << ": " << name_list[i] << std::endl;
  // }
  

  return 0;
}
