#include <iostream>
using namespace std;

int main() {
  int n = 7;
  int k = 2;
  int a[] = {1, 7, 4, 3, 4, 8, 7};
  int counter[n];

  for (int i = 0; i < n; i++){
    counter[i] = 0;
  }

  int Cot = 0;
  for (int i = 0; i < n; i++) {

    // prejst vsetko, ked najde cislo tak pridat jeho count do array na jeho
    // miesto, ak sa ten count bude rovnat k tak skonci

    int j = 0;
    while (a[i] != a[j])
      j++;
    if (j == Cot) {

      Cot++;
      counter[i]++;

      if (counter[i] == k) {
        cout << a[i];
        return 0;
      }
    } else {
      counter[j]++;
      if (counter[j] == k) {
      cout << a[j];
      return 0;
    }
    }
  }
}