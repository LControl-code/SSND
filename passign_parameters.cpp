#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  for(int i = 0; i < argc; ++i) { // argc is the number of arguments passed to the program
    cout << "argv[" << i << "] = " << argv[i] << endl; // argv is an array of strings that are the arguments passed to the program (argv[0] is the name of the program)
  }

 // return is not needed here, but it is a good habit to have
  return 0;
}