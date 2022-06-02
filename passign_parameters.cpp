#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  for(int i = 0; i < argc; ++i) {
    cout << "argv[" << i << "] = " << argv[i] << endl;
  }

 // return is not needed here, but it is a good habit to have
  return 0;
}