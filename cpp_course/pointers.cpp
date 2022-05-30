#include <iostream>
using namespace std;

int main() {

  int age = 19;
  double gpa = 2.7;
  string name = "Mike";

  cout << "Age adress: " << &age << endl;
  // * memory adress, which creates a container for the
  // * variable age with value 19
  cout << "GPA adress: " << &gpa << endl;
  cout << "Name adress: " << &name << endl;

  return 0;
}