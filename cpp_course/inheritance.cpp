#include <iostream>
#include <string>
using namespace std;

// create a class called "Chef" with these void functions in public:
// - makeChicken
// - makeSalad
// - makeSpecialDish


class Chef {
public:
  void makeChicken() {
    cout << "The chef makes chicken" << endl;
  }
  void makeSalad() {
    cout << "The chef makes salad" << endl;
  }
  void makeSpecialDish() {
    cout << "The chef makes special dish" << endl;
  }
};

// create a class called "ItalianChef" that inherits from Chef
// and add a void function called "makePasta"

class ItalianChef : public Chef { // ItalianChef inherits from Chef
public:
  void makePasta() { // ItalianChef has its own makePasta function
    cout << "The chef makes pasta" << endl;
  }

  // can override the makeSpecialDish function from Chef and other functions
};

int main() {
  Chef chef;
  chef.makeChicken();
  chef.makeSalad();
  chef.makeSpecialDish();
  
  ItalianChef italianChef;
  italianChef.makeChicken();
  italianChef.makeSalad();
  italianChef.makeSpecialDish();
  italianChef.makePasta();
}
