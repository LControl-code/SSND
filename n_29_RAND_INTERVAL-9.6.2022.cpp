#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

int main() {

  auto dummy = "./TXT/TXT-cisla_1.txt";
  fstream file_W(dummy, ios::out);
  if (!file_W.is_open()) {
    return 1;
  }

  srand(time(NULL));

  int n, min, max;
  cin >> n >> min >> max;

  for (int i = 0; i < n; i++) {
    file_W << min + rand() % (max - min + 1) << endl;
  }

  file_W.close();
  return 0;
}
