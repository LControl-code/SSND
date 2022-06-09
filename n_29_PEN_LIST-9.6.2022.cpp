#include <fstream>
#include <iostream>
#include <string>

#define MAX 200

int main() {

  std::fstream file_R("./TXT/TXT-zoznam.txt", std::ios::in);
  if (!file_R.is_open()) {
    return 1;
  }

  std::string name[MAX] = {};
  std::string first_name[MAX] = {};
  int pocet = 0;
  int name_list[MAX] = {};
  bool new_name = true;
  
  // ucitelova metoda, lahsia
  std::string text;
  while (file_R >> name[pocet]) {
    std::getline(file_R, text);
    int i = 0;
    while (name[i] != name[pocet])
      i++;

    if (i == pocet) {
      pocet++;
    }

    name_list[i]++;
  }

  file_R.close();

  for (int i = 0; i < pocet; i++) {
    std::cout << name[i] << ": " << name_list[i] << std::endl;
  }
  // 
  // MOJA METODA
  //
  // while (std::getline(file_R, name[pocet])) {
  //   for (int i = 0; i < name[pocet].length(); i++) {

  //     if (name[pocet][i] == ' ') {
  //       break;
  //       new_name = true;
  //     } else {
  //       first_name[pocet] += name[pocet][i];
  //     }
  //   }
  //   int i = 0;
  //   while (first_name[i] != first_name[pocet])
  //     i++;

  //   if (i == pocet) {
  //     pocet++;
  //   } else {
  //     first_name[pocet] = {};
  //   }

  //   name_list[i]++;
  // }
  // file_R.close();

  // for (int i = 0; i < pocet; i++) {
  //   std::cout << first_name[i] << ": " << name_list[i] << std::endl;
  // }
  

  return 0;
}
