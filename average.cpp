#include <iostream>
using namespace std;

int main() {

  double sum_num = 0, sum = 0;
  int count = 0;

  while (cin >> sum_num && sum_num != 0) { // easy and effective way of getting the desired numbers
    sum += sum_num;
    count++;
  }

  cout << sum / count; // The final result, simple math
  return 0;
}
// we went from the formula total_sum devided by the number of items, gives us
// the average.