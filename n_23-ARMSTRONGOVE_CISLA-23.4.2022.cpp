#include <iostream>

int main() {
  // abc = a^3 + b^3 + c^3
  // int num;
  // std::cin >> num;
  for (int incrementation_num = 100; incrementation_num <= 999;
       incrementation_num++) {
    // std::vector<int> reversed_array(3);
    int temp_num = incrementation_num, ending_num = 0;
    for (int arr_num_inc = 2; arr_num_inc >= 0; arr_num_inc--) {
      // reversed_array[arr_num_inc] =  % 10;
      int plus_num = temp_num % 10;
      ending_num += plus_num * plus_num * plus_num;
      temp_num /= 10; // temp_num = temp_num / 10
    }

    if (ending_num == incrementation_num) {
      std::cout << incrementation_num << " ";
    }
  }

  std::cout << std::endl;
  return 0;
}
