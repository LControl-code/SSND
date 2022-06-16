#include <iostream>
#include <any>
using namespace std;

any get_value(any a);

int main() {
  string n;
  cin >> n;
  any a = n;
  
  cout << any_cast<string>(a) << endl;

  any a = "Hello";
  cout << get_value(a) << endl;

}

// create a function that takes any type and returns the value with the corresponding type
// if the type is not supported, return void

any get_value(any a) {
  if (a.type() == typeid(int)) {
    return any_cast<int>(a);
  } else if (a.type() == typeid(string)) {
    return any_cast<string>(a);
  } else if (a.type() == typeid(double)) {
    return any_cast<double>(a);
  } else {
    return void();
  }
}