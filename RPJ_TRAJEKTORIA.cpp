#include <cmath>
#include <iostream>
#include <algorithm>

#ifdef WINDOWS
  #include <windows.h>
#else
  #include <unistd.h>
#endif

// Global variables
bool game_end = false;
int exit_code;

// Prototypes
int mode_selection(int *_mode);
int volny_pad(int mode);
int Vodorovny_vrh(int mode);
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
  float _t = 0.;              // sekunda
  float _v = 0.;              // m * s ^ -1
  float _v0 = 0.;             // m * s ^ -1
  float _a = 0.;              // uhol alpha ako des. cislo, nie stupne
  float _h = 0.;              // meter
  float _s = 0.;              // meter
  float _x = 0.;              // meter
  float _y = 0.;              // meter

};

int main() {

  std::cout << std::fixed;
  std::cout.precision(2);

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
        after_challenge(Vodorovny_vrh(mode));

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
      std::cout << "\nError: " << txtException << "!" << std::endl;
    }

    catch (const int numException) {
      game_end = true;
      exit_code = numException;
      std::cout << "\nExit code: " << numException << std::endl;
    }

    catch (...) {
      game_end = true;
      exit_code = 123;
      std::cout << "\nUndefined exception, quiting . . . " << std::endl;
    }

  } while (!game_end);

  std::cout << "\nExiting!" << std::endl;
  return exit_code;
} // for getting to different states of throws

int mode_selection(int *_mode) {

  clearScreen();

  std::cout << R"(

Vyberte si prostredie pocitania:

    1. Volny pad
    2. Zvisly vrh nadol
    3. Zvisly vrh nahor
    4. Vodorovny vrh
    5. Sikmy vrh

  0. Koniec
)" << std::endl;
  std::cout << "Input (mode): ";
  std::cin >> *_mode;

  if (std::cin.fail() || *_mode < 0 || *_mode > 5)
    throw "Invalid input";

  return *_mode;

} // * mode selection, safe

