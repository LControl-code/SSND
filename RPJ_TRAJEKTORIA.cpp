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
int Vrh_nahor(int mode);
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
        after_challenge(Vrh_nahor(mode));

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
} // for getting to different states of throws

int mode_selection(int *_mode) {

  clearScreen();

  cout << R"(

Vyberte si prostredie pocitania:

    1. Volny pad
    2. Vrh nadol
    3. Vrh nahor
    4. Vodorovny vrh
    5. Sikmy vrh

  0. Koniec
)" << endl;
  cout << "Input (mode): ";
  cin >> *_mode;

  if (cin.fail() || *_mode < 0 || *_mode > 5)
    throw "Invalid input";

  return *_mode;

} // * mode selection, safe

int volny_pad(int mode) {
  // s = 0.5 * g * pow(t,2);
  // v = g * t;

  Vzorec Volny_pad;
  clearScreen();
  cout << R"(

## Volny pad (1) ##

    1. Vypocet vzdialenosti v case
    2. Vypocet rychlosti v case
    3. Vypocet vysky s pociatocnou vyskou
    4. Domov

0. Konec
)" << endl;
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

    if (Volny_pad._s <= 0) {
      cout << "   ~ Teleso dopadlo na zem "; // (-2.5 sekundy)

      float i = 0.0;
      if (Volny_pad._s < -1) {
        do { // vypis sekund do padnutia telesa na zem
          Volny_pad._s = Volny_pad._h - 0.5 * Volny_pad._g * pow(i, 2);
          if (Volny_pad._s <= 0) {
            cout << "(" << i << " sekundy, na h = 0)";
          }
          i += 0.01;
        } while (Volny_pad._s >= 0);
      }
    cout << endl;
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
} // * done

int Vrh_nahor(int mode) {
  // s = v * t + 0.2 * g * pow(t,2);
  // v = v0 + g * t;
  Vzorec Vrh_nadol;
  clearScreen();
  cout << R"(

## Vrh nadol (2) ##

    1. Vypocet vzdialenosti v case s pociatocnou rychlostou
    2. Vypocet rychlosti za cas s pociatocnou rychlostou
    3. Vypocet vysky s pociatocnou vyskou a rychlostou
    4. Domov

0. Konec
)" << endl;
  cout << "Input (mode):  ";
  cin >> mode;

  switch (mode) {
  case 1: {
    clearScreen();
    Vzorec Vrh_nadol;
    cout << R"(

## Vypocet rychlosti za cas s pociatocnou rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0))"
         << endl;
    
    cout << "Input (cas v sekundach):  ";
    cin >> Vrh_nadol._t;

    if (cin.fail())
      throw "Invalid time";

    cout << "Input (pociatocna rychlost v m/s):  ";
    cin >> Vrh_nadol._v0;

    if (cin.fail())
      throw "Invalid starting speed";

    // ! d = v0 . t + 1/2 . g . t^2
    Vrh_nadol._s = Vrh_nadol._v0 * Vrh_nadol._t + 0.5 * Vrh_nadol._g * pow(Vrh_nadol._t, 2);

    cout << "\n   ~ Za cas " << Vrh_nadol._t << " padne teleso s pociatocnou rychlostou " << Vrh_nadol._v0 << " m/s, do hlbky " << Vrh_nadol._s << " m." << endl;
    Sleep_fix(2);
    break;
  }
  case 2: {
    // v = v0 + g . t
    clearScreen();
    Vzorec Vrh_nadol;
    cout << R"(

## Vypocet rychlosti za cas s pociatocnou rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0))"
         << endl;
    cout << "Input (cas v sekundach):  ";
    cin >> Vrh_nadol._t;

    if (cin.fail())
      throw "Invalid time";

    cout << "Input (pociatocna rychlost v m/s):  ";
    cin >> Vrh_nadol._v0;

    if (cin.fail())
      throw "Invalid starting speed";


    Vrh_nadol._v = Vrh_nadol._v0 + Vrh_nadol._g * Vrh_nadol._t;
    cout << "\n   ~ Za cas << " << Vrh_nadol._t<< " sekund bude mat teleso s pociatocnou rychlostou " << Vrh_nadol._v0 << " m/s, rychlost " << Vrh_nadol._v << " m/s." << endl;
    Sleep_fix(2);

    break;
  }
  case 3: {
    clearScreen();
    Vzorec Vrh_nadol;
    cout << R"(

## Vypocet vysky s pociatocnou vyskou a rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0), pociatocna vyska (h))"
         << endl;
    cout << "Input (cas v sekundach):  ";
    cin >> Vrh_nadol._t;
    cout << "Input (pociatocna rychlost v m/s):  ";
    cin >> Vrh_nadol._v0;
    cout << "Input (pociatocna vyska v m):  ";
    cin >> Vrh_nadol._h;

    //! d = h - (v0 . t + 1/2 . g . t^2)
    Vrh_nadol._s = Vrh_nadol._h - (Vrh_nadol._v0 * Vrh_nadol._t + 0.5 * Vrh_nadol._g * pow(Vrh_nadol._t, 2));
    cout << "\n   ~ Za cas " << Vrh_nadol._t
         << " sekund bude teleso s pociatocnou rychlostou " << Vrh_nadol._v0
         << " m/s vo vyske " << (Vrh_nadol._s > 0 ? Vrh_nadol._s : 0) << " m."
         << endl;

    if (Vrh_nadol._s <= 0) {
      cout << "   ~ Teleso dopadlo na zem "; // (-2.5 sekundy)

      float i = 0.0;
      if (Vrh_nadol._s < -1) {
        do { // vypis sekund do padnutia telesa na zem
          Vrh_nadol._s = Vrh_nadol._h - 0.5 * Vrh_nadol._g * pow(i, 2);
          if (Vrh_nadol._s <= 0) {
            cout << "(" << i << " sekundy, na h = 0)";
          }
          i += 0.01;
        } while (Vrh_nadol._s >= 0);
      }
      cout << endl;
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

    throw "Invalid argument";
    break;
  }
  }
  return mode;
} // * done

