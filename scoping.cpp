#include <iostream>
using namespace std;

int main() {

        {
                int i = 0;
                i++;
                cout << "' i ' is in scope: " << i << endl;
        } // here, every variable declared is gone. The compiler get's rid of em, because they are scoped to the brackets.

        cout << "Out of scope, can't use variable ' i ' no more. ";
        return 0;
}