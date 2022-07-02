#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

struct Timer {
  std::chrono::_V2::system_clock::time_point start, endl;
  std::chrono::duration<float> duration;

  Timer() {
      start = std::chrono::high_resolution_clock::now();
  }

  ~Timer() {
      endl = std::chrono::high_resolution_clock::now();
      duration = endl - start;
      float ms = duration.count() * 1000.0f;
      std::cout << "Timer took " << ms << " ms" << std::endl;
      std::cout << "Result: " << std::endl;
  }
};

vector<int> twoSum(vector<int> &nums, int target) { //! O(n^2) -- slow
  Timer timer;
  vector<int> result;
  for (long unsigned int i = 0; i < nums.size(); i++) {
    for (long unsigned int j = i + 1; j < nums.size(); j++) {
      if (target - nums[i] == nums[j]) {
        result.push_back(i);
        result.push_back(j);
        return result;
      }
    }
  }
  return result;
}



// vector<int> twoSum(vector<int> &nums, int target) { //! O(n) -- fast
//   Timer timer;
//   vector<int> result;
//   unordered_map<int, int> hash;
//   for (long unsigned int i = 0; i < nums.size(); i++) {
//     hash[nums[i]] = i;
//   }
//   for (int i = 0; i < (int)nums.size(); i++) {
//     if (hash.find(target - nums[i]) != hash.end() && hash[target - nums[i]] != i) {
//       result.push_back(i);
//       result.push_back(hash[target - nums[i]]);
//       return result;
//     }
//   }
//   return result;
// }


int main() {
  long long target = 6;
  vector<int> nums = {3, -2, 2, -4, 8, 11, 1, -1, 6};
  vector<int> result = twoSum(nums, target);

  {
    int i = 0;
    cout << '[' << nums[result[i]] << ", " << nums[result[i + 1]] << ']' << endl;
  }

  return 0;
}