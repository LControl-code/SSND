#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Osoba {
  vector<string> meno;
  vector<string> rodne_cislo;
  vector<bool> pohlavie;
};

bool Pohlavie(string rodne_cislo);
string Datum(string rodne_cislo);

int main(void) {
  fstream file_R("TXT-vstup-3.txt", ios::in);
  if (!file_R.is_open()) {
    return 1;
  }
  Osoba osoba;
  int i = 0;

  while(!file_R.eof())  {
    string temp_int;
    file_R >> temp_int;
    osoba.rodne_cislo.push_back(temp_int); // vlozim do vektoru rodne_cislo
    osoba.pohlavie.push_back(Pohlavie(temp_int)); // vrati true/false podla pohlavia

    string temp_string;;
    getline(file_R, temp_string); // ! zoberie aj medzeru, davaj si na to bacha
    osoba.meno.push_back(temp_string);
    i++;
  } // * nacita potrebne premenne - DONE

  int pocet[2] = {0, 0};
  for (int j = 0; j < i; j++) {
    if (osoba.pohlavie[j] == true) {
      pocet[0]++;
    } else {
      pocet[1]++;
    }
  }

  cout << "Pocet dievcata: " << pocet[0] << endl;
  for (int j = 0; j < i; j++) {
    if (osoba.pohlavie[j] == true) {
      cout << Datum(osoba.rodne_cislo[j]) << osoba.meno[j] << endl;
    }
  }

  cout << endl;

  cout << "Pocet chlapcov: " << pocet[1] << endl;
  for (int j = 0; j < i; j++) {
    if (osoba.pohlavie[j] == false) {
      cout << Datum(osoba.rodne_cislo[j]) << osoba.meno[j] << endl;
    }
  }
  return 0;

} // end of main

bool Pohlavie(string rodne_cislo) {
  if (stoi(rodne_cislo.substr(2, 2)) > 50) {
    return true;

  } else {
    return false;
  }
}

string Datum(string rodne_cislo) {
  string datum = "";
  if (stoi(rodne_cislo.substr(0, 2)) < 22) {
    datum += "20";
  } else {
    datum += "19";
  }
  datum += rodne_cislo.substr(0, 2) + "-";

  int n = 0;
  if (stoi(rodne_cislo.substr(2, 2)) > 50) n = 50;

    if (stoi(rodne_cislo.substr(2, 2)) - n < 10) {
      datum += "0";
      datum += to_string(stoi(rodne_cislo.substr(2, 2)) - n) + "-"; // pod 10 muz ci zena
    } else {
      datum += to_string(stoi(rodne_cislo.substr(2, 2)) - n) + "-"; // nad 10 muz ci zena
    }
  
    datum += rodne_cislo.substr(4, 2);


  return datum;
}