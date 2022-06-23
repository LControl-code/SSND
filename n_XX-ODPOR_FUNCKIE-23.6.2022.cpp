#include <cstddef>
#include <iostream>

float odpor(float r1, float r2, char typ);

int main() {
  float r1, r2;
  char typ;
  std::cout << std::fixed;
  std::cout.precision(2);
  while (std::cin >> r1 >> r2 >> typ)
    std::cout << odpor(r1, r2, typ) << std::endl;

  std::cin.get();
  return 0;
}

float odpor(float r1, float r2, char typ) {
  switch (typ) {
  case 'P': {
    return 1 / r1 + 1 / r2;
    break;
  }
  case 'S': {
    return r1 + r2;
    break;
  }
  default: {
    return 0.;
  }
  }
}
