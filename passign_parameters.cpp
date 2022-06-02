// program to pass parameters to a function and print them out
// can give help to users if specified "--help"
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {

  string arg1[argc - 1];

  if (argc > 1) {
    arg1[0] = argv[1]; // arg1 is the first argument passed to the program

    if (arg1[0] == "--help") {
      cout << "This program takes a string as an argument and prints it."
           << endl;
      cout << "Usage: " << argv[0] << " <string>" << endl;
      return 0;
    } else {
      for (int i = 0; i < argc; i++) {
        // argc is the number of arguments passed to the program
        cout << "argv[" << i << "] = " << argv[i] << endl;
        // argv is an array of strings that are the arguments passed
        // to the program (argv[0] is the name of the program)
      }
    }
  }

  // return is not needed here, but it is a good habit to have
  return 0;
}