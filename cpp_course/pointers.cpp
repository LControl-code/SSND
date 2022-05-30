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

  // * pointer variable
  // * to contain pointers
  int *Page = &age;      // SHIFT + ALT + I (select the end of selected lines)
  double *Pgpa = &gpa;   // SHIFT + ALT + I (select the end of selected lines)
  string *Pname = &name; // SHIFT + ALT + I (select the end of selected lines)

  return 0;
}