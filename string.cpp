#include <iostream>
#include <string>
using namespace std;

void uncensor(string &infected, const string discovered) {
  int n = 0;
  for (long unsigned int i = 0; i < infected.length(); i++) {
    if (infected[i] == '*') {
      infected[i] = discovered[n];
      n++;
    }
  }
}

int main() {
  
  string name = "A*dr*a*";
  uncensor(name, "nes");
  cout << name << endl;
  
  int x = 50;
  int &Y = x;
  Y = 100;
  cout << x << endl;

  int y = 50;
  int *Z = &y; // Z is a pointer to y (the address of y)
  *Z = 100; // y is now 100 - * is the dereference operator
  cout << y << endl;


  return 0;
}