int vrh_nahor(int mode) {
  // s = v * t - 0.2 * g * pow(t,2);
  // v = v0 - g * t;

  clearScreen();
  Vzorec Vrh_nahor;
  cout << R"(

## Vrh nahor (3) ##

    1. Vypocet vysky za cas s pociatocnou rychlostou
    2. Vypocet rychlosti za cas s pociatocnou rychlostou
    3. Vypocet vysky s pociatocnou vyskou a rychlostou
    4. Domov

0. Konec
)" << endl;
  cout << "Input (mode):  ";
  cin >> mode;

  switch (mode) {
  case 1: {
    // v = v0 - g . t
    clearScreen();
    cout << R"(


## Vypocet rychlosti za cas s pociatocnou rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0))"
         << endl;

    cout << "Input (cas v sekundach):  ";
    cin >> Vrh_nahor._t;

    if (cin.fail())
      throw "Invalid time";

    cout << "Input (pociatocna rychlost v m/s):  ";
    cin >> Vrh_nahor._v0;

    if (cin.fail())
      throw "Invalid starting speed";

    // ! d = v0 . t + 1/2 . g . t^2
    Vrh_nahor._s = Vrh_nahor._v0 * Vrh_nahor._t - 0.5 * Vrh_nahor._g * pow(Vrh_nahor._t, 2);

    cout << "\n   ~ Za cas " << Vrh_nahor._t
         << " vystupy teleso s pociatocnou rychlostou " << Vrh_nahor._v0
         << " m/s, do vysky " << (Vrh_nahor._s > 0 ? Vrh_nahor._s : 0) << " m."
         << endl;

    if (Vrh_nahor._s <= 0) {
      cout << "   ~ Teleso dopadlo na zem "; // (-2.5 sekundy)

      float i = 0.0;
      if (Vrh_nahor._s < -1) {
        do { // vypis sekund do padnutia telesa na zem
          Vrh_nahor._s = Vrh_nahor._h - 0.5 * Vrh_nahor._g * pow(i, 2);
          if (Vrh_nahor._s <= 0) {
            cout << "(" << i << " sekundy, na h = 0)";
          }
          i += 0.01;
        } while (Vrh_nahor._s >= 0);
      }
      cout << endl;
    }
    Sleep_fix(2);
    break;
  }
  case 2: {
    clearScreen();
    cout << R"(

## Vypocet rychlosti za cas s pociatocnou rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0))"
         << endl;
    cout << "Input (cas v sekundach):  ";
    cin >> Vrh_nahor._t;

    if (cin.fail())
      throw "Invalid time";

    cout << "Input (pociatocna rychlost v m/s):  ";
    cin >> Vrh_nahor._v0;

    if (cin.fail())
      throw "Invalid starting speed";


    Vrh_nahor._v = Vrh_nahor._v0 - Vrh_nahor._g * Vrh_nahor._t;
    cout << "\n   ~ Za cas << " << Vrh_nahor._t<< " sekund bude mat teleso s pociatocnou rychlostou " << Vrh_nahor._v0 << " m/s, rychlost " << (Vrh_nahor._v > 0 ? Vrh_nahor._v : 0) << " m/s." << endl;
    Sleep_fix(2);
    break;

  }
  case 3: {
    clearScreen();
    Vzorec Vrh_nahor;
  }
  case 4: {
    mode = 0;
    break;
  }
  case 0: {
    game_end = true;
    break;
  }
  }
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
    cout << R"(
Prajete si pokracovat vo vypocte? (Y/n))"
         << endl;

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
    if(!system("echo $?")){
      cout << "\033[2J\033[1; 1H";
    }
#endif
}

void Sleep_fix(size_t time) {
  #ifdef WINDOWS
    Sleep(time*1000)

  #else
    sleep(time);

  #endif
} // * done