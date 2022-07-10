#include <cwchar>
#include <iostream>
#include <iterator>
//* there's no difference between a class and a struct
//! struct is by default public
//! class is by default private

struct Vec2 {
  float x, y;

  void Add(const Vec2 &other) {
    x += other.x;
    y += other.y;
  }

}; // don't use inheritance for structs, only for data

int main() {
}