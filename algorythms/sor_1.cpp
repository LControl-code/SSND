#include <cstdlib>
#include <iostream>
#define MAX 100
using namespace std;

int main() {

  int arr[MAX], n;
  cout << "Enter a number n: ";
  cin >> n;

  // inputting numbers in array

  srand(time(NULL));

  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10;
  }

  

  // outputting the unsorted array
  cout << "\nUnsorted array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  // now we have an array full of unsorted items
  // TODO: create a sorting algorythm
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) { // j = i + 1 because we want to compare the next item
      if (arr[j] < arr[i]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  // outputting the sorted array
  cout << "\n\nSorted array: ";
  for (int i = 0; i < n; i++) { // printing the sorted array
    cout << arr[i] << " ";
  }


  return 0;
}