int volny_pad(int mode) {
  // s = 0.5 * g * pow(t,2);
  // v = g * t;

  
  clearScreen();
  std::cout << R"(

## Volny pad (1) ##

    1. Vypocet vzdialenosti v case
    2. Vypocet rychlosti v case
    3. Vypocet vysky s pociatocnou vyskou
    4. Domov

0. Konec
)" << std::endl;
  std::cout << "Input (mode):  ";
  std::cin >> mode;

  switch (mode) {
  case 1: {
    clearScreen();
    Vzorec Volny_pad;
    std::cout << "\n\n## Vypocet vzdialenosti v case ##" << std::endl;
    std::cout << "   * Potrebne parametre: cas (t)" << std::endl;
    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Volny_pad._t;

    if (std::cin.fail())
      throw "Invalid time";

    Volny_pad._s = 0.5 * Volny_pad._g * Volny_pad._t; // vzorec

    std::cout << "\n ~ Za cas " << Volny_pad._t << " sekund prejde teleso volnym padom do vzdialenosti "
         << Volny_pad._s << " m" << std::endl;

    Sleep_fix(2);
    break;
  }
  case 2: {
    clearScreen();
    Vzorec Volny_pad;
    std::cout << "\n\n## Vypocet rychlosti v case ##" << std::endl;
    std::cout << "   * Potrebne parametre: cas (t)" << std::endl;
    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Volny_pad._t;

    if (std::cin.fail())
      throw "Invalid time";

    Volny_pad._v = Volny_pad._g * Volny_pad._t; // vzorec

    std::cout << "\n ~ Za cas " << Volny_pad._t << " bude mat teleso rychlost "
         << Volny_pad._v << " m/s" << std::endl;

    Sleep_fix(2);
    break;
  }

  case 3: {
    clearScreen();
    Vzorec Volny_pad;
    std::cout << "\n\n## Vypocet vysky s pociatocnou vyskou ##" << std::endl;
    std::cout << "   * Potrebne parametre: pociatocna vyska (h), cas padu (t)"
         << std::endl;
    std::cout << "Input (vyska v metroch):  ";
    std::cin >> Volny_pad._h;

    if (std::cin.fail())
      throw "Invalid height";

    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Volny_pad._t;

    if (std::cin.fail())
      throw "Invalid time";

    Volny_pad._s = Volny_pad._h - 0.5 * Volny_pad._g * pow(Volny_pad._t, 2);

    std::cout << "\n ~ Za cas " << Volny_pad._t << " (s) z vysky " << Volny_pad._h
         << " (m) bude teleso vo vyske " << (Volny_pad._s > 0 ? Volny_pad._s : 0) << " m" << std::endl;

    if (Volny_pad._s <= 0) {
      std::cout << "   ~ Teleso dopadlo na zem "; // (-2.5 sekundy)

      float i = 0.0;
      if (Volny_pad._s < -1) {
        do { // vypis sekund do padnutia telesa na zem
          Volny_pad._s = Volny_pad._h - 0.5 * Volny_pad._g * pow(i, 2);
          if (Volny_pad._s <= 0) {
            std::cout << "(" << i << " sekundy, na h = 0)";
          }
          i += 0.01;
        } while (Volny_pad._s >= 0);
      }
    std::cout << std::endl;
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

int Vodorovny_vrh(int mode) {
  // s = v * t + 0.2 * g * pow(t,2);
  // v = v0 + g * t;
  
  clearScreen();
  std::cout << R"(

## Zvisly vrh nadol (2) ##

    1. Vypocet vzdialenosti v case s pociatocnou rychlostou
    2. Vypocet rychlosti za cas s pociatocnou rychlostou
    3. Vypocet vysky s pociatocnou vyskou a rychlostou
    4. Domov

0. Konec
)" << std::endl;
  std::cout << "Input (mode):  ";
  std::cin >> mode;

  switch (mode) {
  case 1: {
    clearScreen();
    Vzorec Vrh_nadol;
    std::cout << R"(

## Vypocet rychlosti za cas s pociatocnou rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0))"
         << std::endl;
    
    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Vrh_nadol._t;

    if (std::cin.fail())
      throw "Invalid time";

    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Vrh_nadol._v0;

    if (std::cin.fail())
      throw "Invalid starting speed";

    // ! d = v0 . t + 1/2 . g . t^2
    Vrh_nadol._s = Vrh_nadol._v0 * Vrh_nadol._t + 0.5 * Vrh_nadol._g * pow(Vrh_nadol._t, 2);

    std::cout << "\n   ~ Za cas " << Vrh_nadol._t << " padne teleso s pociatocnou rychlostou " << Vrh_nadol._v0 << " m/s, do hlbky " << Vrh_nadol._s << " m." << std::endl;
    Sleep_fix(2);
    break;
  }
  case 2: {
    // v = v0 + g . t
    clearScreen();
    Vzorec Vrh_nadol;
    std::cout << R"(

## Vypocet rychlosti za cas s pociatocnou rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0))"
         << std::endl;
    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Vrh_nadol._t;

    if (std::cin.fail())
      throw "Invalid time";

    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Vrh_nadol._v0;

    if (std::cin.fail())
      throw "Invalid starting speed";


    Vrh_nadol._v = Vrh_nadol._v0 + Vrh_nadol._g * Vrh_nadol._t;
    std::cout << "\n   ~ Za cas " << Vrh_nadol._t<< " sekund bude mat teleso s pociatocnou rychlostou " << Vrh_nadol._v0 << " m/s, rychlost " << Vrh_nadol._v << " m/s." << std::endl;
    Sleep_fix(2);

    break;
  }
  case 3: {
    clearScreen();
    Vzorec Vrh_nadol;
    std::cout << R"(

## Vypocet vysky s pociatocnou vyskou a rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0), pociatocna vyska (h))"
         << std::endl;
    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Vrh_nadol._t;
    if(std::cin.fail())
      throw "Invalid time";

    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Vrh_nadol._v0;
    if(std::cin.fail())
      throw "Invalid starting speed";

    std::cout << "Input (pociatocna vyska v m):  ";
    std::cin >> Vrh_nadol._h;
    if(std::cin.fail())
      throw "Invalid starting height";

    //! d = h - (v0 . t + 1/2 . g . t^2)
    Vrh_nadol._s = Vrh_nadol._h - (Vrh_nadol._v0 * Vrh_nadol._t + 0.5 * Vrh_nadol._g * pow(Vrh_nadol._t, 2));
    std::cout << "\n   ~ Za cas " << Vrh_nadol._t
         << " sekund bude teleso s pociatocnou rychlostou " << Vrh_nadol._v0
         << " m/s vo vyske " << (Vrh_nadol._s > 0 ? Vrh_nadol._s : 0) << " m."
         << std::endl;

    if (Vrh_nadol._s <= 0) {
      std::cout << "   ~ Teleso dopadlo na zem "; // (-2.5 sekundy)

      float i = 0.0;
      if (Vrh_nadol._s < -1) {
        do { // vypis sekund do padnutia telesa na zem
          Vrh_nadol._s = Vrh_nadol._h - (Vrh_nadol._v0 * i + 0.5 * Vrh_nadol._g * pow(i, 2));
          if (Vrh_nadol._s <= 0) {
            std::cout << "(" << i << " sekundy, na h = 0)";
          }
          i += 0.01;
        } while (Vrh_nadol._s >= 0);
      }
      std::cout << std::endl;
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
  
  std::cout << R"(

## Zvisly vrh nahor (3) ##

    1. Vypocet vysky za cas s pociatocnou rychlostou
    2. Vypocet rychlosti za cas s pociatocnou rychlostou
    3. Vypocet vysky s pociatocnou vyskou a rychlostou
    4. Domov

0. Konec
)" << std::endl;
  std::cout << "Input (mode):  ";
  std::cin >> mode;

  switch (mode) {
  case 1: {
    // v = v0 - g . t
    clearScreen();
    Vzorec Vrh_nahor;
    std::cout << R"(


## Vypocet vysky za cas s pociatocnou rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0))"
         << std::endl;

    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Vrh_nahor._t;

    if (std::cin.fail())
      throw "Invalid time";

    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Vrh_nahor._v0;

    if (std::cin.fail()) // vyhodenie vynimky ak sa nenacita spravne cislo
      throw "Invalid starting speed";

    // ! d = v0 . t + 1/2 . g . t^2
    Vrh_nahor._s = Vrh_nahor._v0 * Vrh_nahor._t - 0.5 * Vrh_nahor._g * pow(Vrh_nahor._t, 2);

    std::cout << "\n   ~ Za cas " << Vrh_nahor._t
         << " vystupy teleso s pociatocnou rychlostou " << Vrh_nahor._v0
         << " m/s, do vysky " << (Vrh_nahor._s > 0 ? Vrh_nahor._s : 0) << " m."
         << std::endl;

    if (Vrh_nahor._s <= 0) {
      std::cout << "   ~ Teleso dopadlo na zem "; // (-2.5 sekundy)

      float i = 0.0;
      if (Vrh_nahor._s < -1) {
        do { // vypis sekund do padnutia telesa na zem
          Vrh_nahor._s = Vrh_nahor._v0 * i - 0.5 * Vrh_nahor._g * pow(i, 2);
          if (Vrh_nahor._s <= 0) {
            std::cout << "(" << i << " sekundy, na h = 0)";
          }
          i += 0.01;
        } while (Vrh_nahor._s >= 0);
      }
      std::cout << std::endl;
    }
    Sleep_fix(2);
    break;
  }
  case 2: {
    clearScreen();
    Vzorec Vrh_nahor;
    std::cout << R"(

## Vypocet rychlosti za cas s pociatocnou rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0))"
         << std::endl;
    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Vrh_nahor._t;

    if (std::cin.fail())
      throw "Invalid time";

    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Vrh_nahor._v0;

    if (std::cin.fail())
      throw "Invalid starting speed";


    Vrh_nahor._v = Vrh_nahor._v0 - Vrh_nahor._g * Vrh_nahor._t;
    std::cout << "\n   ~ Za cas " << Vrh_nahor._t<< " sekund bude mat teleso s pociatocnou rychlostou " << Vrh_nahor._v0 << " m/s, rychlost " << (Vrh_nahor._v > 0 ? Vrh_nahor._v : Vrh_nahor._v * -1) << " m/s" << (Vrh_nahor._v > 0 ? "." : " (smerom dole)") << std::endl;
    Sleep_fix(2);
    break;

  }
  case 3: {
    clearScreen();
    Vzorec Vrh_nahor;
    std::cout << R"(

## Vypocet vysky s pociatocnou vyskou a rychlostou ##
    * Potrebne parametre: cas (t), pociatocna rychlost (v0), pociatocna vyska (h0))"
         << std::endl;
         
    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Vrh_nahor._t;

    if (std::cin.fail())
      throw "Invalid time";

    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Vrh_nahor._v0;

    if (std::cin.fail()) // vyhodenie vynimky ak sa nenacita spravne cislo
      throw "Invalid starting speed";

    std::cout << "Input (pociatocna vyska v m):  ";
    std::cin >> Vrh_nahor._h;

    if (std::cin.fail())
      throw "Invalid starting height";


    // ! d = h0 - (v0 . t + 1/2 . g . t^2)
    Vrh_nahor._s = Vrh_nahor._h + (Vrh_nahor._v0 * Vrh_nahor._t - 0.5 * Vrh_nahor._g * pow(Vrh_nahor._t, 2));

    std::cout << "\n   ~ Za cas " << Vrh_nahor._t
         << " vystupy teleso s pociatocnou rychlostou " << Vrh_nahor._v0
         << " m/s a pociatocnou vyskou " << Vrh_nahor._h << " m, do vysky " << (Vrh_nahor._s > 0 ? Vrh_nahor._s : 0) << " m."
         << std::endl;

    if (Vrh_nahor._s <= 0) {
      std::cout << "   ~ Teleso dopadlo na zem "; // (-2.5 sekundy)

      float i = 0.0; // pocitadlo sekund
      if (Vrh_nahor._s < -1) {
        do { // vypis sekund do padnutia telesa na zem
          Vrh_nahor._s = Vrh_nahor._h + (Vrh_nahor._v0 * i - 0.5 * Vrh_nahor._g * pow(i, 2));
          if (Vrh_nahor._s <= 0) {
            std::cout << "(" << i << " sekundy, na h = 0)";
          }
          i += 0.01;
        } while (Vrh_nahor._s >= 0);
      }
      std::cout << std::endl;
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
  }
  return mode;
}

int vodorovny_vrh(int mode) {
  // x = v0 * t
  // y = h - 0.5 * g * pow(t, 2);
  // v = sqrt(pow(v0, 2) + pow((g * t), 2));
  
  clearScreen();
  std::cout << R"(

## Vodorovny vrh (4) ##

    1. Vypocet vzdialenosti dopadu telesa na zem
    2. Vypocet casu dopadu telesa na zem
    3. Vypocet suradnic telesa za cas (v zakladnych jednotkach)
    4. Vypocet rychlosti za cas a maximalnej rychlosti
    5. Domov

0. Konec
)" << std::endl;
  std::cout << "Input (mode):  ";
  std::cin >> mode;

  switch (mode) {
  case 1: {
    clearScreen();
    Vzorec Vodorovny_vrh;
    std::cout << R"(

## Vypocet vzdialenosti dopadu telesa na zem ##
    * Potrebne parametre: pociatocna rychlost (v0), pociatocna vyska (h0))"
         << std::endl;

    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Vodorovny_vrh._v0;

    if (std::cin.fail())
      throw "Invalid starting speed";

    std::cout << "Input (pociatocna vyska v m):  ";
    std::cin >> Vodorovny_vrh._h;

    if (std::cin.fail())
      throw "Invalid starting height";

    // ! d = v0 * sqr((2h/g))
    Vodorovny_vrh._s = Vodorovny_vrh._v0 * sqrt(2 * Vodorovny_vrh._h / Vodorovny_vrh._g);
    std::cout << "\n   ~ Z vysky " << Vodorovny_vrh._h << " m a pociatocnej rychlosti " << Vodorovny_vrh._v0 << " m/s, teleso padne vo vzdialenosti " << Vodorovny_vrh._s << " m." << std::endl;
    Sleep_fix(2);
    break;
  }
  case 2: {
    clearScreen();
    Vzorec Vodorovny_vrh;
    std::cout << R"(

## Vypocet casu dopadu telesa na zem ##
    * Potrebne parametre: pociatocna vyska (h0))"
         << std::endl;

    std::cout << "Input (pociatocna vyska v m):  ";
    std::cin >> Vodorovny_vrh._h;

    if(std::cin.fail())
      throw "Invalid starting height";

    // ! t = sqrt(2 * h / g)
    Vodorovny_vrh._t = sqrt(2 * Vodorovny_vrh._h / Vodorovny_vrh._g);
    std::cout << "\n   ~ Teleso padne na zem z vysky " << Vodorovny_vrh._h << " m (do jeho maximalnej vzdialenosti) po " << Vodorovny_vrh._t << " sekundach." << std::endl;
    Sleep_fix(2);
    break;

  }
  case 3: {
    clearScreen();
    Vzorec Vodorovny_vrh;
    std::cout << R"(

## Vypocet suradnic telesa za cas (v zakladnych jednotkach) ##
    * Potrebne parametre: pociatocna rychlost (v0), pociatocna vyska (h0), cas (t))"
         << std::endl;
    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Vodorovny_vrh._v0;
    if (std::cin.fail()) {
      throw "Invalid starting speed";
    }

    std::cout << "Input (pociatocna vyska v m):  ";
    std::cin >> Vodorovny_vrh._h;
    if (std::cin.fail()) {
      throw "Invalid starting height";
    }

    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Vodorovny_vrh._t;
    if (std::cin.fail()) {
      throw "Invalid time";
    }

    // ! x = v0 * t
    // ! y = h - 0.5 * g * pow(t, 2);
    Vodorovny_vrh._x = Vodorovny_vrh._v0 * Vodorovny_vrh._t;
    Vodorovny_vrh._y = Vodorovny_vrh._h - 0.5 * Vodorovny_vrh._g * pow(Vodorovny_vrh._t, 2);
    if (Vodorovny_vrh._y <= 0) {
      Vodorovny_vrh._x = Vodorovny_vrh._v0 * sqrt(2 * Vodorovny_vrh._h / Vodorovny_vrh._g);
    }

      std::cout << "\n   ~ Teleso sa bude nachadzat v suradniciach (" << Vodorovny_vrh._x << " m, " << (Vodorovny_vrh._y > 0 ? Vodorovny_vrh._y : 0) << " m)." << std::endl;
      if (Vodorovny_vrh._y <= 0) {
      std::cout << "   ~ Teleso dopadlo na zem "; // (-2.5 sekundy)

      float i = 0.0; // pocitadlo sekund
      if (Vodorovny_vrh._y < -1) {
        do { // vypis sekund do padnutia telesa na zem
          Vodorovny_vrh._y = Vodorovny_vrh._h - 0.5 * Vodorovny_vrh._g * pow(i, 2);
          if (Vodorovny_vrh._y <= 0) {
            std::cout << "(" << i << " sekundy, na h = 0)";
          }
          i += 0.01;
        } while (Vodorovny_vrh._y >= 0);
      }
      std::cout << std::endl;
    }
    Sleep_fix(2);
    break;

  }
  case 4: {
    clearScreen();
    Vzorec Vodorovny_vrh;
    std::cout << R"(

## Vypocet rychlosti za cas a maximalnej rychlosti ##
    * Potrebne parametre: pociatocna rychlost (v0), pociatocna vyska (h0), cas (t))"
         << std::endl;
    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Vodorovny_vrh._v0;
    if (std::cin.fail()) {
      throw "Invalid starting speed";
    }

    std::cout << "Input (pociatocna vyska v m):  ";
    std::cin >> Vodorovny_vrh._h;
    if (std::cin.fail()) {
      throw "Invalid starting height";
    }

    std::cout << "Input (cas v sekundach):  ";
    std::cin >> Vodorovny_vrh._t;
    if (std::cin.fail()) {
      throw "Invalid time";
    }

    // ! v = sqrt(pow(v0, 2) + pow(g*t, 2)); // v = sqrt(v0^2 + (g*t)^2)
    // ! max v = sqrt(pow(v0, 2) + 2*g*h); // max v = sqrt(v0^2 + 2*g*h)

    Vodorovny_vrh._v = sqrt(pow(Vodorovny_vrh._v0, 2) + pow(Vodorovny_vrh._g*Vodorovny_vrh._t, 2));
    

    if (Vodorovny_vrh._v > (sqrt(pow(Vodorovny_vrh._v0, 2) + 2*Vodorovny_vrh._g*Vodorovny_vrh._h)) ) {
      Vodorovny_vrh._v = sqrt(pow(Vodorovny_vrh._v0, 2) + 2*Vodorovny_vrh._g*Vodorovny_vrh._h);

      std::cout << "\n   ~ Teleso dosiahlo maximalnu rychlost " << Vodorovny_vrh._v << " m/s." << std::endl;
    } else {
      std::cout << "\n   ~ Teleso bude mat za cas " << Vodorovny_vrh._t << " sekund, rychlost " << (Vodorovny_vrh._v > 0 ? Vodorovny_vrh._v : 0) << " m/s." << std::endl;

      Vodorovny_vrh._v = sqrt(pow(Vodorovny_vrh._v0, 2) + 2*Vodorovny_vrh._g*Vodorovny_vrh._h);
      std::cout << "   ~ Teleso dosiahne maximalnu rychlost " << Vodorovny_vrh._v << " m/s." << std::endl;
    }

    Sleep_fix(2);
    break;
  }
  case 5: {
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

int sikmy_vrh(int mode) {
  // x = v0 * t * cos(a);
  // y = v0 * t * sin(a) - 0.5 * g * pow(t, 2);
  // v = v0 * cos(a);
  // time = (pow(v0, 2) * sin(a)) / g;
  // range = (pow(v0, 2) * sin(a) * cos(a)) / g;
  // altidude = (pow(v0, 2) * sin(a) * sin(a)) / (2 * g);

  clearScreen();
  std::cout << R"(

## Sikmy vrh (5) ##

    1. Vypocet dlzky letu v sekundach
    2. Vypocet vzdialenosti dopadu telesa na zem
    3. Vypocet maximalnej vysky telesa pod uhlom
    4. Domov

0. Konec
)" << std::endl;
  std::cout << "Input (mode):  ";
  std::cin >> mode;

  switch (mode) {
  case 1: {
    clearScreen();
    Vzorec Sikmy_vrh;
    std::cout << R"(

## Vypocet dlzky letu v sekundach ##
    * Potrebne parametre: pociatocna rychlost (v0), uhol (a))"
         << std::endl;
    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Sikmy_vrh._v0;
    if (std::cin.fail()) {
      throw "Invalid starting speed";
    }

    std::cout << "Input (uhol v stupnoch):  ";
    std::cin >> Sikmy_vrh._a;
    if (std::cin.fail()) {
      throw "Invalid angle";
    }

    Sikmy_vrh._a = Sikmy_vrh._a * M_PI / 180; // uhol v radianoch

    Sikmy_vrh._t = (pow(Sikmy_vrh._v0, 2) * sin(Sikmy_vrh._a)) / Sikmy_vrh._g; // dlzka letu v sekundach

    std::cout << "\n    ~ Teleso bude letiet " << Sikmy_vrh._t << " sekund." << std::endl;

    Sleep_fix(2);
    break;

  }
  case 2: {
    clearScreen();
    Vzorec Sikmy_vrh;
    std::cout << R"(

## Vypocet vzdialenosti dopadu telesa na zem ##
    * Potrebne parametre: pociatocna rychlost (v0), uhol (a))"
         << std::endl;

    std::cout << "Input (pociatocna rychlost v m/s):  ";
    std::cin >> Sikmy_vrh._v0;
    if (std::cin.fail()) {
      throw "Invalid starting speed";
    }

    std::cout << "Input (uhol v stupnoch):  ";
    std::cin >> Sikmy_vrh._a;
    if (std::cin.fail()) {
      throw "Invalid angle";
    }

    Sikmy_vrh._a = Sikmy_vrh._a * M_PI / 180; // uhol v radianoch

    // range = (pow(v0, 2) * sin(a) * cos(a)) / g;
    Sikmy_vrh._s = (pow(Sikmy_vrh._v0, 2) * sin(Sikmy_vrh._a) * cos(Sikmy_vrh._a)) / Sikmy_vrh._g;

    std::cout << "\n    ~ Teleso dopadne na zem v " << Sikmy_vrh._s << " metroch." << std::endl;

    Sleep_fix(2);
    break;

  }

  case 3: {
    clearScreen();
    Vzorec Sikmy_vrh;
    
    std::cout << R"(

## Vypocet maximalnej vysky telesa pod uhlom ##
    * Potrebne parametre: pociatocna rychlost (v0), uhol (a))"
         << std::endl;
    std::cout << "Input (pociatocna rychlost v m/s):  ";

    std::cin >> Sikmy_vrh._v0;
    if (std::cin.fail()) {
      throw "Invalid starting speed";
    }

    std::cout << "Input (uhol v stupnoch):  ";
    std::cin >> Sikmy_vrh._a;
    if (std::cin.fail()) {
      throw "Invalid angle";
    }

    Sikmy_vrh._a = Sikmy_vrh._a * M_PI / 180; // uhol v radianoch

    // altidude = (pow(v0, 2) * sin(a) * sin(a)) / (2 * g);
    Sikmy_vrh._h = (pow(Sikmy_vrh._v0, 2) * sin(Sikmy_vrh._a) * sin(Sikmy_vrh._a)) / (2 * Sikmy_vrh._g);

    std::cout << "\n    ~ Teleso dosiahne maximalnu vysku " << Sikmy_vrh._h << " metrov." << std::endl;


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
  }

  return mode;
}

void after_challenge(int mode) {
  if (!game_end && mode) {
    std::cout << R"(
Prajete si pokracovat vo vypocte? (Y/n))"
         << std::endl;

    char choice = '\0';

    std::cout << "Input (choice):  ";
    std::cin >> choice;

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
      std::cout << "\033[2J\033[1;]";
    }
#endif
}

void Sleep_fix(size_t time) {
  #ifdef WINDOWS
    Sleep(time*1000);

  #else
    sleep(time);

  #endif
} // * done

// Resources to learn C++:
// https://www.tutorialspoint.com/cplusplus/