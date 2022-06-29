#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void Increment(int& value) {
  value++;
} // by reference

int main() {
  int a = 5;
  int& ref = a; // ref is a reference to a
  // ref = 2;

  // you can only reference only one variable at a time
  LOG(a);
  Increment(ref);
  LOG(a);

}