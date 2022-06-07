#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#ifdef WINDOWS
  #include <windows.h>
#else
  #include <unistd.h>
#endif

using namespace std;

// Global variables
bool game_end = false;
int exit_code;

// Prototypes
int mode_selection(int *_mode);
int volny_pad(int mode);
int vrh_nadol(int mode);
int vrh_nahor(int mode);
int vodorovny_vrh(int mode);
int sikmy_vrh(int mode);
void after_challenge(int mode);
void clearScreen();
void Sleep_fix(size_t time);


// class declaration
class Vzorec {
public:
  const float _g = 9.81; // m * s ^ -2
  float _t;              // sekunda
  float _v;              // m * s ^ -1
  float _v0;             // m * s ^ -1
  float _a;              // uhol alpha ako des. cislo, nie stupne
  float _h;              // meter
  float _s;              // meter

};

int main() {

  cout << fixed;
  cout.precision(2);

  int mode; // neccesarry for program

  do {
    try {

      mode_selection(&mode);

      switch (mode) {
      case 1: {
        // volny pad
        after_challenge(volny_pad(mode));
        break;
      }

      case 2: {
        // vrh nadol
        after_challenge(vrh_nadol(mode));

        break;
      }

      case 3: {
        // vrh nahor
        after_challenge(vrh_nahor(mode));

        break;
      }

      case 4: {
        // vodorovny vrh
        after_challenge(vodorovny_vrh(mode));

        break;
      }

      case 5: {
        // sikmy vrh
        after_challenge(sikmy_vrh(mode));

        break;
      }

      case 0:
      default: {
        game_end = true;
        break;
      }
      }

    }

    // Catching exceptions
    catch (const char *txtException) {
      game_end = true;
      exit_code = 120;
      cout << "\nError: " << txtException << "!" << endl;
    }

    catch (const int numException) {
      game_end = true;
      exit_code = numException;
      cout << "\nExit code: " << numException << endl;
    }

    catch (...) {
      game_end = true;
      exit_code = 123;
      cout << "\nUndefined exception, quiting . . . " << endl;
    }

  } while (!game_end);

  cout << "\nExiting!" << endl;
  return exit_code;
}

int mode_selection(int *_mode) {

  clearScreen();

  cout << "\n\nVyberte si prostredie pocitania:\n\n    1. Volny pad\n    2. "
          "Vrh nadol\n    3. Vrh nahor\n    4. Vodorovny vrh\n    5. Sikmy "
          "vrh\n\n  0. Koniec\n"
       << endl;
  cout << "Input (mode): ";
  cin >> *_mode;

  if (cin.fail() || *_mode < 0 || *_mode > 5)
    throw "Invalid input";

  return *_mode;

} // mode selection, safe

