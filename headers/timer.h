#include <chrono>
#include <iostream>

/* 
  * The chrono library provides a high-resolution clock.
  * The clock is a monotonic clock, which means that it never goes backwards.
  * The clock is a system clock, which means that it is affected by system

! HOW TO USE THE CHRONO LIBRARY:
  1. Get the current time from the clock.
  2. Do something
  3. Get the current time again.
  4. Calculate the difference between the two times.
  5. Print the difference.
*/

namespace timer {
struct Timer {
  std::chrono::_V2::system_clock::time_point start, endl;
  std::chrono::duration<float> duration;

  Timer() {
    // Get the current timepoint
    start = std::chrono::high_resolution_clock::now();
  }

  ~Timer() {
    // Get the current timepoint again for the end
    endl = std::chrono::high_resolution_clock::now();

    // Calculate the difference between the two timepoints
    duration = endl - start;

    // Calculate the duration in milliseconds
    float ms = duration.count() * 1000.0f;

    // Print the difference
    std::cout << "Timer took " << ms << " ms" << std::endl;
  }
};
} // namespace timer