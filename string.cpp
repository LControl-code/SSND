#include <string>
#include <iostream>
using namespace std;

string uncensor(const string& infected, const string& discovered) {
    int n = 0;
    string done;
    for(long unsigned int i = 0; i < infected.length(); i++) {
      
      if (infected[i] == '*') {
        done += discovered[n];
        n++;
      } else {
        done += infected[i];
      }
      
    }
  
  
    return done;
}

int main () {

  string test = uncensor("*h*s *s v*ry *tr*ng*", "Tiiesae");
  cout << test << endl;
  return 0;
}