int volny_pad(int mode) {
  // s = 0.5 * g * pow(t,2);
  // v = g * t;

  Vzorec Volny_pad;
  clearScreen();
  cout << "\n\n## Volny pad (1) ##\n\n    1. Vypocet vzdialenosti v case\n    "
          "2. Vypocet rychlosti v case\n    3. Vypocet vysky s pociatocnou "
          "vyskou\n    4. Domov\n\n0. Konec\n"
       << endl;
  cout << "Input (mode):  ";
  cin >> mode;

  switch (mode) {
  case 1: {
    clearScreen();
    cout << "\n\n## Vypocet vzdialenosti v case ##" << endl;
    cout << "   * Potrebne parametre: cas (t)" << endl;
    cout << "Input (cas v sekundach):  ";
    cin >> Volny_pad._t;

    if (cin.fail())
      throw "Invalid time";

    Volny_pad._s = 0.5 * Volny_pad._g * Volny_pad._t; // vzorec

    cout << "\n ~ Za cas " << Volny_pad._t << " sekund prejde teleso volnym padom do vzdialenosti "
         << Volny_pad._s << " m" << endl;

    Sleep_fix(2);
    break;
  }
  case 2: {
    clearScreen();
    cout << "\n\n## Vypocet rychlosti v case ##" << endl;
    cout << "   * Potrebne parametre: cas (t)" << endl;
    cout << "Input (cas v sekundach):  ";
    cin >> Volny_pad._t;

    if (cin.fail())
      throw "Invalid time";

    Volny_pad._v = Volny_pad._g * Volny_pad._t; // vzorec

    cout << "\n ~ Za cas " << Volny_pad._t << " bude mat teleso rychlost "
         << Volny_pad._v << " m/s" << endl;

    Sleep_fix(2);
    break;
  }

  case 3: {
    clearScreen();
    cout << "\n\n## Vypocet vysky s pociatocnou vyskou ##" << endl;
    cout << "   * Potrebne parametre: pociatocna vyska (h), cas padu (t)"
         << endl;
    cout << "Input (vyska v metroch):  ";
    cin >> Volny_pad._h;

    if (cin.fail())
      throw "Invalid height";

    cout << "Input (cas v sekundach):  ";
    cin >> Volny_pad._t;

    if (cin.fail())
      throw "Invalid time";

    Volny_pad._s = Volny_pad._h - 0.5 * Volny_pad._g * pow(Volny_pad._t, 2);

    cout << "\n ~ Za cas " << Volny_pad._t << " (s) z vysky " << Volny_pad._h
         << " (m) bude teleso vo vyske " << (Volny_pad._s > 0 ? Volny_pad._s : 0) << " m" << endl;

    if (Volny_pad._s <= 0){
      cout << "   ~ Teleso dopadlo na zem "; // (-2.5 sekundy)

      float i = 0.0;
      Volny_pad._s = 0;
      while(Volny_pad._s >= 0) { // vypis sekund do padnutia telesa na zem
        Volny_pad._s = Volny_pad._h - 0.5 * Volny_pad._g * pow(i, 2);
        if(Volny_pad._s <= 0){
          cout <<"(" << i  << " sekundy, na h = 0)" << endl;
        }
        i += 0.01;
      }
    }
    
    Sleep_fix(2);
    break;
  }
  case 4: {
    mode = 0;
    break;
  }

  case 0: {
    game_end = true;
    break;
  }

  default: {
    // takes non-wanting arguments and annihilates them
    throw "Invalid argument";
  }
  }

  return mode;
}

int vrh_nadol(int mode) {
  // s = v * t + 0.2 * g * pow(t,2);
  // v = v0 + g * t;
  Vzorec Vrh_nadol;
  clearScreen();
  cout << "\n\n## Vrh nadol (2) ##\n\n    1. Vypocet vzdialenosti v case s "
          "pociatocnou rychlostou\n    2. Vypocet rychlosti za cas s "
          "pociatocnou rychlostou\n    4. Domov\n\n0. Konec\n"
       << endl;
  cout << "Input (mode):  ";
  cin >> mode;

  return mode;
}

int vrh_nahor(int mode) {
  // s = v * t - 0.2 * g * pow(t,2);
  // v = v0 - g * t;

  return mode;
}

int vodorovny_vrh(int mode) {
  // x = v0 * t
  // y = h - 0.5 * g * pow(t, 2);
  // v = sqrt(pow(v0, 2) + pow((g * t), 2));

  return mode;
}

int sikmy_vrh(int mode) {
  // x = v0 * t * cos(a);
  // y = v0 * t * sin(a) - 0.5 * g * pow(t, 2);

  return mode;
}

void after_challenge(int mode) {
  if (!game_end && mode) {
    cout << "\nPrajete si pokracovat vo vypocte? (Y/n)" << endl;

    char choice = '\0';

    cout << "Input (choice):  ";
    cin >> choice;

    if (choice == 'n' || choice == 'N') {
      game_end = true;
    } else if (choice != 'Y' && choice != 'y') {
      throw "Invalid choice";
    }
  }
  return;
}

void clearScreen() {
#ifdef WINDOWS
    system("cls"); // on windows

#else
    system("clear 2> /dev/null");
    cout << "\033[2J\033[1; 1H";
#endif
}

void Sleep_fix(size_t time) {
  #ifdef WINDOWS
    Sleep(time*1000)

  #else
    sleep(time);

  #endif
}
