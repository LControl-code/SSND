#include <fstream>
#include <iostream>
#define MAX 100

using namespace std;

int main(void) {
  /**
  // * chcem aby to zobralo premenne zo suboru, kde bude
  // * meno a kolko nakupil, cize string a int
  // * vypise mi kto nakupil najviac a aka to bola hodnota
  // * potom vypise kto bol na nakupe najviac (cize je v subore viackrat)
  // * ak su viaceri tak ich vypise vsetkych, to plati aj o tom predtym

  * TODO: ziskat premenne zo suboru
  * TODO: Polia na pridavanie cien a poctu nakupov na pouzivatela
  * TODO: Vypisovanie
  **/

  string name[MAX] = {};
  int price_for_n[MAX] = {};
  int counter_1 = 0;
  int counter_n_shopping[MAX] = {};
  int max_price = 0;
  int max_counter_n = 0;

  fstream file_W("TXT-shop_list.txt", ios::in);
  if (!file_W.is_open()) {
    return EXIT_FAILURE;
  }

  // ! zapisovanie udajov
  while (file_W >> name[counter_1] >> price_for_n[counter_1]) {
    // zistujeme ci uz nahodou neexistuje
    int i = 0;
    while (name[i] != name[counter_1]) { //! naraznik
      i++; // ak to nebude counter_1 tak uz u nas nakupoval, vieme jeho index
    }

    counter_n_shopping[i]++; // toto  sa prida ci chce ci nechce
    if (counter_n_shopping[i] > max_counter_n) { //* max 1
      max_counter_n = counter_n_shopping[i];
    }

    if (i == counter_1) { // ak je novy tak moze zapisovat do noveho indexu, inak prepisujeme
      counter_1++;
    } else {
      price_for_n[i] += price_for_n[counter_1]; // pripisanie ceny existujucemu
    }

    if (price_for_n[i] > max_price) {
      max_price = price_for_n[i]; //* max 2
    }
  } // ukoncenie while - mame potrebne data

  file_W.close(); // uz nie je potrebne ho mat

  // ! vypisovanie
  cout << "Najviac nakupil/i:" << endl;
  for (int i = 0; i < counter_1; i++) {
    if (price_for_n[i] == max_price) {
      cout << " * " << name[i] << ", suma: " << price_for_n[i] << endl;
    }
  } //* ti co nakupili najviac, mozu byt viaceri

  cout << endl;

  cout << "Najvernejsi zakaznik:" << endl;
  for (int i = 0; i < counter_1; i++) {
    if (counter_n_shopping[i] == max_counter_n) {
      cout << " * " << name[i] << ", nakupy: " << counter_n_shopping[i] << endl;
    }
  }

  return EXIT_SUCCESS;
}