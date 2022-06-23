// nacitanie do 3 vektorov
// najprv dievcata a potom chlapci, podmienka s funkciou pohlavie()

#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Pohlavie();
string Datum(int n);

int main(void) {
  fstream file_R("TXT-vstup-3.txt", ios::in);
  if (!file_R.is_open()) {
    return 1;
  }

  vector<int> rodne_cislo;
  vector<string> meno;
  int i = 0;

  while (!file_R.eof()) {
    int temp_int;
    file_R >> temp_int;
    rodne_cislo.push_back(temp_int);

    string temp_string;
    getline(file_R, temp_string); // ! zoberie aj medzeru, davaj si na to bacha
    meno.push_back(temp_string);

    i++;
  } // * nacita potrebne premenne - DONE

  // if dievca -- napise dievca, ak chlapec ide do else, to zistim funkciou
  // v pohlavie mi spocita aj kolko ich je
  int pocet = 0;
  bool once_g = true;
  bool once_b = true;
  for (int j = 0; j < i; j++) {
    if (Pohlavie()) { // je to dievca
      if (once_g){
        cout << "dievcat: " << pocet << endl; // vyries pocet ako premennu ktoru da raz chalanom a raz babam
        once_g = false;
      }
      cout << Datum(j) << meno[j] << endl;

    } else { // je to chlapec
    if (once_b){
        cout << "chlapcov: " << pocet << endl;
        once_b = false;
      }
      cout << Datum(j) << meno[j] << endl;
    }
  }
  // {
  //   
  // }
  return 0;

} // end of main

bool Pohlavie() { return false; }

string Datum(int n) {
  return "TEST";
}